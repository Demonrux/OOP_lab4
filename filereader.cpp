#include "filereader.h"
#include "figure.h"

std::unique_ptr<Scene> FileReader::ReadScene(std::filesystem::path path, NormalizationParameters params) {
    auto scene = std::make_unique<Scene>();
    std::string line;

    std::ifstream in(path);
    if(in.is_open()) {
        std::vector<std::vector<float>> input;

        while (std::getline(in, line)) {
            std::vector<float> lineNums;
            std::stringstream ss(line);
            std::string element;

            while (getline(ss, element, Constants::SEPARATOR)) {
                lineNums.push_back(std::stof(element));
            }
            input.push_back(lineNums);
        }

        float min = input[0][0];
        float max = input[0][0];
        for (auto& row : input) {
            for (auto& cell : row) {
                if (cell < min) min = cell;
                if (cell > max) max = cell;
            }
        }

        std::vector<Vertex> vertices;
        for (size_t i = 0; i < input.size(); i += params.step) {
            for (size_t j = 0; j < input[i].size(); j += params.step) {
                Point3D point(Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE, Constants::DEFAULT_VALUE);
                point.x = j * params.step;
                point.y = i * params.step;
                point.z = params.min + (input[i][j] - min) / (max - min) * (params.max - params.min);
                vertices.push_back(Vertex(point));
            }
        }

        std::vector<Edge> edges;
        size_t cols = input[0].size();
        for (size_t i = 0; i < input.size() - 1; i += params.step) {
            for (size_t j = 0; j < input[i].size() - 1; j += params.step) {
                size_t currentIdx = (i / params.step) * (cols / params.step) + (j / params.step);
                size_t rightIdx = currentIdx + 1;
                size_t bottomIdx = ((i + params.step) / params.step) * (cols / params.step) + (j / params.step);

                if (j + params.step < input[i].size()) {
                    edges.push_back(Edge(vertices[currentIdx], vertices[rightIdx]));
                }
                if (i + params.step < input.size()) {
                    edges.push_back(Edge(vertices[currentIdx], vertices[bottomIdx]));
                }
            }
        }

        auto figure = std::make_shared<Figure>(vertices, edges);
        scene->getFigures().push_back(figure);
    }

    return scene;
}
