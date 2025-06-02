#include "transformmatrix.h"

TransformMatrix::TransformMatrix(float mat[Constants::MATRIX_SIZE][Constants::MATRIX_SIZE]) {
    for (size_t i = 0; i < Constants::MATRIX_SIZE; i++) {
        for (size_t j = 0; j < Constants::MATRIX_SIZE; j++) {
            matr[i][j] = mat[i][j];
        }
    }
}

TransformMatrix TransformMatrix::operator *(TransformMatrix& transformMatrix) {
    float mat[Constants::MATRIX_SIZE][Constants::MATRIX_SIZE];

    for (size_t i = 0; i < Constants::MATRIX_SIZE; i++) {
        for (size_t j = 0; j < Constants::MATRIX_SIZE ;j++) {
            mat[i][j] = 0;
            for (size_t k = 0; k < Constants::MATRIX_SIZE; k++) {
                mat[i][j] += this->matr[i][k] * (transformMatrix.matr[k][j]);
            }
        }
    }
    TransformMatrix newTransformMatrix = mat;
    return newTransformMatrix;
}

Point3D TransformMatrix::TransformPoint(Point3D& point) {
    float x = matr[0][0] * point.x + matr[0][1] * point.y + matr[0][2] * point.z + matr[0][3];
    float y = matr[1][0] * point.x + matr[1][1] * point.y + matr[1][2] * point.z + matr[1][3];
    float z = matr[2][0] * point.x + matr[2][1] * point.y + matr[2][2] * point.z + matr[2][3];

    return Point3D{x, y, z};
}
