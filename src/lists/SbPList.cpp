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
  \class SbPList SbPList.h Inventor/lists/SbPList.h
  \brief The SbPList class is a container class for void pointers.
  \ingroup base

  This class is for most purposes superseded by the Coin-specific
  SbList class.
*/


#include <Inventor/lists/SbPList.h>

/*!
  \fn SbPList::SbPList(void)

  Default constructor.
*/

/*!
  \fn SbPList::SbPList(const int sizehint)

  This constructor initializes the internal allocated size for the
  list to \a sizehint. Note that the list will still initially contain
  zero items.

  \sa SbList::SbList(const int sizehint)
*/

/*!
  \fn SbPList::SbPList(const SbPList & l)
  Copy constructor.

  \sa SbList::SbList(const SbList<Type> & l)
*/

/*!
  \fn void * SbPList::get(const int index) const

  Returns element at \a index. Does \e not expand array bounds if \a
  index is outside the list.
*/

 /*!
   \fn void SbPList::set(const int index, void * const item)

   Index operator to set element at \a index. Does \e not expand array
   bounds if \a index is outside the list.
 */

/*!
  Returns element at \a index.

  Overloaded from parent class to automatically expand the size of the
  internal array if \a index is outside the current bounds of the
  list. The values of any additional pointers are then set to \c NULL.
 */
void *
SbPList::operator[](const int index) const
{
  assert(index >= 0);
  if (index >= this->getLength()) ((SbPList *)this)->expandlist(index + 1);
  return SbList<void *>::operator[](index);
}

/*!
  Index operator to set element at \a index.

  Overloaded from parent class to automatically expand the size of the
  internal array if \a index is outside the current bounds of the
  list. The values of any additional pointers are then set to \c NULL.
 */
void * &
SbPList::operator[](const int index)
{
  assert(index >= 0);
  if (index >= this->getLength()) this->expandlist(index + 1);
  return SbList<void *>::operator[](index);
}

// Expand list to the given size, filling in with NULL pointers.
void
SbPList::expandlist(const int size)
{
  const int oldsize = this->getLength();
  this->expand(size);
  SbList<void *> * thisp = (SbList<void *> *)this;
  for (int i = oldsize; i < size; i++) (*thisp)[i] = NULL;
}
