/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2000 by Systems in Motion. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation. See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin for applications not compatible with the
 *  LGPL, please contact SIM to acquire a Professional Edition license.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/

/*!
  \class SoCameraKit SoCameraKit.h Inventor/nodekits/SoCameraKit.h
  \brief The SoCameraKit class ...
  \ingroup nodekits

  FIXME: write class doc
*/

#include <Inventor/nodekits/SoCameraKit.h>
#include <Inventor/nodekits/SoSubKitP.h>
#include <Inventor/nodes/SoTransformSeparator.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>


SO_KIT_SOURCE(SoCameraKit);


/*!
  Constructor.
*/
SoCameraKit::SoCameraKit(void)
{
  SO_KIT_INTERNAL_CONSTRUCTOR(SoCameraKit);

  // Note: we must use "" instead of , , to humour MS VisualC++ 6.

  SO_KIT_ADD_CATALOG_ENTRY(transformGroup, SoTransformSeparator, TRUE, this, "", FALSE);
  SO_KIT_ADD_CATALOG_ENTRY(transform, SoTransform, TRUE, transformGroup, camera, TRUE);
  SO_KIT_ADD_CATALOG_ABSTRACT_ENTRY(camera, SoCamera, SoPerspectiveCamera, FALSE, transformGroup, "", TRUE);

  SO_KIT_INIT_INSTANCE();
}

/*!
  Destructor.
*/
SoCameraKit::~SoCameraKit()
{
}

/*!
  Does initialization common for all objects of the
  SoCameraKit class. This includes setting up the
  type system, among other things.
*/
void
SoCameraKit::initClass(void)
{
  SO_KIT_INTERNAL_INIT_CLASS(SoCameraKit);
}
