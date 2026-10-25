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
