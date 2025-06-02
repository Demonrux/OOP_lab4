#ifndef FILEREADER_H
#define FILEREADER_H

#include "normalizationparameters.h"
#include "basefilereader.h"

class FileReader: public BaseFileReader {
public:
    std::unique_ptr<Scene> ReadScene(std::filesystem::path path, NormalizationParameters params) override;
};

#endif // FILEREADER_H
