#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_core/juce_core.h>
#include <juce_events/juce_events.h>

struct AudioPlayerState
{
    bool isPlaying = false;
    bool hasLoadedFile = false;
};

class AudioPlayerProcessor : public juce::ChangeBroadcaster
{
public:
    void load(juce::File file);
    void play();
    void stop();

    void processAudio(const juce::AudioSourceChannelInfo& bufferToFill);

    bool isPlaying();
    bool hasLoadedFile();

private:
    void sendStateChange();

    AudioPlayerState state;
};
