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
#define ES_Disparch_Main_Sync_Safe(block)\
if (block == nil) {\
return;\
}\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_sync(dispatch_get_main_queue(), block);\
}

// gcd async
#define ES_Disparch_Main_Async_Safe(block)\
if (block == nil) {\
return;\
}\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}

// safe block
#define ES_Block_Safe(block)\
if (block != nil) {\
block();\
} else {\
}

//self
#define ES_WeakSelf(weakSelf)    __weak __typeof(&*self)weakSelf = self;
#define ES_StrongSelf(strongSelf) __strong __typeof(&*self)strongSelf = self;

//log
#ifdef DEBUG
#  define ESLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#  define ESLog(...)
#endif

//time
#define ES_Perform_Time_Start NSDate *es_startDate = [NSDate date];
#define ES_Perform_Time_End \
NSTimeInterval time = [[NSDate date] timeIntervalSinceDate:es_startDate];\
ESLog(@"%fms",time*1000);\

#endif /* ESMacros_h */
