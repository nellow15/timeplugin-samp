#include <cstddef>
#include "plugin.h"
#include <ctime>

void *pAMXFunctions;

// logprintf handler
typedef void (*logprintf_t)(const char *format, ...);
logprintf_t logprintf;

// Native: GetServerTime()
cell AMX_NATIVE_CALL GetServerTime(AMX *amx, cell *params)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;
    int second = ltm->tm_sec;

    return (hour << 16) | (minute << 8) | second;
}

// Register native
AMX_NATIVE_INFO PluginNatives[] =
{
    {"GetServerTime", GetServerTime},
    {0, 0}
};

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

    logprintf("[TimePlugin] Loaded!");
    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
    logprintf("[TimePlugin] Unloaded!");
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
    return amx_Register(amx, PluginNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
    return AMX_ERR_NONE;
}