
#include "AudioPlayerView.h"

AudioPlayerView::AudioPlayerView(AudioPlayerProcessor& processorToUse) : processor(processorToUse)
{
    playButton.onClick = [this]()
    {
        onPlay();
    };

    stopButton.onClick = [this]()
    {
        onStop();
    };

    loadButton.onClick = [this]()
    {
        onLoad();
    };

    addAndMakeVisible(playButton);
    addAndMakeVisible(stopButton);
    addAndMakeVisible(loadButton);

    playButton.setBounds(10, 10, 180, 40);
    stopButton.setBounds(200, 10, 180, 40);
    loadButton.setBounds(390, 10, 180, 40);

    addAndMakeVisible(playingLabel);
    addAndMakeVisible(loadedLabel);

    playingLabel.setBounds(10, 100, 200, 40);
    loadedLabel.setBounds(250, 100, 200, 40);

    processor.addChangeListener(this);
    update();
}

AudioPlayerView::~AudioPlayerView()
{
    processor.removeChangeListener(this);
}

void AudioPlayerView::changeListenerCallback(juce::ChangeBroadcaster* source)
{
    if (source == &processor)
    {
        update();
    }
}

void AudioPlayerView::update() {
    auto newState = processor.getState();
    playingLabel.setText(newState.isPlaying ? "Playing" : "Stopped", juce::dontSendNotification);
    loadedLabel.setText(newState.hasLoadedFile ? "Loaded" : "No file", juce::dontSendNotification);
}