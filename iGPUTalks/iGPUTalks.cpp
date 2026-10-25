#include "iGPUTalks.hpp"
#include <Headers/plugin_start.hpp>
#include <Headers/kern_api.hpp>

OSDefineMetaClassAndStructors(iGPUTalks, IOService)

bool iGPUTalks::init(OSDictionary *dictionary) {
    if (!IOService::init(dictionary)) return false;
    IOLog("iGPUTalks: Initializing patch engine v29.41.10...\n");
    return true;
}

IOService* iGPUTalks::probe(IOService *provider, SInt32 *score) {
    return IOService::probe(provider, score);
}

bool iGPUTalks::start(IOService *provider) {
    if (!IOService::start(provider)) return false;
    IOLog("iGPUTalks: Driver successfully started and waiting for device match.\n");
    registerService();
    return true;
}

void iGPUTalks::stop(IOService *provider) {
    IOLog("iGPUTalks: Driver stopping.\n");
    IOService::stop(provider);
}

void iGPUTalks::free(void) {
    IOLog("iGPUTalks: Context freed.\n");
    IOService::free();
}
EOF