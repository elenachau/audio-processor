//
// Created by trentr on 5/4/22.
//

#ifndef S22_SEMESTER_PROJECT_RILEY_AND_CHAU_WAVMODEL_H
#define S22_SEMESTER_PROJECT_RILEY_AND_CHAU_WAVMODEL_H

#include "IWavModel.h"
#include "WavReader.h"
#include "FileAttributes.h"
#include "wavHeader.h"
#include "SignalProcessor.h"
#include "Echo.h"
#include "Normalizer.h"
#include "Reverse.h"
#include "WavWriter.h"
#include "LowPass.h"
#include "HighPass.h"
#include "BassBooster.h"
#include <vector>
#include <iostream>


class WavModel: public IWavModel {
private:
    std::vector<float> soundData;
    wav_hdr wavHeader;
    std::string outputFileName;
public:
    WavModel();
    ~WavModel(){}
    FileAttributes openFile(const std::string &fileName) override;
    std::vector<std::string> getProcessList() override;
    void processFile(const std::string& processID, const std::string& outputFileName) override;
    std::vector<float> getSoundData();

};


#endif //S22_SEMESTER_PROJECT_RILEY_AND_CHAU_WAVMODEL_H
