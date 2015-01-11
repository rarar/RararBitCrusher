/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
RararBitCrusherAudioProcessorEditor::RararBitCrusherAudioProcessorEditor (RararBitCrusherAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter)
{
    // This is where our plugin's editor size is set.
    setSize (400, 300);
    bitRateKnob.setBounds(50, 10, 200, 200);
    bitRateKnob.setSliderStyle(Slider::SliderStyle::Rotary);
    bitRateKnob.setRange(0.0, 1.0);
    bitRateKnob.hideTextBox(true);
    bitRateKnob.addListener(this);
    addAndMakeVisible(&bitRateKnob);
    timerCallback();
    startTimer(50);
    
}

RararBitCrusherAudioProcessorEditor::~RararBitCrusherAudioProcessorEditor()
{
}

//==============================================================================
void RararBitCrusherAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("RARAR Super Simplistic Bit Crusher",
                      0, 100, getWidth(), getHeight(),
                      Justification::centred, 1);
}

void RararBitCrusherAudioProcessorEditor::resized() {
    
}

void RararBitCrusherAudioProcessorEditor::sliderValueChanged(Slider* sliderThatChanged) {
    if (sliderThatChanged == &bitRateKnob) {
        RararBitCrusherAudioProcessor* theProcessor = getAudioProcessorAsSubclass();
        theProcessor->setParameterNotifyingHost(theProcessor->bitRateParam, bitRateKnob.getValue());
    }
}

void RararBitCrusherAudioProcessorEditor::timerCallback() {
    RararBitCrusherAudioProcessor* proc = getAudioProcessorAsSubclass();
    bitRateKnob.setValue(proc->getParameter(proc->bitRateParam), dontSendNotification);
}