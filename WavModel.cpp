//
// Created by trentr on 5/4/22.
//

#include "WavModel.h"

WavModel::WavModel() {}

FileAttributes WavModel::openFile(const std::string &fileName)
{
    WavReader* wavReader;
    wavHeader = wavReader -> readFile(fileName);
    soundData = wavReader -> readFileData(fileName); //Was having trouble getting back both the header and sound vector for the file attributes struct.
    FileAttributes fileAttributes;
    fileAttributes.fileName = fileName;
    fileAttributes.bitsPerSample = wavHeader.bit_depth;
    fileAttributes.numChannels = wavHeader.num_channels;
    fileAttributes.sampleRate = wavHeader.sample_rate;
    fileAttributes.numSeconds = static_cast<float>(wavHeader.data_bytes/wavHeader.byte_rate);
    return fileAttributes;

}

std::vector<std::string> WavModel::getProcessList()
{
    return std::vector<std::string> {"Echo", "Normalization", "Reverse", "LowPass", "HighPass", "BassBooster"};
}

void WavModel::processFile(const std::string &processID, const std::string &outputFileName)
{
    for(int i = 0; i < 1; i++)
    {
        if(processID == "Normalize")
        {
            SignalProcessor *s = new Normalizer();
            soundData = s -> Process(WavModel::getSoundData());
        }
        else if(processID == "Echo")
        {
            SignalProcessor *s = new Echo();
            soundData = s -> Process(WavModel::getSoundData());
        }
        else if(processID == "Reverse")
        {
            SignalProcessor *s = new Reverse();
            soundData = s -> Process(WavModel::getSoundData());
        }
        else if(processID == "LowPass")
        {
            SignalProcessor *s = new LowPass();
            soundData = s -> Process(WavModel::getSoundData());
        }
        else if(processID == "HighPass")
        {
            SignalProcessor *s = new HighPass();
            soundData = s -> Process(WavModel::getSoundData());
        }
        else if(processID == "BassBooster")
        {
            SignalProcessor *s = new BassBooster();
            soundData = s -> Process(WavModel::getSoundData());
        }
    }
    WavWriter* wavWriter;
    wavWriter ->writeFile(soundData, outputFileName, wavHeader);

}

std::vector<float> WavModel::getSoundData()
{
    return soundData;
}
