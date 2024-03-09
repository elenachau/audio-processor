//
// Created by trentr on 5/4/22.
//

#include "WavReader.h"

WavReader::WavReader() {}

wav_hdr WavReader::readFile(const std::string &fileName)
{
    wav_hdr wavHeader;
    std::vector<float> soundData;
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    if(file.is_open())
    {
        file.read((char *) &wavHeader, sizeof(wav_hdr));
        if(wavHeader.bit_depth == 8.0)//This works
        {
            unsigned char* buffer = nullptr;
            buffer = new unsigned char[wavHeader.data_bytes];
            file.read((char *) buffer, wavHeader.data_bytes);
            for(int i = 0; i < wavHeader.data_bytes; i++)
            {
                float scaled = ((2 * buffer[i] / 255.0) - 1.0);
                soundData.push_back(scaled);
            }
            delete[] buffer;
        }
        else if(wavHeader.bit_depth == 16.0)//Works
        {
            short* buffer = nullptr;
            buffer = new short[wavHeader.data_bytes];
            file.read((char *) buffer, wavHeader.data_bytes);
            for(int i = 0; i < wavHeader.data_bytes / 2.0; i++)
            {
                soundData.push_back((float) buffer[i] / 32768.0);
            }
            delete[] buffer;
        }
        file.close();
    }
    else
    {
        throw std::logic_error("File not found, please try again.");
    }
    return wavHeader;
}

std::vector<float> WavReader::readFileData(const std::string &fileName)
{
    wav_hdr wavHeader;
    std::vector<float> soundData;
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    if(file.is_open())
    {
        file.read((char *) &wavHeader, sizeof(wav_hdr));
        if(wavHeader.bit_depth == 8.0)//This works
        {
            unsigned char* buffer = nullptr;
            buffer = new unsigned char[wavHeader.data_bytes];
            file.read((char *) buffer, wavHeader.data_bytes);
            for(int i = 0; i < wavHeader.data_bytes; i++)
            {
                float scaled = ((2 * buffer[i] / 255.0) - 1.0);
                soundData.push_back(scaled);
            }
            delete[] buffer;
        }
        else if(wavHeader.bit_depth == 16.0)//Works
        {
            short* buffer = nullptr;
            buffer = new short[wavHeader.data_bytes];
            file.read((char *) buffer, wavHeader.data_bytes);
            for(int i = 0; i < wavHeader.data_bytes / 2.0; i++)
            {
                soundData.push_back((float) buffer[i] / 32768.0);
            }
            delete[] buffer;
        }
        file.close();
    }
    else
    {
        throw std::logic_error("File not found, please try again.");
    }
    return soundData;
}