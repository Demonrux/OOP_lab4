#include "facadeoperationresult.h"

FacadeOperationResult::FacadeOperationResult(OperationResult result, std::string errorMessage)
    : result(result), message(errorMessage) {}

bool FacadeOperationResult::isSuccess(){
    return result == OperationResult::Success;
}

FacadeOperationResult::OperationResult FacadeOperationResult::getResult(){
    return result;
}

std::string FacadeOperationResult::getMessage(){
    return message;
}

FacadeOperationResult FacadeOperationResult::DrawError() {
    return FacadeOperationResult(OperationResult::DrawError, "Ошибка при отрисовки сцены");
}

FacadeOperationResult FacadeOperationResult::Success() {
    return FacadeOperationResult(OperationResult::Success, "Успешно");
}

FacadeOperationResult FacadeOperationResult::InvaidParams() {
    return FacadeOperationResult(OperationResult::InvalidParams, "Некорректные параметры загрузки");
}

FacadeOperationResult FacadeOperationResult::InvalidFile() {
    return FacadeOperationResult(OperationResult::InvalidFile, "Ошибка при чтении файла");
}

FacadeOperationResult FacadeOperationResult::InvalidData() {
    return FacadeOperationResult(OperationResult::InvalidData, "Ошибка при чтиени данных");
}

FacadeOperationResult FacadeOperationResult::TranslationLimit() {
    return FacadeOperationResult(OperationResult::TranslationLimit, "Достигнут предел сдвига");
}

FacadeOperationResult FacadeOperationResult::ScaleLimit() {
    return FacadeOperationResult(OperationResult::ScaleLimit, "Достигнут предел масштабирования");
}
