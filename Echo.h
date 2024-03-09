//
// Created by trentr on 4/7/22.
//

#ifndef PROJECT_ECHO_H
#define PROJECT_ECHO_H

#include "SignalProcessor.h"
#include <math.h>
#include <vector>


class Echo: public SignalProcessor{
private:
    std::vector<float> output;
public:
    Echo() {}
    ~Echo() {}
    std::vector<float> Process(const std::vector<float>& input) override;

};


#endif //PROJECT_ECHO_H
