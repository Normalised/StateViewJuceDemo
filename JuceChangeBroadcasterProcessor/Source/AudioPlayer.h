#pragma once

#include "AudioPlayerProcessor.h"
#include "AudioPlayerView.h"
#include <memory>

struct AudioPlayer
{
    AudioPlayer()
    {
        view.onPlay = [this]()
        {
            processor.play();
        };

        view.onStop = [this]()
        {
            processor.stop();
        };

        view.onLoad = [this]()
        {
            chooseFile();
        };

        processor.addChangeListener(&view);
        /**
         * Processor doesn't know when a listener is connected so can't
         * send the initial state update
         */
        processor.sendChangeMessage();
    }

    void chooseFile()
    {
        fileChooser = std::make_unique<juce::FileChooser>("Choose an audio file");
        auto flags = juce::FileBrowserComponent::canSelectFiles | juce::FileBrowserComponent::openMode;

        fileChooser->launchAsync(flags,
                                 [this](const juce::FileChooser& chooser)
                                 {
            processor.load(chooser.getResult());
        });
    }

    ~AudioPlayer()
    {
        processor.removeChangeListener(&view);
    }

    AudioPlayerProcessor processor;
    AudioPlayerView view;

private:
    std::unique_ptr<juce::FileChooser> fileChooser;
};
