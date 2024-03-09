//
// Created by trentr on 4/7/22.
//

#ifndef PROJECT_CONSOLE_H
#define PROJECT_CONSOLE_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "FileAttributes.h"


class Console {
private:
    std::string fileName;
public:
    Console();
    std::string getInputFileName();
    void displayAttributes(FileAttributes fileAttributes);
    void displayProcesses(std::vector<std::string>& processList);
    std::string getSelection();
    std::string getOutputFileName();

};


#endif //PROJECT_CONSOLE_H
