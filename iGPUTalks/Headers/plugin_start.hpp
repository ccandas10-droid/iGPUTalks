#ifndef lilu_plugin_start_hpp
#define lilu_plugin_start_hpp

#include <IOKit/IOService.h>

class LiluPlugin {
public:
    static bool init();
    static void forcedMaxVersion();
};

#endif
