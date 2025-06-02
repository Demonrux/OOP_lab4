#ifndef NORMALIZATIONPARAMETERS_H
#define NORMALIZATIONPARAMETERS_H

class NormalizationParameters {
public:
    double max;
    double min;
    double step;
    NormalizationParameters(double max, double min, double step);
};

#endif // NORMALIZATIONPARAMETERS_H
