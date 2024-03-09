#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Console.h"
#include "IWavModel.h"
#include "WavModel.h"
#include "FileAttributes.h"

class Controller {
private:
        std::string inputFileName;
        std::string outputFileName;
        std::vector<std::string> processList;
        Console* console;

public:
        Controller();
        void setUI(Console* c);
        void run();
};

#endif

