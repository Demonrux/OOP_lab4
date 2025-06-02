#include "edge.h"

Edge::Edge(Vertex& vertex1, Vertex& vertex2) :begin(vertex1), end(vertex2) {}

Vertex& Edge::getBegin() {
    return this->begin;
}

Vertex& Edge::getEnd() {
    return this->end;
}
