#ifndef VERTEX_H
#define VERTEX_H

#include "point3d.h"
#include "sceneobject.h"

class Vertex: public SceneObject {
private:
    Point3D position;
public:
    Vertex(Point3D point);
    Point3D& getPosition();
    void Transform(TransformMatrix& transformMatrix) override;
};

#endif // VERTEX_H
