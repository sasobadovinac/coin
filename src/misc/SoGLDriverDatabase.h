#ifndef SOGLDRIVERDATABASE_H
#define SOGLDRIVERDATABASE_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2007 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See http://www.coin3d.org/ for more information.
 *
 *  Systems in Motion, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  http://www.sim.no/  sales@sim.no  coin-support@coin3d.org
 *
\**************************************************************************/

#ifndef COIN_INTERNAL
#error this is a private header file
#endif /* !COIN_INTERNAL */

// FIXME: consider if this should be part of the public Coin API. It
// will be useful for appliction/library programmers that make
// extension nodes with OpenGL code.

#include <Inventor/C/glue/gl.h>
#include <Inventor/lists/SbList.h>

class SoGLDriver;
class SoGLDriverDatabaseP;
class SbName;

class SoGLDriverDatabase {
public:
  static SbBool isSupported(const cc_glglue * context, const SbName & feature);
  static SbBool isBroken(const cc_glglue * context, const SbName & feature);
  static SbBool isSlow(const cc_glglue * context, const SbName & feature);
  static SbBool isFast(const cc_glglue * context, const SbName & feature);

public:
  static void init(void);

private:
  static SoGLDriverDatabaseP * pimpl(void);
};

/**************************************************************************/

// OpenGL features that can't be checked with a single GL_ARB/EXT extension test
#define SO_GL_MULTIDRAW_ELEMENTS    "COIN_multidraw_elements"
#define SO_GL_POLYGON_OFFSET        "COIN_polygon_offset"
#define SO_GL_TEXTURE_OBJECT        "COIN_texture_object"
#define SO_GL_3D_TEXTURES           "COIN_3d_textures"
#define SO_GL_MULTITEXTURE          "COIN_multitexture"
#define SO_GL_TEXSUBIMAGE           "COIN_texsubimage"
#define SO_GL_2D_PROXY_TEXTURES     "COIN_2d_proxy_textures"
#define SO_GL_TEXTURE_EDGE_CLAMP    "COIN_texture_edge_clamp"
#define SO_GL_TEXTURE_COMPRESSION   "COIN_texture_compression"
#define SO_GL_COLOR_TABLES          "COIN_color_tables"
#define SO_GL_COLOR_SUBTABLES       "COIN_color_subtables"
#define SO_GL_PALETTED_TEXTURES     "COIN_paletted_textures"
#define SO_GL_BLEND_EQUATION        "COIN_blend_equation"
#define SO_GL_VERTEX_ARRAY          "COIN_vertex_array"
#define SO_GL_NV_VERTEX_ARRAY_RANGE "COIN_nv_vertex_array_range"
#define SO_GL_VERTEX_BUFFER_OBJECT  "COIN_vertex_buffer_object"
#define SO_GL_ARB_FRAGMENT_PROGRAM  "COIN_arb_fragment_program"
#define SO_GL_ARB_VERTEX_PROGRAM    "COIN_arb_vertex_program"
#define SO_GL_ARB_SHADER_OBJECT     "COIN_arb_shader_object"
#define SO_GL_OCCLUSION_QUERY       "COIN_occlusion_query"
#define SO_GL_FRAMEBUFFER_OBJECT    "COIN_framebuffer_object"
#define SO_GL_ANISOTROPIC_FILTERING "COIN_anisotropic_filtering"
#define SO_GL_SORTED_LAYERS_BLEND   "COIN_sorted_layers_blend"
#define SO_GL_BUMPMAPPING           "COIN_bumpmapping"

#endif // SOGLDATABASE_H