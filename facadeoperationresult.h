#ifndef FACADEOPERATIONRESULT_H
#define FACADEOPERATIONRESULT_H

#include <string>

class FacadeOperationResult {
public:
    enum class OperationResult {
        Success,
        InvalidFile,
        InvalidData,
        InvalidParams,
        DrawError,
        TranslationLimit,
        ScaleLimit
    };
    FacadeOperationResult(OperationResult result, std::string errorMessage);
    bool isSuccess();
    OperationResult getResult();
    std::string getMessage();
    static FacadeOperationResult DrawError();
    static FacadeOperationResult Success();
    static FacadeOperationResult InvalidFile();
    static FacadeOperationResult InvalidData();
    static FacadeOperationResult InvaidParams();
    static FacadeOperationResult TranslationLimit();
    static FacadeOperationResult ScaleLimit();
private:
    OperationResult result;
    std::string message;
};

#endif // FACADEOPERATIONRESULT_H
