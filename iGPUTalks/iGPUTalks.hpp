#ifndef iGPUTalks_hpp
#define iGPUTalks_hpp

#include <IOKit/IOService.h>

class iGPUTalks : public IOService {
    OSDeclareDefaultStructors(iGPUTalks)
public:
    virtual bool init(OSDictionary *dictionary = nullptr) override;
    virtual void free(void) override;
    virtual IOService *probe(IOService *provider, SInt32 *score) override;
    virtual bool start(IOService *provider) override;
    virtual void stop(IOService *provider) override;
};

#endif
EOF