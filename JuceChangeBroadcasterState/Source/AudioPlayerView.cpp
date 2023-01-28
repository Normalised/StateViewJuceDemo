
#include "AudioPlayerView.h"
#include "AudioPlayerState.h"

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
    // Now the change broadcaster is the state, again if we don't have a pointer
    // to it, we have to dynamic cast to check the type.
    if (auto newState = dynamic_cast<AudioPlayerState*>(source))
    {
        playingLabel.setText(newState->isPlaying ? "Playing" : "Stopped", juce::dontSendNotification);
        loadedLabel.setText(newState->hasLoadedFile ? "Loaded" : "No file", juce::dontSendNotification);
    }
}
