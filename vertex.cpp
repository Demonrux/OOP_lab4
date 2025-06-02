#include "vertex.h"

Vertex::Vertex(Point3D point): position(point) {}

Point3D& Vertex::getPosition() {
    return this->position;
}

void Vertex::Transform(TransformMatrix& transformMatrix) {
    position = transformMatrix.TransformPoint(this->position);
}
