#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_core/juce_core.h>

#include "AudioPlayerState.h"
#include <rocket.hpp>

class AudioPlayerProcessor
{
public:
    void load(juce::File file);
    void play();
    void stop();

    rocket::scoped_connection addStateListener(std::function<void(AudioPlayerState)> listener);

    void processAudio(const juce::AudioSourceChannelInfo& bufferToFill);

private:
    void sendStateChange();
    rocket::thread_safe_signal<void(AudioPlayerState)> signal;
    AudioPlayerState state;
};
