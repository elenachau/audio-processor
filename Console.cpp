//
// Created by trentr on 4/7/22.
//

#include "Console.h"

Console::Console() {}

std::string Console::getInputFileName()
{
    std::cout << "Enter the name of your .WAV file(including extension): ";
    std::cin >> fileName;
    return fileName;
}

void Console::displayAttributes(FileAttributes fileAttributes)
{
    std::string channels;
    if(fileAttributes.numChannels == 1.0)
    {
        channels = "Mono";
    }
    else
    {
        channels = "Stereo";
    }
    std::cout << "Wav File attributes:" << std::endl;
    std::cout << "Wav filename: " << fileAttributes.fileName << std::endl;
    std::cout << "Wav Sample rate: " << fileAttributes.sampleRate << std::endl;
    std::cout << "Wav bits: " << fileAttributes.bitsPerSample << "-bit" << std::endl;
    std::cout << "Wav Audio type: " << channels << std::endl;
    std::cout << "Wav length: " << std::fixed << std::setprecision(2) << fileAttributes.numSeconds << " second(s)." << std::endl;
}

void Console::displayProcesses(std::vector<std::string>& processList)
{
    std::cout << "Available processes: " << std::endl;
    for(int i = 0; i < processList.size(); i++)
    {
        std::cout << i + 1 << ". " << processList[i] << std::endl;
    }
}

std::string Console::getSelection()
{
    std::string selection;
    std::cout << "Please type the name of the process you want to perform." << std::endl;
    std::cin >> selection;

    return selection;
}

std::string Console::getOutputFileName()
{
    std::cout << "Enter the name of your new .WAV file(including .wav extension): ";
    std::cin >> fileName;
    return fileName;
}