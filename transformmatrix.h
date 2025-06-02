#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H

#include "point3d.h"
#include "iostream"
#include "Constants.h"

class TransformMatrix {
private:
    float matr[Constants::MATRIX_SIZE][Constants::MATRIX_SIZE];
public:
    TransformMatrix(float mat[Constants::MATRIX_SIZE][Constants::MATRIX_SIZE]);
    TransformMatrix operator*(TransformMatrix& transformMatrix);
    Point3D TransformPoint(Point3D& point3D);
};

#endif // TRANSFORMMATRIX_H
