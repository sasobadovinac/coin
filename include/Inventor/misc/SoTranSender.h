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

#ifndef COIN_SOTRANSENDER_H
#define COIN_SOTRANSENDER_H

#include <Inventor/SbBasic.h>

class SoOutput;
class SoNode;


class COIN_DLL_EXPORT SoTranSender {

public:
  SoTranSender(SoOutput * output);
  ~SoTranSender();

  SoOutput * getOutput(void) const;
  void insert(SoNode * node);
  void insert(SoNode * node, SoNode * parent, int n);
  void remove(SoNode * parent, int n);
  void replace(SoNode * parent, int n, SoNode * newnode);
  void modify(SoNode * node);
  void prepareToSend(void);

private:
  // Placeholder for any data for the instance. Just added for the
  // sake of making it possible to implement this class after release
  // without breaking ABI compatibility.
  void * pimpl;
};

#endif // COIN_SOTRANSENDER_H
