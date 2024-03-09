
#include "LowPass.h"

LowPass::LowPass() {
    cutoff = 0.1;
    buf0 = 0;
    buf1 = 0;
}

std::vector<float> LowPass::Process(const std::vector<float>& input) {

    for (int i = 0; i < input.size(); ++i) {
        //Second Order Digital LP filter
        buf0 += cutoff * (input[i] - buf0);
        buf1 += cutoff * (buf0 - buf1);
        output.push_back(buf1);
    }
    
    return output;
}

LowPass::~LowPass() {}
