//
// Created by trentr on 4/7/22.
//

#ifndef PROJECT_NORMALIZER_H
#define PROJECT_NORMALIZER_H

#include "SignalProcessor.h"
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

class Normalizer: public SignalProcessor{
private:
    std::vector<float> output;
public:
    Normalizer(){}
    ~Normalizer(){}
    std::vector<float> Process(const std::vector<float>& input) override;

};


#endif //PROJECT_NORMALIZER_H
