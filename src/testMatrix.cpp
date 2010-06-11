#include <UnitTest++/UnitTest++.h>
#include <UnitTest++/CheckMsg.h>

#include <MCG/Vector3.h>
#include <MCG/Matrix.h>
#include <MCG/Quaternion.h>

#include "utl.h"

//----------------------------------------------------------------------

SUITE (MCG_Matrix)
{
  TEST (Matrix_ConstructorDefault)
  {
    MCG::Matrix mat;
    CHECK_MATRIX(mat, 1,0,0,0,
                      0,1,0,0,
                      0,0,1,0,
                      0,0,0,1);
  }

  TEST (Matrix_ConstructorComponents)
  {
    MCG::Matrix mat (1,2,3,4,
                     5,6,7,8,
                     9,0,1,2,
                     3,4,5,6);

    CHECK_MATRIX(mat, 1,2,3,4,
                      5,6,7,8,
                      9,0,1,2,
                      3,4,5,6);
  }

  TEST (Matrix_ConstructorMatrix)
  {
    MCG::Matrix input (1,2,3,4,
                       5,6,7,8,
                       9,0,1,2,
                       3,4,5,6);

    MCG::Matrix mat (input);

    CHECK_MATRIX(mat, 1,2,3,4,
                      5,6,7,8,
                      9,0,1,2,
                      3,4,5,6);
  }

//   TEST (Matrix_ConstructorVector3)
//   {
//     MCG::Vector3 input (1,2,3);
//     MCG::Matrix mat (input);
// 
//     CHECK_MATRIX(mat, 1,0,0,0,
//                       0,1,0,0,
//                       0,0,1,0,
//                       1,2,3,1);
//   }

  TEST (Matrix_Identity)
  {
  	MCG::Matrix mat (1,2,3,4,
                     5,6,7,8,
                     9,0,1,2,
                     3,4,5,6);

    mat.Identity();
    CHECK_MATRIX(mat, 1,0,0,0,
                      0,1,0,0,
                      0,0,1,0,
                      0,0,0,1);
  }

  TEST (Matrix_Transpose)
  {
    MCG::Matrix mat (1,2,3,4,
                     5,6,7,8,
                     9,0,1,2,
                     3,4,5,6);

    mat.Transpose();
    CHECK_MATRIX(mat, 1,5,9,3,
                      2,6,0,4,
                      3,7,1,5,
                      4,8,2,6);
  }

  TEST (Matrix_GetTranspose)
  {
    MCG::Matrix mat (1,2,3,4,
      5,6,7,8,
      9,0,1,2,
      3,4,5,6);

    MCG::Matrix test (mat.GetTranspose());
    CHECK_MATRIX(test, 1,5,9,3,
                       2,6,0,4,
                       3,7,1,5,
                       4,8,2,6);
  }
  
  TEST (Matrix_Invert)
  {
    MCG::Matrix mat;

    mat.Invert();
    CHECK_MATRIX(mat, 1,0,0,0,
                      0,1,0,0,
                      0,0,1,0,
                      0,0,0,1);

    // needs two more test, one for a matrix with NO inverse, and a valid inverse
  }

  TEST (Matrix_ToQuat)
  {
    // get a valid quaternion
    MCG::Matrix mat = MCG::Matrix::NewXAxisRotation(MCG::PI_OVER_2);
    MCG::Quaternion quat = mat.ToQuat();
    CHECK_QUATERNION (quat,sqrt(0.5),0,0,sqrt(0.5));
  }

}