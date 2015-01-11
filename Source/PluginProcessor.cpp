/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
RararBitCrusherAudioProcessor::RararBitCrusherAudioProcessor() : bitRate(1.0)
{
}

RararBitCrusherAudioProcessor::~RararBitCrusherAudioProcessor()
{
}

//==============================================================================
const String RararBitCrusherAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int RararBitCrusherAudioProcessor::getNumParameters()
{
    return totalNumberOfParams;
}

float RararBitCrusherAudioProcessor::getParameter (int index)
{
    switch (index) {
        case bitRateParam:
            return bitRate;
            break;
            
        default:
            return 0.0f;
            break;
    }
    
}

void RararBitCrusherAudioProcessor::setParameter (int index, float newValue)
{
    switch (index) {
        case bitRateParam:   setBitRate(newValue); break;
            
        default:
            break;
    }
}

const String RararBitCrusherAudioProcessor::getParameterName (int index)
{
    switch (index) {
        case bitRateParam: return "Bit Rate";
            
        default: return String::empty;
    }
}

const String RararBitCrusherAudioProcessor::getParameterText (int index)
{
    switch (index) {
        case bitRateParam: return String((bitRate * 4094) + 2);
            
        default: return String::empty;
    }
}

const String RararBitCrusherAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String RararBitCrusherAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool RararBitCrusherAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool RararBitCrusherAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool RararBitCrusherAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool RararBitCrusherAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool RararBitCrusherAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double RararBitCrusherAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int RararBitCrusherAudioProcessor::getNumPrograms()
{
    return 0;
}

int RararBitCrusherAudioProcessor::getCurrentProgram()
{
    return 0;
}

void RararBitCrusherAudioProcessor::setCurrentProgram (int index)
{
}

const String RararBitCrusherAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void RararBitCrusherAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void RararBitCrusherAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void RararBitCrusherAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void RararBitCrusherAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    BitCrusher bitCrusher;

    bitCrusher.bitRate = (bitRate - 0) * (4096 - 1024) / (1.0 - 0) + 1024; // custom map() function to scale 0.0-1.0 to 1024-4096
    std::cout << "bit rate = " << bitCrusher.bitRate << std::endl;
    bitCrusher.processSampleBuffer(buffer);

    
    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
bool RararBitCrusherAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* RararBitCrusherAudioProcessor::createEditor()
{
    return new RararBitCrusherAudioProcessorEditor (this);
}

//==============================================================================
void RararBitCrusherAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void RararBitCrusherAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RararBitCrusherAudioProcessor();
}

void RararBitCrusherAudioProcessor::setBitRate(float newBitRate) {
    bitRate = jlimit<float>(0.0, 1.0, newBitRate); // set bitRate field based on slider value
}
