//
//  ESMacros.h
//  ESMacros
//
//  Created by codeLocker on 2017/7/25.
//  Copyright © 2017年 codeLocker. All rights reserved.
//

#ifndef ESMacros_h
#define ESMacros_h

// gcd sync
#define es_dispatch_main_sync_safe(block)\
if (block == nil) {\
return;\
}\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_sync(dispatch_get_main_queue(), block);\
}

// gcd async
#define es_dispatch_main_async_safe(block)\
if (block == nil) {\
return;\
}\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}

// safe block
#define es_block_safe(block)\
if (block != nil) {\
block();\
} else {\
}

//self
#define es_weakSelf(weakSelf)    __weak __typeof(&*self)weakSelf = self;
#define es_strongSelf(strongSelf) __strong __typeof(&*self)strongSelf = self;

//log
#ifdef DEBUG
#  define ESLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#  define ESLog(...)
#endif

#endif /* ESMacros_h */
