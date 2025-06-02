#include "scene.h"

std::vector<std::shared_ptr<Figure>>& Scene::getFigures() {
    return this->figures;
}


void Scene::TranformFigures(TransformMatrix& transforMatrix) {
    for(auto& figure : figures)
        figure->Transform(transforMatrix);
}
