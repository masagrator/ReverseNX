#include <switch_min.h>

#include <string.h>
#include <stdio.h>
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

uint32_t GetPerformanceMode1() {
  return 1;
}

uint8_t GetOperationMode1() {
  return 1;
}

uint32_t GetPerformanceMode0() {
  return 0;
}

uint8_t GetOperationMode0() {
  return 0;
}

int main(int argc, char *argv[]) {
	SaltySD_printf("SaltySD ReverseNX: alive\n");
	
	FILE* flag_handheld = SaltySDCore_fopen("sdmc:/SaltySD/plugins/ReverseNX/handheld.flag", "r+b");
	FILE* flag_docked = SaltySDCore_fopen("sdmc:/SaltySD/plugins/ReverseNX/docked.flag", "r+b");
	
	// Get anchor for imports
	// do not remove if you plan on using IMPORT
	ANCHOR_ABS = SaltySDCore_getCodeStart();
	
	// Add function replacements here
	if(flag_handheld) {
		if(flag_docked) {
			SaltySD_printf("Both flags detected. Applying default graphics settings.\n");
			SaltySDCore_fclose(flag_handheld);
			SaltySDCore_fclose(flag_docked);
		}
		else if(!flag_docked) {
			SaltySD_printf("Handheld flag detected. Applying handheld graphics settings.\n");	
			
			SaltySD_printf("Setting GetPerformanceMode: 0\n");
			SaltySDCore_ReplaceImport("_ZN2nn2oe18GetPerformanceModeEv", &GetPerformanceMode0);
			
			SaltySD_printf("Setting GetOperationMode: 0\n");
			SaltySDCore_ReplaceImport("_ZN2nn2oe16GetOperationModeEv", &GetOperationMode0);
			
			SaltySD_printf("SaltySD ReverseNX: finished\n");
			SaltySDCore_fclose(flag_handheld);
		}
	}

	else if(!flag_handheld) {
		if(!flag_docked) {
		SaltySD_printf("No flag detected. Applying default graphics settings.\n");
		}
		else if(flag_docked) {
			SaltySD_printf("Docked flag detected. Applying docked graphics settings.\n");	
			
			SaltySD_printf("Setting GetPerformanceMode: 1\n");
			SaltySDCore_ReplaceImport("_ZN2nn2oe18GetPerformanceModeEv", &GetPerformanceMode1);
			
			SaltySD_printf("Setting GetOperationMode: 1\n");
			SaltySDCore_ReplaceImport("_ZN2nn2oe16GetOperationModeEv", &GetOperationMode1);
			
			SaltySD_printf("SaltySD ReverseNX: finished\n");
			SaltySDCore_fclose(flag_docked);
		}
		
	}

	__libnx_exit(0);
}
