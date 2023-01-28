#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_audio_utils/juce_audio_utils.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include "AudioPlayerProcessor.h"
#include "AudioPlayerView.h"

class MainComponent : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();

    //==============================================================================
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void resized() override;

private:
    AudioPlayerProcessor audioPlayerProcessor;
    AudioPlayerView audioPlayerView {audioPlayerProcessor};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
