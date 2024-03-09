//
// Created by trentr on 5/4/22.
//

#ifndef S22_SEMESTER_PROJECT_RILEY_AND_CHAU_WAVWRITER_H
#define S22_SEMESTER_PROJECT_RILEY_AND_CHAU_WAVWRITER_H

#include <vector>
#include <algorithm>
#include <fstream>
#include "wavHeader.h"

class WavWriter {
public:
    void writeFile(std::vector<float> soundData, std::string fileName, wav_hdr wavHeader);

};


#endif //S22_SEMESTER_PROJECT_RILEY_AND_CHAU_WAVWRITER_H
