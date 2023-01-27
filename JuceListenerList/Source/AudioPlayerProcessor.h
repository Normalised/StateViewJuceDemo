#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_core/juce_core.h>

#include "AudioPlayerState.h"

class AudioPlayerProcessor : public AudioPlayerState::Broadcaster
{
public:
    void load(juce::File file);
    void play();
    void stop();

    void processAudio(const juce::AudioSourceChannelInfo& bufferToFill);

    void addStateListener(AudioPlayerState::Listener* listener) override;
    void removeStateListener(AudioPlayerState::Listener* listener) override;

private:
    void sendStateChange();

    juce::ListenerList<AudioPlayerState::Listener> listeners;

    AudioPlayerState state;
};
