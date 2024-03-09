//
// Created by trentr on 5/4/22.
//

#ifndef S22_SEMESTER_PROJECT_RILEY_AND_CHAU_WAVREADER_H
#define S22_SEMESTER_PROJECT_RILEY_AND_CHAU_WAVREADER_H

#include <fstream>
#include <vector>
#include <iostream>
#include "wavHeader.h"

class WavReader {
private:
public:
    WavReader ();
    wav_hdr readFile(const std::string &fileName);
    std::vector<float> readFileData(const std::string &fileName);

};


#endif //S22_SEMESTER_PROJECT_RILEY_AND_CHAU_WAVREADER_H
