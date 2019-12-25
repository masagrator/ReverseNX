#include <switch_min.h>

#include <inttypes.h>
#include <cstdlib>
#include <sys/iosupport.h>

#include "saltysd/SaltySD_core.h"
#include "saltysd/SaltySD_ipc.h"
#include "saltysd/SaltySD_dynamic.h"

#include "saltysd/SaltySD_helper.h"

extern "C" {
	extern u32 __start__;

	static char g_heap[0x8000];

	void __libnx_init(void* ctx, Handle main_thread, void* saved_lr);
	void __attribute__((weak)) NORETURN __libnx_exit(int rc);
	void __nx_exit(int, void*);
	void __libc_fini_array(void);
	void __libc_init_array(void);
	extern u32 _ZN2nn2oe18GetPerformanceModeEv() LINKABLE;
	extern u8 _ZN2nn2oe16GetOperationModeEv() LINKABLE;
}

u32 __nx_applet_type = AppletType_None;

Handle orig_main_thread;
void* orig_ctx;
void* orig_saved_lr;
uint8_t set = 0;
uint8_t def = 1;
char* ver = "0.3.4";

void __libnx_init(void* ctx, Handle main_thread, void* saved_lr) {
	extern char* fake_heap_start;
	extern char* fake_heap_end;

	fake_heap_start = &g_heap[0];
	fake_heap_end   = &g_heap[sizeof g_heap];
	
	orig_ctx = ctx;
	orig_main_thread = main_thread;
	orig_saved_lr = saved_lr;
	
	// Call constructors.
	//void __libc_init_array(void);
	__libc_init_array();
}

void __attribute__((weak)) NORETURN __libnx_exit(int rc) {
	// Call destructors.
	//void __libc_fini_array(void);
	__libc_fini_array();

	SaltySD_printf("SaltySD Plugin: jumping to %p\n", orig_saved_lr);

	__nx_exit(0, orig_saved_lr);
	while (true);
}

const char* CheckTitleID() {
    char* titleid = malloc(0x20);
    uint64_t titid = 0;
    svcGetInfo(&titid, 18, CUR_PROCESS_HANDLE, 0);	
    snprintf(titleid, 0x20, "%016" PRIx64, titid);
	return titleid;
}

void CheckFlag() {
	
	FILE* path_createdock_flag = SaltySDCore_fopen("sdmc:/SaltySD/flags/ReverseNX/createdock.flag", "r");
	FILE* path_createhandheld_flag = SaltySDCore_fopen("sdmc:/SaltySD/flags/ReverseNX/createhandheld.flag", "r");
	FILE* path_createremove_flag = SaltySDCore_fopen("sdmc:/SaltySD/flags/ReverseNX/createremove.flag", "r");

	char* tid_check = CheckTitleID();
	char* flag_path = "sdmc:/SaltySD/plugins/";
	char* handheld_flag = "/ReverseNX/handheld.flag";
	char* docked_flag = "/ReverseNX/docked.flag";
	char handheld_flag_path[128];
	char docked_flag_path[64];
	char tid_path[64];
	char tid_path_reversenx[128];
	char* ReverseNX = "/ReverseNX";
	FILE* path_titleid_flag = SaltySDCore_fopen("sdmc:/SaltySD/flags/ReverseNX/titleid.flag", "r");
	FILE* path_global_handheld = SaltySDCore_fopen("sdmc:/SaltySD/plugins/ReverseNX/handheld.flag", "r");
	FILE* path_global_docked = SaltySDCore_fopen("sdmc:/SaltySD/plugins/ReverseNX/docked.flag", "r");
	snprintf(handheld_flag_path, sizeof handheld_flag_path, "%s%s%s", flag_path, tid_check, handheld_flag);
	snprintf(docked_flag_path, sizeof docked_flag_path, "%s%s%s", flag_path, tid_check, docked_flag);

	if ((path_createdock_flag || path_createhandheld_flag || path_createremove_flag) && path_titleid_flag) {
		SaltySDCore_remove(handheld_flag_path);
		SaltySDCore_remove(docked_flag_path);
		SaltySDCore_fclose(path_createdock_flag);
		SaltySDCore_fclose(path_createhandheld_flag);
		SaltySDCore_fclose(path_createremove_flag);
		snprintf(tid_path, sizeof tid_path, "%s%s", flag_path, tid_check);
		snprintf(tid_path_reversenx, sizeof tid_path_reversenx, "%s%s", tid_path, ReverseNX);
		if (!path_createdock_flag || !path_createhandheld_flag) {
			mkdir(tid_path, ACCESSPERMS);
			mkdir(tid_path_reversenx, ACCESSPERMS);
		}
		if (path_createdock_flag) {
			FILE* createdock = SaltySDCore_fopen(docked_flag_path, "w");
			SaltySDCore_remove(handheld_flag_path);
			SaltySDCore_fclose(createdock);
		}
		else if (path_createhandheld_flag) {
			FILE* createhandheld = SaltySDCore_fopen(handheld_flag_path, "w");
			SaltySDCore_remove(docked_flag_path);
			SaltySDCore_fclose(createhandheld);
		}
		else if (path_createremove_flag) {
			SaltySDCore_remove(docked_flag_path);
			SaltySDCore_remove(handheld_flag_path);
		}
		SaltySDCore_remove("sdmc:/SaltySD/flags/ReverseNX/createdock.flag");
		SaltySDCore_remove("sdmc:/SaltySD/flags/ReverseNX/createhandheld.flag");
		SaltySDCore_remove("sdmc:/SaltySD/flags/ReverseNX/createremove.flag");
	}
	else {
		SaltySDCore_fclose(path_createdock_flag);
		SaltySDCore_fclose(path_createhandheld_flag);
		SaltySDCore_fclose(path_createremove_flag);
		SaltySDCore_remove("sdmc:/SaltySD/flags/ReverseNX/createdock.flag");
		SaltySDCore_remove("sdmc:/SaltySD/flags/ReverseNX/createhandheld.flag");
		SaltySDCore_remove("sdmc:/SaltySD/flags/ReverseNX/createremove.flag");
	}
	if (!path_titleid_flag) goto global;
	else {
		SaltySDCore_fclose(path_titleid_flag);
		goto titleid;
	}

global:
	if(path_global_handheld) {
		if(path_global_docked) {
			SaltySD_printf("Both global flags detected. Applying default graphics settings.\n");
			def = 1;
		}
		else if(!path_global_docked) {
			SaltySD_printf("Handheld global flag detected. Applying handheld graphics settings.\n");	
			set = 0;
			def = 0;
		}
	}
	else if(!path_global_handheld) {
		if(!path_global_docked) {
			SaltySD_printf("No docked or handheld global flag detected. Applying default graphics settings.\n");
			def = 1;
		}
		else if(path_global_docked) {
			SaltySD_printf("Docked global flag detected. Applying docked graphics settings.\n");	
			set = 1;
			def = 0;
		}
	}
	SaltySDCore_fclose(path_global_handheld);
	SaltySDCore_fclose(path_global_docked);
	return;

titleid:
	FILE* path_titleid_handheld = SaltySDCore_fopen(handheld_flag_path, "r");
	FILE* path_titleid_docked = SaltySDCore_fopen(docked_flag_path, "r");
	if(path_titleid_handheld) {
		if(path_titleid_docked) {
			SaltySD_printf("Both titleid flags detected. Applying default graphics settings.\n");
			def = 1;
		}
		else if(!path_titleid_docked) {
			SaltySD_printf("Handheld titleid flag detected. Applying handheld graphics settings.\n");
			set = 0;
			def = 0;
		}
	}
	else if(!path_titleid_handheld) {
		if(!path_titleid_docked) {
			SaltySD_printf("No titleid flag detected. Applying default graphics settings.\n");
			def = 1;
		}
		else if(path_titleid_docked) {
			SaltySD_printf("Docked titleid flag detected. Applying docked graphics settings.\n");	
			set = 1;
			def = 0;
		}
	}
	SaltySDCore_fclose(path_titleid_handheld);
	SaltySDCore_fclose(path_titleid_docked);
	return;
}

// GetPerformanceMode and GetOperationMode needs the same return value
// return 0 - handheld mode
// return 1 - docked mode

uint32_t GetPerformanceMode() {
	CheckFlag();
	if (def == 1) {
		uint32_t nnperformance = _ZN2nn2oe18GetPerformanceModeEv();
		return nnperformance;
	}
	else return set;
}

uint8_t GetOperationMode() {
	CheckFlag();
	if (def == 1) {
		uint8_t nnoperation = _ZN2nn2oe16GetOperationModeEv();
		return nnoperation;
	}
	else return set;
}

int main(int argc, char *argv[]) {
	SaltySD_printf("SaltySD ReverseNX %s: alive\n", ver);

	ANCHOR_ABS = SaltySDCore_getCodeStart();
	CheckFlag();

	SaltySDCore_ReplaceImport("_ZN2nn2oe18GetPerformanceModeEv", &GetPerformanceMode);
	SaltySDCore_ReplaceImport("_ZN2nn2oe16GetOperationModeEv", &GetOperationMode);
	SaltySD_printf("SaltySD ReverseNX %s: injection finished\n", ver);
}