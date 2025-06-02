#ifndef BASEFILEREADER_H
#define BASEFILEREADER_H

#include "scene.h"
#include "normalizationparameters.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string.h>

class BaseFileReader {
public:
    virtual ~BaseFileReader() = default;
    virtual std::unique_ptr<Scene> ReadScene(std::filesystem::path path, NormalizationParameters params) = 0;
};

#endif // BASEFILEREADER_H
