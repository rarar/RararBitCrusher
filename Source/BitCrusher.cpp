/*
  ==============================================================================

    BitCrusher.cpp
    Created: 10 Dec 2013 11:49:11pm
    Author:  Raphael Arar

  ==============================================================================
*/

#include "BitCrusher.h"

BitCrusher::BitCrusher(void) : bitDepth(8), bitRate(4096) // initialize bit depth & bit rate
{
}

BitCrusher::~BitCrusher(void)
{
    
}

void BitCrusher::processSampleBuffer(AudioSampleBuffer &buffer)
{
    int max = pow(2, bitDepth) - 1; // adjust max based on bit depth value
    int step = 44100 / bitRate; // adjust step size based on bit rate
    
    float* leftData = buffer.getSampleData(0);
    float* rightData = buffer.getSampleData(1);
    int i = 0;
    
    // first iterate through buffer
    while (i < buffer.getNumSamples()) {
        
        float leftFirstSample = roundToInt((leftData[i] + 1.0) + max) / max - 1.0; // clip left sample based on max
        float rightFirstSample = roundToInt((rightData[i] + 1.0) + max) / max - 1.0; // clip right sample based on max
        
        // loop through samples based on step size to downsample!
        for (int j = 0; j < step && i < buffer.getNumSamples(); j++) {
            leftData[j] = leftFirstSample;
            rightData[j] = rightFirstSample;
            
            i++;
        }
    }

}