/*
  ==============================================================================

    BitCrusher.h
    Created: 10 Dec 2013 11:49:11pm
    Author:  Raphael Arar

  ==============================================================================
*/

#ifndef BITCRUSHER_H_INCLUDED
#define BITCRUSHER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class BitCrusher {
    
public:
    int bitRate; // bit rate field
    int bitDepth; // bit depth field
    
    BitCrusher(void);
    ~BitCrusher(void);
    
    void processSampleBuffer(AudioSampleBuffer &buffer); // main processing block
};


#endif  // BITCRUSHER_H_INCLUDED
