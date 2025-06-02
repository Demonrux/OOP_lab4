#ifndef FACADE_H
#define FACADE_H

#include "normalizationparameters.h"
#include "basefilereader.h"
#include "Constants.h"
#include "scenedrawerbase.h"
#include "facadeoperationresult.h"
#include "transformmatrixbuilder.h"
#include "scene.h"

class Facade {
private:
    std::unique_ptr<BaseFileReader> fileReader;
    std::unique_ptr<SceneDrawerBase> sceneDrawer;
    std::unique_ptr<Scene> scene;
    Point3D currentMove = {Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE};
    Point3D currentScale = {Constants::DEFAULT_SCALE, Constants::DEFAULT_SCALE, Constants::DEFAULT_SCALE};
public:
    Facade(std::unique_ptr<BaseFileReader> reader, std::unique_ptr<SceneDrawerBase> drawer);
    void transformScene(TransformMatrix& matrix);
    FacadeOperationResult LoadScene(std::filesystem::path& path, NormalizationParameters& normalizattionParameters);
    FacadeOperationResult DrawScene();
    FacadeOperationResult MoveScene(float moveX, float moveY, float moveZ);
    FacadeOperationResult RotateScene(float rotateX, float rotateY, float rotateZ);
    FacadeOperationResult ScaleScene(float scaleX, float scaleY, float scaleZ);

};

#endif // FACADE_H
