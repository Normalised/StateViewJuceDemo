
#include "AudioPlayerView.h"

AudioPlayerView::AudioPlayerView(AudioPlayerProcessor& processorToUse) : processor(processorToUse)
{
    playButton.onClick = [this]()
    {
        processor.play();
    };

    stopButton.onClick = [this]()
    {
        processor.stop();
    };

    loadButton.onClick = [this]()
    {
        fileChooser = std::make_unique<juce::FileChooser>("Choose an audio file");
        auto flags = juce::FileBrowserComponent::canSelectFiles | juce::FileBrowserComponent::openMode;

        fileChooser->launchAsync(flags,
                                 [this](const juce::FileChooser& chooser)
                                 {
            processor.load(chooser.getResult());
        });
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
    playingLabel.setText(processor.isPlaying() ? "Playing" : "Stopped", juce::dontSendNotification);
    loadedLabel.setText(processor.hasLoadedFile() ? "Loaded" : "No file", juce::dontSendNotification);
}