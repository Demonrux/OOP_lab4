#include "figure.h"

Figure:: Figure(std::vector<Vertex>& verts, std::vector<Edge>& edgs) : vertices(verts), edges(edgs) {}

std::vector<Vertex>& Figure::getVertices() {
    return this->vertices;
}

std::vector<Edge>& Figure::getEdges() {
    return this->edges;
}

void Figure::Transform(TransformMatrix& transformMatrix) {
    for(Vertex& vertex : vertices)
       vertex.Transform(transformMatrix);

    for(Edge& edge : edges) {
        edge.getBegin().Transform(transformMatrix);
        edge.getEnd().Transform(transformMatrix);
    }
}
