//
//  NeonMetrics.h
//
//  Copyright Neon Games 2013. All rights reserved.
//

#import "MessageChannel.h"

typedef enum
{
    NEON_METRIC_TYPE_KISS,
    NEON_METRIC_TYPE_FLURRY,
    NEON_METRIC_TYPE_BOTH
} NeonMetricType;

typedef enum
{
    LOCALYTICS_SESSION_OPEN,
    LOCALYTICS_SESSION_CLOSED
} LocalyticsState;

@interface NeonMetrics : NSObject<MessageChannelListener>
{
    NSString*       mVersion;
    LocalyticsState mLocalyticsState;
}

-(NeonMetrics*)Init;
-(void)dealloc;

+(void)CreateInstance;
+(void)DestroyInstance;

+(NeonMetrics*)GetInstance;

-(NSString*)GetVersion;

-(void)ProcessMessage:(Message*)inMsg;

-(void)logEvent:(NSString*)inEvent withParameters:(NSDictionary*)inParameters;
-(void)logEvent:(NSString*)inEvent withParameters:(NSDictionary*)inParameters type:(NeonMetricType)inType;


-(void)logEvent:(NSString*)inEvent withParameters:(NSDictionary*)inParameters timed:(BOOL)inTimed;
-(void)endTimedEvent:(NSString*)inEvent withParameters:(NSDictionary*)inParameters;

@end