//
// Created by trentr on 4/29/22.
//

#include "Reverse.h"

std::vector<float> Reverse::Process(const std::vector<float> &input)
{
    std::vector<float> output;
    for(int i = 0; i < input.size(); i++)
    {
        output.push_back(input[i]);
    }
    std::reverse(output.begin(),output.end());
    return output;
}