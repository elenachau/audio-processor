//
// Created by trentr on 5/4/22.
//

#ifndef S22_SEMESTER_PROJECT_RILEY_AND_CHAU_FILEATTRIBUTES_H
#define S22_SEMESTER_PROJECT_RILEY_AND_CHAU_FILEATTRIBUTES_H

#include <string>

struct FileAttributes{
    std::string fileName;
    int sampleRate;
    short bitsPerSample;
    short numChannels;
    short numSeconds;
};

#endif //S22_SEMESTER_PROJECT_RILEY_AND_CHAU_FILEATTRIBUTES_H
