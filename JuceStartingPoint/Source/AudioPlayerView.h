#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include "AudioPlayerProcessor.h"

class AudioPlayerView
    : public juce::Component
    , public juce::ChangeListener
{
public:
    AudioPlayerView(AudioPlayerProcessor& processorToUse);
    ~AudioPlayerView() override;

    void changeListenerCallback(juce::ChangeBroadcaster* source) override;

private:
    void update();

    std::unique_ptr<juce::FileChooser> fileChooser;

    AudioPlayerProcessor& processor;

    juce::TextButton playButton{"Play"};
    juce::TextButton stopButton{"Stop"};
    juce::TextButton loadButton{"Load"};

    juce::Label playingLabel;
    juce::Label loadedLabel;
};
