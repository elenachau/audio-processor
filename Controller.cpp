

#include "Controller.h"

Controller::Controller(){}

void Controller::setUI(Console* c)
{
    console = c;
}

void Controller::run()
{
    inputFileName = console -> getInputFileName();
    IWavModel* r = new WavModel();
    FileAttributes fileAttributes = r -> openFile(inputFileName);
    console -> displayAttributes(fileAttributes);
    processList = r -> getProcessList();
    console -> displayProcesses(processList);
    std::string selection = console -> getSelection();
    for(int i = 0; i < processList.size(); i++)
    {
        if(selection != processList[i])
        {
            std::cout << processList[i] << std::endl;
            if(i + 1 == processList.size())
            {
                std::cout << "Invalid process name, try again." << std::endl;
                console -> displayProcesses(processList);
                selection = console -> getSelection();
                i = -1;
            }
        }
        else
        {
            i = processList.size();
        }
    }
    outputFileName = console -> getOutputFileName();
    r -> processFile(selection, outputFileName);
    std::cout << "File processed successfully." << std::endl;
}