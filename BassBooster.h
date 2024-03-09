
#ifndef PROJECT_BASSBOOSTER_H
#define PROJECT_BASSBOOSTER_H

#include "SignalProcessor.h"
#include <vector>
#include <iostream>

class BassBooster: public SignalProcessor{
private:
    std::vector<float> output;
    float cutoff;
    float buf0;
    float buf1;
    float buf2;
    float amplify;

public:
    BassBooster();
    virtual ~BassBooster();

    std::vector<float> Process(const std::vector<float>& input) override;
};


#endif //PROJECT_BASSBOOSTER_H