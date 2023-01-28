#pragma once

#include <juce_events/juce_events.h>

struct AudioPlayerState : public juce::ChangeBroadcaster
{
    bool isPlaying = false;
    bool hasLoadedFile = false;

    void setPlaying(bool playing)
    {
        isPlaying = playing;
        sendChangeMessage();
    }

    void setLoaded(bool loaded)
    {
        hasLoadedFile = loaded;
        sendChangeMessage();
    }
};
