#pragma once

#include "AudioPlayerState.h"
#include <juce_gui_basics/juce_gui_basics.h>

class AudioPlayerView : public juce::Component
{
public:
    AudioPlayerView();

    void onStateChange(AudioPlayerState newState);

    std::function<void()> onPlay = []()
    {
    };
    std::function<void()> onStop = []()
    {
    };
    std::function<void()> onLoad = []()
    {
    };

private:
    juce::TextButton playButton{"Play"};
    juce::TextButton stopButton{"Stop"};
    juce::TextButton loadButton{"Load"};

    juce::Label playingLabel;
    juce::Label loadedLabel;
};
