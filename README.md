# iGPUTalks

**iGPUTalks** is an experimental, open-source macOS Kernel Extension (kext) designed to interface modern AMD Radeon 660M and 700M series mobile integrated graphics (RDNA2/RDNA3 architecture) with the native macOS kernel and graphic stacks. 

> [!WARNING]
> This project operates at the ring-0 kernel level. Misconfigurations or unhandled memory panics will cause severe Kernel Panics. Use exclusively on experimental test rigs.

## Current Target Version
- **Kext Version:** 29.41.10 (Build: 26Y29.41)
- **Minimum macOS Target:** macOS 12.0 (Monterey) and above

## Features & Goals
- Patch kernel framebuffers for RDNA2 (Radeon 660M) and RDNA3 (700M Series) APUs.
- Enforce custom SMBIOS requirements for mobile AMD chips.
- Bind memory mappings directly to Apple's native AMDRadeonX6000 stack components.

## Boot Arguments
- `-igputalksdbg` Enables debug logging to system dmesg console.
- `-igputalksoff` Disables driver initialization hooks entirely.

## Building
This repository utilizes automated compilation via GitHub Actions. If building locally, ensure Xcode 15+ and the Command Line Tools are installed:
```bash
xcodebuild -project iGPUTalks.xcodeproj -scheme iGPUTalks -configuration Release
```

## License
Distributed under the BSD 3-Clause License.
