#include "iGPUTalks.hpp"

OSDefineMetaClassAndStructors(iGPUTalks, IOService)

bool iGPUTalks::init(OSDictionary *dictionary) {
    if (!IOService::init(dictionary)) return false;
    IOLog("iGPUTalks: Initializing v29.41.10\n");
    return true;
}

IOService *iGPUTalks::probe(IOService *provider, SInt32 *score) {
    return IOService::probe(provider, score);
}

bool iGPUTalks::start(IOService *provider) {
    if (!IOService::start(provider)) return false;

    IOPCIDevice *pci = OSDynamicCast(IOPCIDevice, provider);
    if (!pci) {
        IOLog("iGPUTalks: provider is not a PCI device\n");
        return false;
    }

    IOLog("iGPUTalks: attached to PCI device vendor=0x%04x device=0x%04x rev=0x%02x\n",
          pci->configRead16(kIOPCIConfigVendorID),
          pci->configRead16(kIOPCIConfigDeviceID),
          pci->configRead8(kIOPCIConfigRevisionID));

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
