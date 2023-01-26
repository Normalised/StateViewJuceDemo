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

    /**
     * State Broadcaster stuff
     */
    void addStateListener(AudioPlayerState::Listener* listener) override;
    void removeStateListener(AudioPlayerState::Listener* listener) override;

    juce::ListenerList<AudioPlayerState::Listener> listeners;

private:
    void sendStateChange();

    AudioPlayerState state;
};
