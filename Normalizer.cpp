//
// Created by trentr on 4/7/22.
//

#include "Normalizer.h"

std::vector<float> Normalizer::Process(const std::vector<float> &input)
{
    float largestNum = 0.0;
    float smallestNum = 0.0;
    float newMax;
    for(int i = 0;i < input.size(); i++)
    {
        if(largestNum < input[i])
        {
            largestNum = input[i];
        }
        if(smallestNum > input[i])
        {
            smallestNum = input[i];
        }
    }
    if(smallestNum * -1.0 > largestNum)
    {
        newMax = -1.0/smallestNum;
    }
    else if(largestNum > smallestNum)
    {
        newMax = 1.0/largestNum;
    }
    else
    {
        newMax = 1.0;
    }

    for(int i = 0; i < input.size(); i++)
    {
        output.push_back(input[i]);
        output[i] *= newMax;
    }
    return output;
}