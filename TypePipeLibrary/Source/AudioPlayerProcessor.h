#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_core/juce_core.h>

#include "AudioPlayerState.h"
#include <TypePipe.h>

class AudioPlayerProcessor
{
public:
    void load(juce::File file);
    void play();
    void stop();

    void processAudio(const juce::AudioSourceChannelInfo& bufferToFill);

    norm::Subscription<AudioPlayerState> addStateListener(std::function<void(AudioPlayerState)> listener);

private:
    norm::TypePipe pipe;

    AudioPlayerState state;
};
