//
// Created by trentr on 5/4/22.
//

#include "WavWriter.h"

void WavWriter::writeFile(std::vector<float> soundData, std::string fileName, wav_hdr wavHeader)
{
    std::ofstream outFile(fileName, std::ios::out | std::ios::binary);

    if(wavHeader.bit_depth == 8.0)//This works
    {
        unsigned char* newBuffer = new unsigned char[soundData.size()];
        for (int i = 0; i < soundData.size(); i++)
        {
            newBuffer[i] = (unsigned char) ((soundData[i] + 1) * 255/2);
        }
        wavHeader.data_bytes = soundData.size();
        wavHeader.wav_size = wavHeader.data_bytes + 44 - 8;
        outFile.write((char *) &wavHeader, sizeof(wav_hdr));
        outFile.write((char *) newBuffer, wavHeader.data_bytes);
    }
    else if(wavHeader.bit_depth == 16.0)//Works
    {
        short* newBuffer = nullptr;
        newBuffer = new short[soundData.size() ];
        for (int i = 0; i < soundData.size(); i++)
        {
            newBuffer[i] = (short) (soundData[i] * 32768.0);
        }
        if(wavHeader.num_channels == 2.0)
        {
            wavHeader.data_bytes = soundData.size() * 2;
        }
        else
        {
            wavHeader.data_bytes = soundData.size() * wavHeader.sample_alignment;
        }
        wavHeader.wav_size = wavHeader.data_bytes + 44 - 8;
        outFile.write((char *) &wavHeader, sizeof(wav_hdr));
        outFile.write((char *) newBuffer, wavHeader.data_bytes);
    }
    outFile.close();
}