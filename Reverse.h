//
// Created by trentr on 4/29/22.
//

#ifndef S22_SEMESTER_PROJECT_RILEY_AND_CHAU_REVERSE_H
#define S22_SEMESTER_PROJECT_RILEY_AND_CHAU_REVERSE_H

#include "SignalProcessor.h"
#include <vector>
#include <algorithm>


class Reverse: public SignalProcessor{
public:
    Reverse() {}
    ~Reverse() {}
    std::vector<float> Process(const std::vector<float>& input) override;


};


#endif //S22_SEMESTER_PROJECT_RILEY_AND_CHAU_REVERSE_H
