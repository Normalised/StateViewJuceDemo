#pragma once

#include <juce_events/juce_events.h>

struct AudioPlayerState : public juce::ChangeBroadcaster
{
    bool isPlaying = false;
    bool hasLoadedFile = false;
};
