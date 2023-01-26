#include "AudioPlayerProcessor.h"

/**
 * State Handling
 */
void AudioPlayerProcessor::sendStateChange()
{
    signal(state);
}

rocket::scoped_connection AudioPlayerProcessor::addStateListener(std::function<void(AudioPlayerState)> listener)
{
    auto connection = signal.connect(listener);
    sendStateChange();
    return connection;
}

/**
 * Actions
 */
void AudioPlayerProcessor::load(juce::File file)
{
    state.hasLoadedFile = file.existsAsFile();
    sendStateChange();
}

void AudioPlayerProcessor::play()
{
    state.isPlaying = true;
    sendStateChange();
}

void AudioPlayerProcessor::stop()
{
    state.isPlaying = false;
    sendStateChange();
}

/**
 * DSP
 */
void AudioPlayerProcessor::processAudio(const juce::AudioSourceChannelInfo& bufferToFill)
{
    if(state.hasLoadedFile && state.isPlaying) {
        // Play the audio
    }
}
