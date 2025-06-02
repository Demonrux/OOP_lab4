#ifndef TRANSFORMMATRIXBUILDER_H
#define TRANSFORMMATRIXBUILDER_H

#include "transformmatrix.h"
#include "Constants.h"
#include <math.h>

class TransformMatrixBuilder {
public:
    static TransformMatrix CreateRotationMatrix(float rotateX, float roateY, float rotateZ);
    static TransformMatrix CreateScaleMatrix(float scaleX, float scaleY, float scaleZ);
    static TransformMatrix CreateMoveMatrix(float moveX, float moveY, float moveZ);
};

#endif // TRANSFORMMATRIXBUILDER_H
