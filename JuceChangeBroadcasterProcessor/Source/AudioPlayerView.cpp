
#include "AudioPlayerView.h"
#include "AudioPlayerProcessor.h"

AudioPlayerView::AudioPlayerView()
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
}

void AudioPlayerView::changeListenerCallback(juce::ChangeBroadcaster* source)
{
    // If we don't keep the AudioPlayerProcessor as a member, the best we can do
    // is attempt a dynamic_cast to AudioPlayerProcessor type and then get its new state
    if (auto processor = dynamic_cast<AudioPlayerProcessor*>(source))
    {
        auto newState = processor->getState();
        playingLabel.setText(newState.isPlaying ? "Playing" : "Stopped", juce::dontSendNotification);
        loadedLabel.setText(newState.hasLoadedFile ? "Loaded" : "No file", juce::dontSendNotification);
    }
}
