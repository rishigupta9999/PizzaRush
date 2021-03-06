//
//  Camera.h
//  Neon21
//
//  Copyright Neon Games 2010. All rights reserved.
//

@class DebugCamera;

@interface Camera : NSObject
{
    @public
        Vector3 mPosition;
		Vector3 mLookAt;
		
        float   mNear;
        float   mFar;
    
        Matrix44     mPostProjectionMatrix;
    
    @protected
        DebugCamera* mDebugCamera;
}

-(Camera*)Init;

-(void)GetPosition:(Vector3*)outPosition;
-(void)GetLookAt:(Vector3*)outLookAt;

-(void)GetViewMatrix:(Matrix44*)outViewMatrix;
-(void)GetProjectionMatrix:(Matrix44*)outProjMatrix;
-(void)GetPostProjectionMatrix:(Matrix44*)outPostProjMatrix;

-(DebugCamera*)GetDebugCameraAttached;
-(void)SetDebugCameraAttached:(DebugCamera*)inDebugCamera;

@end