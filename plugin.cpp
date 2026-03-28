#include "plugin.h"

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
    logprintf("Plugin loaded!");
    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
    logprintf("Plugin unloaded!");
}