#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "transformmatrix.h"

class SceneObject {
public:
    virtual ~SceneObject() = default;
    virtual void Transform(TransformMatrix& transformMatrix) = 0;
};

#endif // SCENEOBJECT_H
