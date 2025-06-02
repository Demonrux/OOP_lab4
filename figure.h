#ifndef FIGURE_H
#define FIGURE_H

#include "vector"
#include "sceneobject.h"
#include "vertex.h"
#include "edge.h"

class Figure: public SceneObject {
private:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
public:
    Figure(std::vector<Vertex>& verts, std::vector<Edge>& edgs);
    std::vector<Vertex>& getVertices();
    std::vector<Edge>& getEdges();
    void Transform(TransformMatrix& transformMatrix) override;
};

#endif // FIGURE_H
