//
//  DDCustomOpenGLView.h
//  DDCustomOpenGL
//
//  Created by Dave Dribin on 10/11/06.
//  Copyright 2006 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>

@interface DDCustomOpenGLView : NSView
{
    NSOpenGLContext * mOpenGLContext;
    NSOpenGLPixelFormat * mPixelFormat;
    
    NSOpenGLContext * mFullScreenOpenGLContext;
    NSOpenGLPixelFormat * mFullScreenPixelFormat;

    BOOL mFullScreen;
    int mFullScreenWidth;
    int mFullScreenHeight;
    NSRect mFullScreenRect;
    float mFullScreenMouseOffset;

    NSRecursiveLock * mDisplayLock;
    CVDisplayLinkRef mDisplayLink;
    NSTimer * mAnimationTimer;
    
    BOOL mDoubleBuffered;
}

+ (NSOpenGLPixelFormat*)defaultPixelFormat;

- (id) initWithFrame: (NSRect) frame
         pixelFormat: (NSOpenGLPixelFormat *) pixelFormat;

- (NSOpenGLContext *) openGLContext;
- (void) setOpenGLContext: (NSOpenGLContext *) anOpenGLContext;

- (NSOpenGLPixelFormat *) pixelFormat;
- (void) setPixelFormat: (NSOpenGLPixelFormat *) aPixelFormat;

- (void) prepareOpenGL: (NSOpenGLContext *) context;


- (NSOpenGLContext *) currentOpenGLContext;
- (NSOpenGLPixelFormat *) currentPixelFormat;
- (NSRect) currentBounds;

- (void) update;

- (void) lockOpenGLLock;
- (void) unlockOpenGLLock;

#pragma mark -
#pragma mark "Animation"

- (void) startAnimation;
- (void) stopAnimation;
- (BOOL) isAnimationRunning;

- (void) updateAnimation;
- (void) drawFrame;

#pragma mark -
#pragma mark "Full screen"

- (NSOpenGLContext *) fullScreenOpenGLContext;
- (void) setFullScreenOpenGLContext: (NSOpenGLContext *) aFullScreenOpenGLContext;

- (NSOpenGLPixelFormat *) fullScreenPixelFormat;
- (void) setFullScreenPixelFormat: (NSOpenGLPixelFormat *) aFullScreenPixelFormat;

- (void) setFullScreenWidth: (int) width height: (int) height;

- (BOOL) fullScreen;
- (void) setFullScreen: (BOOL) flag;

- (void) willEnterFullScreen;
- (void) willExitFullScreen;

- (void) didEnterFullScreen;
- (void) didExitFullScreen;

@end
