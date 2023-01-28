
#include "AudioPlayerView.h"
#include "AudioPlayerState.h"

AudioPlayerView::AudioPlayerView(AudioPlayerState& stateToUse)
    : state(stateToUse)
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

    state.addChangeListener(this);
    update();
}

AudioPlayerView::~AudioPlayerView()
{
    state.removeChangeListener(this);
}

void AudioPlayerView::changeListenerCallback(juce::ChangeBroadcaster* source)
{
    if (source == &state)
    {
        update();
    }
}

void AudioPlayerView::update()
{
    playingLabel.setText(state.isPlaying ? "Playing" : "Stopped", juce::dontSendNotification);
    loadedLabel.setText(state.hasLoadedFile ? "Loaded" : "No file", juce::dontSendNotification);
}