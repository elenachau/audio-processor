
#ifndef PROJECT_HIGHPASS_H
#define PROJECT_HIGHPASS_H

#include "SignalProcessor.h"
#include <vector>
#include <iostream>

class HighPass: public SignalProcessor{
private:
    std::vector<float> output;
    float cutoff;
    float buf0;
    float buf1;
    float buf2;

public:
    HighPass();
    virtual ~HighPass();

    std::vector<float> Process(const std::vector<float>& input) override;
};


#endif //PROJECT_HIGHPASS_H