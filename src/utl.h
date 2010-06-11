#ifdef _MSC_VER
#pragma once
#endif

#ifndef _testMCG_utl_h_
#define _testMCG_utl_h_

#include <UnitTest++/UnitTest++.h>
#include <UnitTest++/CheckMsg.h>

#define CHECK_VECTOR3(V,X,Y,Z) \
  CHECK_MSG (FCOMPARE((V).x,X), "Check X value"); \
  CHECK_MSG (FCOMPARE((V).y,Y), "Check Y value"); \
  CHECK_MSG (FCOMPARE((V).z,Z), "Check Z value")

#define CHECK_VECTOR4(V,X,Y,Z,W) \
  CHECK_MSG (FCOMPARE((V).x,X), "Check X value"); \
  CHECK_MSG (FCOMPARE((V).y,Y), "Check Y value"); \
  CHECK_MSG (FCOMPARE((V).z,Z), "Check Z value"); \
  CHECK_MSG (FCOMPARE((V).w,W), "Check W value")

#define CHECK_QUATERNION(V,X,Y,Z,W) \
  CHECK_VECTOR4(V,X,Y,Z,W)

#define CHECK_MATRIX(M, M00,M01,M02,M03, \
                        M10,M11,M12,M13, \
                        M20,M21,M22,M23, \
                        M30,M31,M32,M33) \
  CHECK_MSG (FCOMPARE(M.m00,M00), "Check matrix [00] value, rotation component"); \
  CHECK_MSG (FCOMPARE(M.m01,M01), "Check matrix [01] value, rotation component"); \
  CHECK_MSG (FCOMPARE(M.m02,M02), "Check matrix [02] value, rotation component"); \
  CHECK_MSG (FCOMPARE(M.m03,M03), "Check matrix [03] value"); \
  \
  CHECK_MSG (FCOMPARE(M.m10,M10), "Check matrix [10] value, rotation component"); \
  CHECK_MSG (FCOMPARE(M.m11,M11), "Check matrix [11] value, rotation component"); \
  CHECK_MSG (FCOMPARE(M.m12,M12), "Check matrix [12] value, rotation component"); \
  CHECK_MSG (FCOMPARE(M.m13,M13), "Check matrix [13] value"); \
  \
  CHECK_MSG (FCOMPARE(M.m20,M20), "Check matrix [20] value, rotation component"); \
  CHECK_MSG (FCOMPARE(M.m21,M21), "Check matrix [21] value, rotation component"); \
  CHECK_MSG (FCOMPARE(M.m22,M22), "Check matrix [22] value, rotation component"); \
  CHECK_MSG (FCOMPARE(M.m23,M23), "Check matrix [23] value"); \
  \
  CHECK_MSG (FCOMPARE(M.m30,M30), "Check matrix [30] value, X translation"); \
  CHECK_MSG (FCOMPARE(M.m31,M31), "Check matrix [31] value, Y translation"); \
  CHECK_MSG (FCOMPARE(M.m32,M32), "Check matrix [32] value, Z translation"); \
  CHECK_MSG (FCOMPARE(M.m33,M33), "Check matrix [33] value")

#endif