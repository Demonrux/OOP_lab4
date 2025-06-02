#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class Edge {
private:
    Vertex begin;
    Vertex end;
public:
    Edge(Vertex& vertex1, Vertex& vertex2);
    Vertex& getBegin();
    Vertex& getEnd();
};

#endif // EDGE_H
