
#include "HighPass.h"

HighPass::HighPass() {
    cutoff = 0.3;
    buf0 = 0;
    buf1 = 0;
    buf2 = 0;
}

std::vector<float> HighPass::Process(const std::vector<float>& input) {

    for (int i = 0; i < input.size(); ++i) {
        //Second Order Digital HP filter (12 dB/Octave attenuation)
        buf0 += cutoff * (input[i] - buf0);
        buf1 += cutoff * (buf0 - buf1);
        buf2 = input[i] - buf1;
        output.push_back(buf2);
    }
    
    return output;
}

HighPass::~HighPass() {}