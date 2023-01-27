#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_core/juce_core.h>

#include "AudioPlayerState.h"
#include <rxcpp/rx.hpp>

class AudioPlayerProcessor
{
public:
    void load(juce::File file);
    void play();
    void stop();

    void processAudio(const juce::AudioSourceChannelInfo& bufferToFill);

    rxcpp::composite_subscription addStateListener(std::function<void(AudioPlayerState)> listener);

private:

    void notifyStateChange();

    rxcpp::subjects::subject<AudioPlayerState> stateSubject;

    AudioPlayerState state;
};
