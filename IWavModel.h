//
// Created by trentr on 5/4/22.
//

#ifndef S22_SEMESTER_PROJECT_RILEY_AND_CHAU_IWAVMODEL_H
#define S22_SEMESTER_PROJECT_RILEY_AND_CHAU_IWAVMODEL_H

#include "FileAttributes.h"
#include <string>
#include <vector>

class IWavModel{
public:
    virtual FileAttributes openFile(const std::string &fileName) = 0;
    virtual std::vector<std::string> getProcessList() = 0;
    virtual void processFile(const std::string& processID, const std::string& outputFileName) = 0;
};

#endif //S22_SEMESTER_PROJECT_RILEY_AND_CHAU_IWAVMODEL_H
