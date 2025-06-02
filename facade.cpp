#include "facade.h"
#include "transformmatrixbuilder.h"

Facade::Facade(std::unique_ptr<BaseFileReader> reader, std::unique_ptr<SceneDrawerBase> drawer)
    : fileReader(std::move(reader)), sceneDrawer(std::move(drawer)) {}

FacadeOperationResult Facade::LoadScene(std::filesystem::path& path, NormalizationParameters& normalizattionParameters) {
    currentMove = {Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE};
    currentScale = {Constants::DEFAULT_SCALE, Constants::DEFAULT_SCALE, Constants::DEFAULT_SCALE};

    if (normalizattionParameters.max <= normalizattionParameters.min || normalizattionParameters.step < 1)
        return  FacadeOperationResult::InvaidParams();
    if(path.extension() != ".csv")
        return FacadeOperationResult::InvalidFile();

    scene = fileReader->ReadScene(path, normalizattionParameters);

    return scene ? FacadeOperationResult::Success() :FacadeOperationResult::InvalidFile();
}

FacadeOperationResult Facade::DrawScene() {
    if (!scene || !sceneDrawer)
        return FacadeOperationResult::DrawError();

    sceneDrawer->clear();
    sceneDrawer->DrawScene(*scene);

    return FacadeOperationResult::Success();
}

FacadeOperationResult Facade::MoveScene(float moveX, float moveY, float moveZ) {
    if (!scene)
        return FacadeOperationResult::InvalidData();

    float newX = currentMove.x + moveX;
    float newY = currentMove.y + moveY;
    float newZ = currentMove.z + moveZ;

    if (std::abs(newX) > Constants::MAX_TRANSLATE ||
        std::abs(newY) > Constants::MAX_TRANSLATE ||
        std::abs(newZ) > Constants::MAX_TRANSLATE) {
        return FacadeOperationResult::TranslationLimit();
    }

    currentMove.x = newX;
    currentMove.y = newY;
    currentMove.z = newZ;

    auto moveMatrix = TransformMatrixBuilder::CreateMoveMatrix(moveX, moveY, moveZ);
    transformScene(moveMatrix);

    return FacadeOperationResult::Success();
}

FacadeOperationResult Facade::RotateScene(float rotateX, float rotateY, float rotateZ) {
    if (!scene)
        return FacadeOperationResult::InvalidData();

    float radX =  rotateX * (Constants::PI / 180.0);
    float radY =  rotateY * (Constants::PI / 180.0);
    float radZ =  rotateZ * (Constants::PI / 180.0);

    auto rotationMatrix = TransformMatrixBuilder::CreateRotationMatrix(radX, radY , radZ);
    transformScene(rotationMatrix);

    return FacadeOperationResult::Success();
}

FacadeOperationResult Facade::ScaleScene(float scaleX, float scaleY, float scaleZ) {
    if (!scene)
        return FacadeOperationResult::InvalidData();

    float newScaleX = currentScale.x * scaleX;
    float newScaleY = currentScale.y * scaleY;
    float newScaleZ = currentScale.z * scaleZ;

    if (newScaleX < Constants::MIN_SCALE || newScaleX > Constants::MAX_SCALE ||
        newScaleY < Constants::MIN_SCALE || newScaleY > Constants::MAX_SCALE ||
        newScaleZ < Constants::MIN_SCALE || newScaleZ > Constants::MAX_SCALE) {
        return
            FacadeOperationResult::ScaleLimit();
    }

    currentScale.x = newScaleX;
    currentScale.y = newScaleY;
    currentScale.z = newScaleZ;

    auto scaleMatrix = TransformMatrixBuilder::CreateScaleMatrix(scaleY, scaleY, scaleZ);
    transformScene(scaleMatrix);

    return FacadeOperationResult::Success();
}

void Facade::transformScene(TransformMatrix& matrix) {
    if (scene) {
        scene->TranformFigures(matrix);
    }
}
