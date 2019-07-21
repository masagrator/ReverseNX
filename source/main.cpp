#include <switch_min.h>

#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <cstdlib>
#include <dirent.h>
#include <sys/iosupport.h>
#include <sys/reent.h>
#include <switch_min/kernel/ipc.h>

#include "useful/useful.h"

#include "saltysd/saltysd_core.h"
#include "saltysd/saltysd_ipc.h"
#include "saltysd/saltysd_dynamic.h"

#include "saltysd/saltysd_helper.h"

extern "C" {
	extern u32 __start__;

	static char g_heap[0x8000];

	void __libnx_init(void* ctx, Handle main_thread, void* saved_lr);
	void __attribute__((weak)) NORETURN __libnx_exit(int rc);
	void __nx_exit(int, void*);
	void __libc_fini_array(void);
	void __libc_init_array(void);
}

u32 __nx_applet_type = AppletType_None;

Handle orig_main_thread;
void* orig_ctx;
void* orig_saved_lr;
uint8_t* set = 0;

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

// GetPerformanceMode and GetOperationMode needs the same return value
// return 0 - handheld mode
// return 1 - docked mode

uint32_t GetPerformanceMode() {
	return set;
}

uint8_t GetOperationMode() {
	return set;
}

const char* CheckTitleID() {
    char* titleid = malloc(0x20);
    uint64_t titid = 0;
    svcGetInfo(&titid, 18, CUR_PROCESS_HANDLE, 0);	
    snprintf(titleid, 0x20, "%016" PRIx64, titid);
	return titleid;
}

int main(int argc, char *argv[]) {
	SaltySD_printf("SaltySD ReverseNX: alive\n");
	char* tid_check = CheckTitleID();
	char* flag_path = "sdmc:/SaltySD/plugins/";
	char* handheld_flag = "/ReverseNX/handheld.flag";
	char* docked_flag = "/ReverseNX/docked.flag";
	char handheld_flag_path[128];
	char docked_flag_path[64];
	snprintf(handheld_flag_path, sizeof handheld_flag_path, "%s%s%s", flag_path, tid_check, handheld_flag);
	snprintf(docked_flag_path, sizeof docked_flag_path, "%s%s%s", flag_path, tid_check, docked_flag);
	
	FILE* path_titleid_handheld = SaltySDCore_fopen(handheld_flag_path, "r");
	FILE* path_titleid_docked = SaltySDCore_fopen(docked_flag_path, "r");
	FILE* path_titleid_flag = SaltySDCore_fopen("sdmc:/SaltySD/flags/ReverseNX/titleid.flag", "r");
	FILE* path_global_handheld = SaltySDCore_fopen("sdmc:/SaltySD/plugins/ReverseNX/handheld.flag", "r");
	FILE* path_global_docked = SaltySDCore_fopen("sdmc:/SaltySD/plugins/ReverseNX/docked.flag", "r");
	
	// Get anchor for imports
	// do not remove if you plan on using IMPORT
	ANCHOR_ABS = SaltySDCore_getCodeStart();
	
	// Add function replacements here
	if (!path_titleid_flag) goto global;
	else goto titleid;

titleid:
	if(path_titleid_handheld) {
		if(path_titleid_docked) {
			SaltySD_printf("Both titleid flags detected. Applying default graphics settings.\n");
		}
		else if(!path_titleid_docked) {
			SaltySD_printf("Handheld titleid flag detected. Applying handheld graphics settings.\n");	
			
			SaltySDCore_ReplaceImport("_ZN2nn2oe18GetPerformanceModeEv", &GetPerformanceMode);
			SaltySDCore_ReplaceImport("_ZN2nn2oe16GetOperationModeEv", &GetOperationMode);
		}
	goto close;
	}
	else if(!path_titleid_handheld) {
		if(!path_titleid_docked) {
		SaltySD_printf("No titleid flag detected. Applying default graphics settings.\n");
		}
		else if(path_titleid_docked) {
			SaltySD_printf("Docked titleid flag detected. Applying docked graphics settings.\n");	
			
			set = 1;
			SaltySDCore_ReplaceImport("_ZN2nn2oe18GetPerformanceModeEv", &GetPerformanceMode);
			SaltySDCore_ReplaceImport("_ZN2nn2oe16GetOperationModeEv", &GetOperationMode);
		}
	goto close;
	}

global:
	if(path_global_handheld) {
		if(path_global_docked) {
			SaltySD_printf("Both global flags detected. Applying default graphics settings.\n");
		}
		else if(!path_global_docked) {
			SaltySD_printf("Handheld global flag detected. Applying handheld graphics settings.\n");	

			SaltySDCore_ReplaceImport("_ZN2nn2oe18GetPerformanceModeEv", &GetPerformanceMode);
			SaltySDCore_ReplaceImport("_ZN2nn2oe16GetOperationModeEv", &GetOperationMode);
		}
	goto close;
	}
	else if(!path_global_handheld) {
		if(!path_global_docked) {
		SaltySD_printf("No docked or handheld global flag detected. Applying default graphics settings.\n");
		}
		else if(path_global_docked) {
			SaltySD_printf("Docked global flag detected. Applying docked graphics settings.\n");	
			
			set = 1;
			SaltySDCore_ReplaceImport("_ZN2nn2oe18GetPerformanceModeEv", &GetPerformanceMode);
			SaltySDCore_ReplaceImport("_ZN2nn2oe16GetOperationModeEv", &GetOperationMode);
		}
	goto close;
	}
	

close:
	SaltySD_printf("Setting GetOperationMode: %d\n", set);
	SaltySD_printf("Setting GetPerformanceMode: %d\n", set);	
	SaltySDCore_fclose(path_titleid_handheld);
	SaltySDCore_fclose(path_titleid_docked);
	SaltySDCore_fclose(path_global_handheld);
	SaltySDCore_fclose(path_global_docked);
	SaltySDCore_fclose(path_titleid_flag);
	SaltySD_printf("SaltySD ReverseNX: finished\n");
	__libnx_exit(0);
}
