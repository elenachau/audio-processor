
#include "BassBooster.h"

BassBooster::BassBooster() {
    cutoff = 0.2;
    amplify = 5;
    buf0 = 0;
    buf1 = 0;
    buf2 = 0;
}

std::vector<float> BassBooster::Process(const std::vector<float>& input) {

    for (int i = 0; i < input.size(); ++i) {
        //A bandpass filter with a low center frequency, the amplitude is increased to 'boost the bass'
        buf0 += cutoff * ((input[i]*amplify) - buf0);
        buf1 += cutoff * (buf0 - buf1);
        buf2 = buf0-buf1;
        output.push_back(buf2);
    }
    
    return output;
}

BassBooster::~BassBooster() {}
