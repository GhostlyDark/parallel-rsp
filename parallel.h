#pragma once

#include "m64p_plugin.h"
#include "m64p_common.h"
#include "m64p_config.h"
#include "m64p_vidext.h"

#ifdef _WIN32
#define DLSYM(a, b) GetProcAddress(a, b)
#else
#include <dlfcn.h>
#define DLSYM(a, b) dlsym(a, b)
#endif

extern m64p_dynlib_handle CoreLibHandle;
extern m64p_handle configRspParallel;
extern void (*render_callback)(int);
extern void (*debug_callback)(void *, int, const char *);
extern void *debug_call_context;

extern ptr_ConfigOpenSection ConfigOpenSection;
extern ptr_ConfigSaveSection ConfigSaveSection;
extern ptr_ConfigSetDefaultInt ConfigSetDefaultInt;
extern ptr_ConfigSetDefaultBool ConfigSetDefaultBool;
extern ptr_ConfigGetParamInt ConfigGetParamInt;
extern ptr_ConfigGetParamBool ConfigGetParamBool;
extern ptr_ConfigSetParameter ConfigSetParameter;


#define KEY_HLE_GFX "CFG_HLE_GFX"
#define KEY_HLE_AUD "CFG_HLE_AUD"
