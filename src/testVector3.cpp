#include <UnitTest++/UnitTest++.h>
#include <UnitTest++/CheckMsg.h>

#include <MCG/Vector2.h>
#include <MCG/Vector3.h>
#include <MCG/Vector4.h>

#include <math.h>
#include "utl.h"

//----------------------------------------------------------------------
SUITE (MCG_Vector3)
{
  TEST(Vector3_ConstructorDefault)
  {
    MCG::Vector3 vector;
    CHECK_VECTOR3 (vector,0,0,0);
  }

  TEST(Vector3_ConstructorComponents)
  {
    MCG::Vector3 vector (1,2,3);
    CHECK_VECTOR3 (vector,1,2,3);
  }

  TEST(Vector3_ConstructorVector2)
  {
    MCG::Vector2 v2 (1,2);

    MCG::Vector3 vector (v2);
    CHECK_VECTOR3 (vector,1,2,0);
  }

  TEST(Vector3_ConstructorVector4)
  {
    MCG::Vector4 v4 (1,2,3,4);

    MCG::Vector3 vector (v4);
    CHECK_VECTOR3 (vector,1,2,3);
  }

  //----------------------------------------------------------------------

  TEST(Vector3_SetDefault)
  {
    MCG::Vector3 vector (1,2,3);

    vector.Set();
    CHECK_VECTOR3 (vector,0,0,0);
  }

  TEST(Vector3_SetComponents)
  {
    MCG::Vector3 vector;
    vector.Set(1,2,3);
    CHECK_VECTOR3 (vector,1,2,3);
  }

  //----------------------------------------------------------------------

  TEST (Vector3_SetColour)
  {
    MCG::Vector3 vector;
    vector.SetColour(255.0, 255.0/2.0, 255.0/3.0);
    CHECK_VECTOR3 (vector, 1.0, 1.0/2.0, 1.0/3.0);
  }

  //----------------------------------------------------------------------

  TEST (Vector3_MagnitudeSquared)
  {
    MCG::Vector3 vector (1,2,3);
    //CHECK_CLOSE (vector.MagnitudeSquared(), 1*1 + 2*2 + 3*3, 0.001 );
    MCG::Real magsq = 1.0*1.0 + 2.0*2.0 + 3.0*3.0;
    CHECK_MSG(FCOMPARE(vector.MagnitudeSquared(), magsq), "Check magnitude squared");
  }

  TEST (Vector3_Magnitude)
  {
    MCG::Vector3 vector (1,2,3);
    //CHECK_CLOSE (vector.Magnitude(), sqrt(1.0*1.0 + 2.0*2.0 + 3.0*3.0), 0.001 );
    MCG::Real mag = sqrt(1.0*1.0 + 2.0*2.0 + 3.0*3.0);
    CHECK_MSG(FCOMPARE(vector.Magnitude(), mag), "Check magnitude");
  }

  //----------------------------------------------------------------------

  TEST (Vector3_Normalise)
  {
    MCG::Vector3 vector (1,2,3);
    MCG::Vector3 original (1,2,3);
    vector.Normalise();

    // check magnitude (squared) == 1
    CHECK_MSG(FCOMPARE(vector.Magnitude(), 1), "Check magnitude");

    // check angle between  == 0
    // a.b = |a|*|b|*cos(C)
    // cos(C) = |b| / (a.b), assuming vector is a, and |vector| == 1
    // C == 0, cos(C) == 1
    MCG::Real cos_angle_ = original.Magnitude() / (vector * original);
    CHECK_MSG(FCOMPARE(cos_angle_, 1), "Check angle between");
  }

  TEST (Vector3_Scale)
  {
    MCG::Vector3 vector (1,2,3);
    MCG::Vector3 original (1,2,3);
    vector.Scale(40);

    // check magnitude (squared) == 1600 (40*40)
    CHECK_MSG(FCOMPARE(vector.Magnitude(), 40), "Check magnitude is scaled");

    // check angle between  == 0
    // a.b = |a|*|b|*cos(C)
    // cos(C) = |b|*40 / (a.b), assuming vector is a, and |vector| == 40
    // C == 0, cos(C) == 1
    MCG::Real cos_angle_ = (original.Magnitude() * 40) / (vector * original);
    CHECK_MSG(FCOMPARE(cos_angle_, 1), "Check angle between");
  }

  TEST (Vector3_Truncate)
  {
    MCG::Vector3 vector (1,2,3);
    MCG::Vector3 original (1,2,3);
    // truncate using limit greater than vector
    vector.Truncate(40);

    // check magnitude (squared)
    CHECK_MSG (vector == original, "Check vector is unchanged");

    // truncate using limit less than vector
    vector.Truncate(2);
    // check magnitude (squared)
    CHECK_MSG(FCOMPARE(vector.Magnitude(), 2), "Check magnitude is truncated");


    // check angle between  == 0
    // a.b = |a|*|b|*cos(C)
    // cos(C) = |b|*40 / (a.b), assuming vector is a, and |vector| == 40
    // C == 0, cos(C) == 1
    MCG::Real cos_angle_ = (original.Magnitude() * 2) / (vector * original);
    CHECK_MSG(FCOMPARE(cos_angle_, 1), "Check angle between");
  }

  //----------------------------------------------------------------------

  TEST(Vector3_NegativeOp)
  {
    MCG::Vector3 vector (1,2,3);
    CHECK_VECTOR3 (-vector,-1,-2,-3);
  }

  //----------------------------------------------------------------------

  TEST(Vector3_AddOp)
  {
    MCG::Vector3 vA (1,2,3);
    MCG::Vector3 vB (1,2,3);
    CHECK_VECTOR3 (vA + vB, 2,4,6);
  }

  TEST(Vector3_SubtractOp)
  {
    MCG::Vector3 vA (1,2,3);
    MCG::Vector3 vB (1,2,3);
    CHECK_VECTOR3 (vA - vB, 0,0,0);
  }

  TEST(Vector3_DotOp)
  {
    MCG::Vector3 vA (1,2,3);
    MCG::Vector3 vB (2,3,1);

    MCG::Real output = vA * vB;
    MCG::Real dot = 1*2 + 2*3 + 3*1;
    CHECK_MSG(FCOMPARE(output,dot), "Check dot product");
  }

  TEST(Vector3_CrossOp)
  {
    MCG::Vector3 vA (2,0,0);
    MCG::Vector3 vB (0,2,0);
    
    CHECK_VECTOR3 (vA^vB, 0,0,4);
  }

  TEST(Vector3_MultiplyOp)
  {
    MCG::Vector3 vA (1,2,3);

    // check magnitude (squared) == 1600 (40*40)
    CHECK_MSG(FCOMPARE((vA * 4.5).Magnitude(), vA.Magnitude()*4.5), "Check magnitude is scaled");

    // check angle between  == 0
    // a.b = |a|*|b|*cos(C)
    // cos(C) = |b|*40 / (a.b), assuming vector is a, and |vector| == 40
    // C == 0, cos(C) == 1
    MCG::Real cos_angle_ = (vA.Magnitude() * (vA * 4.5).Magnitude()) / ((vA * 4.5) * vA);
    CHECK_MSG(FCOMPARE(cos_angle_, 1), "Check angle between");
  }

  //----------------------------------------------------------------------

  TEST(Vector3_AssignOp_Vector2)
  {
    MCG::Vector2 v2 (1,2);
    MCG::Vector3 vector (3,2,1);
    vector = v2;
    CHECK_VECTOR3 (vector,1,2,0);
  }

  TEST(Vector3_AssignOp_Vector3)
  {
    MCG::Vector3 v3 (1,2,3);
    MCG::Vector3 vector (3,2,1);
    vector = v3;
    CHECK_VECTOR3 (vector,1,2,3);
  }

  TEST(Vector3_AssignOp_Vector4)
  {
    MCG::Vector4 v4 (1,2,3,4);
    MCG::Vector3 vector (3,2,1);
    vector = v4;
    CHECK_VECTOR3 (vector,1,2,3);
  }

  TEST(Vector3_AddAssignOp)
  {
    MCG::Vector3 vA (1,2,3);
    MCG::Vector3 vB (1,2,3);
    vA += vB;
    CHECK_VECTOR3 (vA,2,4,6);
  }

  TEST(Vector3_SubractAssignOp)
  {
    MCG::Vector3 vA (1,2,3);
    MCG::Vector3 vB (1,2,3);
    vA -= vB;
    CHECK_VECTOR3 (vA,0,0,0);
  }

  TEST(Vector3_MultiplyAssignOp)
  {
    MCG::Vector3 vector (1,2,3);
    MCG::Vector3 original (1,2,3);
    vector *= 4.5;

    // check magnitude (squared) == 1600 (40*40)
    CHECK_MSG(FCOMPARE(vector.Magnitude(), original.Magnitude()*4.5), "Check magnitude is scaled");

    // check angle between  == 0
    // a.b = |a|*|b|*cos(C)
    // cos(C) = |b|*40 / (a.b), assuming vector is a, and |vector| == 40
    // C == 0, cos(C) == 1
    MCG::Real cos_angle_ = (original.Magnitude() * vector.Magnitude()) / (vector * original);
    CHECK_MSG(FCOMPARE(cos_angle_, 1), "Check angle between");
  }

  TEST(Vector3_DivideAssignOp)
  {
    MCG::Vector3 vector (1,2,3);
    MCG::Vector3 original (1,2,3);
    vector /= 4.5;

    // check magnitude (squared) == 1600 (40*40)
    CHECK_MSG(FCOMPARE(vector.Magnitude(), original.Magnitude()/4.5), "Check magnitude is scaled");

    // check angle between  == 0
    // a.b = |a|*|b|*cos(C)
    // cos(C) = |b|*40 / (a.b), assuming vector is a, and |vector| == 40
    // C == 0, cos(C) == 1
    MCG::Real cos_angle_ = (original.Magnitude() * vector.Magnitude()) / (vector * original);
    CHECK_MSG(FCOMPARE(cos_angle_, 1), "Check angle between");
  }

  //----------------------------------------------------------------------

  TEST(Vector3_EqualOp)
  {
    MCG::Vector3 vA (1,2,3);
    MCG::Vector3 vB (1,2,3);
    CHECK_MSG((vA == vB) == true, "Check true condition");

    MCG::Vector3 vC (2,1,4);
    CHECK_MSG((vA == vC) == false, "Check false condition");
  }

  TEST(Vector3_NotEqualOp)
  {
    MCG::Vector3 vA (1,2,3);
    MCG::Vector3 vB (1,2,3);
    CHECK_MSG((vA != vB) == false, "Check false condition");

    MCG::Vector3 vC (2,1,4);
    CHECK_MSG((vA != vC) == true, "Check true condition");
  }
}
