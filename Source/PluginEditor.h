/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class RararBitCrusherAudioProcessorEditor  : public Timer,
                                             public AudioProcessorEditor,
                                             public Slider::Listener
{
public:
    RararBitCrusherAudioProcessorEditor (RararBitCrusherAudioProcessor* ownerFilter);
    ~RararBitCrusherAudioProcessorEditor();

    //==============================================================================
    // This is just a standard Juce paint method...
    void paint (Graphics& g);
    void resized();
    
    void sliderValueChanged(Slider* sliderThatChanged);
    void timerCallback();
    
private:
    
    Slider bitRateKnob;
    RararBitCrusherAudioProcessor* getAudioProcessorAsSubclass() const
    {
        return static_cast<RararBitCrusherAudioProcessor*>(getAudioProcessor());
    }
};


#endif  // PLUGINEDITOR_H_INCLUDED
