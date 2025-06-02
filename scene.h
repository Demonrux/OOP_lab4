#ifndef SCENE_H
#define SCENE_H

#include "figure.h"
#include "filesystem"

class Scene {
private:
    std::vector<std::shared_ptr<Figure>> figures;
public:
    std::vector<std::shared_ptr<Figure>>& getFigures();
    void TranformFigures(TransformMatrix& transforMatrix);
};

#endif // SCENE_H
