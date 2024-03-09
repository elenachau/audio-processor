//
// Created by trentr on 4/7/22.
//

#include "Echo.h"


std::vector<float> Echo::Process(const std::vector<float>& input)
{
    float gain = 0.8;
    int delay = 50000;
    std::vector<float> output;
    auto decay = log(0.001) / log(gain); //tells us how long for the last sample to diminish to a point. -3 works too so meh. If last sample is 1, then could be (((((1 * .5).5).5).5), 1 * .5^4. How many times does it echo before it gets to .001?
    int new_size = int(input.size() + delay * decay); //Stops when almost silent. To find out how long this new vector needs to be.
    std::vector<float> extendedInput(new_size, 0.0f);
    extendedInput.insert(extendedInput.begin(), input.begin(), input.end());
    output.reserve(extendedInput.size());
    for(int i = 0; i < new_size; i++)
    {
        if(i > delay)
        {
            output.push_back(extendedInput[i] + gain * output[i - delay]);
        }
        else
        {
            output.push_back(extendedInput[i]);
        }
    }
    //Shameless copy of normalizer so the output doesn't destroy your ears.
    float largestNum = 0.0;
    float smallestNum = 0.0;
    float newMax;
    for(int i = 0;i < output.size(); i++)
    {
        if(largestNum < output[i])
        {
            largestNum = output[i];
        }
        if(smallestNum > output[i])
        {
            smallestNum = output[i];
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

    for(int i = 0; i < output.size(); i++)
    {
        output[i] *= newMax;
    }
    return output;
}
