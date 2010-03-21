//
// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// Surface.h: Defines the egl::Surface class, representing a drawing surface
// such as the client area of a window, including any back buffers.
// Implements EGLSurface and related functionality. [EGL 1.4] section 2.2 page 3.

#ifndef INCLUDE_SURFACE_H_
#define INCLUDE_SURFACE_H_

#define EGLAPI
#include <EGL/egl.h>
#include <d3d9.h>

#include "angleutils.h"

namespace egl
{
class Surface
{
  public:
    Surface(IDirect3DDevice9 *device, IDirect3DSwapChain9 *swapChain, IDirect3DSurface9* depthStencil, EGLint configID);

    ~Surface();

    HWND getWindowHandle();
    void swap();

    EGLint getWidth() const;
    EGLint getHeight() const;

    virtual IDirect3DSurface9 *getRenderTarget();
    virtual IDirect3DSurface9 *getDepthStencil();

  private:
    DISALLOW_COPY_AND_ASSIGN(Surface);
    IDirect3DSwapChain9 *const mSwapChain;
    IDirect3DSurface9 *mBackBuffer;
    IDirect3DSurface9 *mRenderTarget;
    IDirect3DSurface9 *mDepthStencil;

    const EGLint mConfigID;            // ID of EGLConfig surface was created with
    EGLint mHeight;                    // Height of surface
    EGLint mWidth;                    // Width of surface
//    EGLint horizontalResolution;    // Horizontal dot pitch
//    EGLint verticalResolution;        // Vertical dot pitch
//    EGLBoolean largestPBuffer;        // If true, create largest pbuffer possible
//    EGLBoolean mipmapTexture;        // True if texture has mipmaps
//    EGLint mipmapLevel;                // Mipmap level to render to
//    EGLenum multisampleResolve;        // Multisample resolve behavior
    EGLint mPixelAspectRatio;        // Display aspect ratio
    EGLenum mRenderBuffer;            // Render buffer
    EGLenum mSwapBehavior;            // Buffer swap behavior
//    EGLenum textureFormat;            // Format of texture: RGB, RGBA, or no texture
//    EGLenum textureTarget;            // Type of texture: 2D or no texture
//    EGLenum vgAlphaFormat;            // Alpha format for OpenVG
//    EGLenum vgColorSpace;            // Color space for OpenVG
};
}

#endif   // INCLUDE_SURFACE_H_