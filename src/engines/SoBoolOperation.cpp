/**************************************************************************\
 *
 *  Copyright (C) 1998-2000 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

/*!
  \class SoBoolOperation SoBoolOperation.h Inventor/engines/SoBoolOperation.h
  \brief The SoBoolOperation class performs boolean operations.
  \ingroup engines

  FIXME: doc
*/

#include <Inventor/engines/SoBoolOperation.h>
#include <Inventor/lists/SoEngineOutputList.h>
#include <Inventor/engines/SoSubEngineP.h>

#if COIN_DEBUG
#include <Inventor/errors/SoDebugError.h>
#endif // COIN_DEBUG

SO_ENGINE_SOURCE(SoBoolOperation);

/*!
  Defalt constructor.
*/
SoBoolOperation::SoBoolOperation()
{
  SO_ENGINE_INTERNAL_CONSTRUCTOR(SoBoolOperation);

  SO_ENGINE_ADD_INPUT(a,(FALSE));
  SO_ENGINE_ADD_INPUT(b,(FALSE));
  SO_ENGINE_ADD_INPUT(operation,(SoBoolOperation::A));

  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, CLEAR);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, SET);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, A);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, NOT_A);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, NOT_B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, A_OR_B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, NOT_A_OR_B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, A_OR_NOT_B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, NOT_A_OR_NOT_B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, A_AND_B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, NOT_A_AND_B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, A_AND_NOT_B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, NOT_A_AND_NOT_B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, A_EQUALS_B);
  SO_ENGINE_DEFINE_ENUM_VALUE(Operation, A_NOT_EQUALS_B);

  SO_ENGINE_SET_MF_ENUM_TYPE(operation, Operation);

  SO_ENGINE_ADD_OUTPUT(output, SoMFBool);
  SO_ENGINE_ADD_OUTPUT(inverse, SoMFBool);
}

// doc from parent
void
SoBoolOperation::initClass()
{
  SO_ENGINE_INTERNAL_INIT_CLASS(SoBoolOperation);
}

/*!
  Destructor.
*/
SoBoolOperation::~SoBoolOperation()
{
}

// doc from parent
void
SoBoolOperation::evaluate()
{
  SbBool _a, _b, _op, val;
  int numA = this->a.getNum();
  int numB = this->b.getNum();
  int numOp = this->operation.getNum();

  int numOut = SbMax(SbMax(numA, numB), numOp);

  SO_ENGINE_OUTPUT(output,SoMFBool,setNum(numOut));
  SO_ENGINE_OUTPUT(inverse,SoMFBool,setNum(numOut));

  for (int i = 0; i < numOut; i++) {
    _a = i < numA ? this->a[i] : this->a[numA-1];
    _b = i < numB ? this->b[i] : this->b[numB-1];
    _op = i < numOp ? this->operation[i] : this->operation[numOp-1];

    switch (_op) {
    case CLEAR:
      val = FALSE;
      break;
    case SET:
      val = TRUE;
      break;
    case A:
      val = _a;
      break;
    case NOT_A:
      val = !_a;
      break;
    case B:
      val = _b;
      break;
    case NOT_B:
      val = !_b;
      break;
    case A_OR_B:
      val = _a || _b;
      break;
    case NOT_A_OR_B:
      val = !_a || _b;
      break;
    case A_OR_NOT_B:
      val = _a || !_b;
      break;
    case NOT_A_OR_NOT_B:
      val = !_a || !_b;
      break;
    case A_AND_B:
      val = _a && _b;
      break;
    case NOT_A_AND_B:
      val = !_a && _b;
      break;
    case A_AND_NOT_B:
      val = _a && !_b;
      break;
    case NOT_A_AND_NOT_B:
      val = !_a && !_b;
      break;
    case A_EQUALS_B:
      val = (a==b);
      break;
    case A_NOT_EQUALS_B:
      val = (a != b);
      break;
    default:
#if COIN_DEBUG && 1 // debug
      SoDebugError::postInfo("SoBoolOperation::evaluate",
                             "unknown bool operation");
#endif // debug
      val = TRUE; // avoid compiler warning
      break;
    }

    SO_ENGINE_OUTPUT(output, SoMFBool, set1Value(i, val));
    SO_ENGINE_OUTPUT(inverse, SoMFBool, set1Value(i, !val));
  }
}
