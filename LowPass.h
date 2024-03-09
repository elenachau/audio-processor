
#ifndef PROJECT_LOWPASS_H
#define PROJECT_LOWPASS_H

#include "SignalProcessor.h"
#include <vector>
#include <iostream>

class LowPass: public SignalProcessor{
private:
    std::vector<float> output;
    float cutoff;
    float buf0;
    float buf1;

public:
    LowPass();
    virtual ~LowPass();

    std::vector<float> Process(const std::vector<float>& input) override;
};


#endif //PROJECT_LOWPASS_H