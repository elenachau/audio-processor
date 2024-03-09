//
// Created by trentr on 4/7/22.
//

#ifndef PROJECT_SIGNALPROCESSOR_H
#define PROJECT_SIGNALPROCESSOR_H

#include <vector>

class SignalProcessor {
public:
    SignalProcessor(){}
    virtual ~SignalProcessor() {}
    virtual std::vector<float> Process(const std::vector<float>& input) = 0;

};


#endif //PROJECT_SIGNALPROCESSOR_H
