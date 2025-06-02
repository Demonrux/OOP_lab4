#include "transformmatrixbuilder.h"

TransformMatrix TransformMatrixBuilder::CreateMoveMatrix(float moveX, float moveY, float moveZ) {
    float mat[Constants::MATRIX_SIZE][Constants::MATRIX_SIZE] =
        {{1, 0, 0, moveX},
        {0, 1, 0, moveY},
        {0, 0, 1, moveZ},
        {0, 0, 0, 1}};

    TransformMatrix transformMatrix = mat;

    return transformMatrix;
}

TransformMatrix TransformMatrixBuilder::CreateRotationMatrix(float rotateX, float rotateY, float rotateZ) {
    float matRotateX[Constants::MATRIX_SIZE][Constants::MATRIX_SIZE] =
        {{1, 0, 0, 0},
        {0, cos(rotateX), -sin(rotateX), 0},
        {0, sin(rotateX), cos(rotateX), 0},
        {0, 0, 0, 1}};

    float matRotateY[Constants::MATRIX_SIZE][Constants::MATRIX_SIZE] =
        {{cos(rotateY), 0, sin(rotateY), 0},
        {0, 1, 0, 0},
        {-sin(rotateY), 0, cos(rotateY), 0},
        {0, 0, 0, 1}};

    float matRotateZ[Constants::MATRIX_SIZE][Constants::MATRIX_SIZE] =
        {{cos(rotateZ), -sin(rotateZ), 0, 0},
        {sin(rotateZ), cos(rotateZ), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};

    TransformMatrix transformMatrixX = matRotateX;
    TransformMatrix transformMatrixY = matRotateY;
    TransformMatrix transformMatrixZ = matRotateZ;

    return transformMatrixX*transformMatrixY*transformMatrixZ;
}

TransformMatrix TransformMatrixBuilder::CreateScaleMatrix(float scaleX, float scaleY, float scaleZ) {
    float mat[Constants::MATRIX_SIZE][Constants::MATRIX_SIZE] =
        {{scaleX, 0, 0, 0},
        {0, scaleY, 0, 0},
        {0, 0, scaleZ, 0},
        {0, 0, 0, 1}};

    TransformMatrix transformMatrix = mat;

    return transformMatrix;
}
