#ifndef COIN_SOSFBITMASK_H
#define COIN_SOSFBITMASK_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2001 by Systems in Motion.  All rights reserved.
 *  
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  version 2 as published by the Free Software Foundation.  See the
 *  file LICENSE.GPL at the root directory of this source distribution
 *  for more details.
 *
 *  If you desire to use Coin with software that is incompatible
 *  licensewise with the GPL, and / or you would like to take
 *  advantage of the additional benefits with regard to our support
 *  services, please contact Systems in Motion about acquiring a Coin
 *  Professional Edition License.  See <URL:http://www.coin3d.org> for
 *  more information.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  <URL:http://www.sim.no>, <mailto:support@sim.no>
 *
\**************************************************************************/

#include <Inventor/fields/SoSFEnum.h>

class COIN_DLL_API SoSFBitMask : public SoSFEnum {
  typedef SoSFEnum inherited;

  SO_SFIELD_DERIVED_HEADER(SoSFBitMask, int, int);

public:
  static void initClass(void);

  // FIXME: there's a bug in Doxygen (at least with version 1.2.9)
  // which causes the following statement to be regarded as a member
  // variable. Remove this workaround when the bug has been
  // fixed. 20011125 mortene.
#ifndef DOXYGEN_SKIP_THIS
  friend class SoMFBitMask; // For readValue() & writeValue().
#endif // DOXYGEN_SKIP_THIS
};

#endif // !COIN_SOSFBITMASK_H
