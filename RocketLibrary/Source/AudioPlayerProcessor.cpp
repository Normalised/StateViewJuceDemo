#include "AudioPlayerProcessor.h"

/**
 * State Handling
 */
rocket::scoped_connection AudioPlayerProcessor::addStateListener(std::function<void(AudioPlayerState)> listener)
{
    auto connection = signal.connect(listener);
    signal(state);
    return connection;
}

/**
 * Actions
 */
void AudioPlayerProcessor::load(juce::File file)
{
    state.hasLoadedFile = file.existsAsFile();
    signal(state);
}

void AudioPlayerProcessor::play()
{
    state.isPlaying = true;
    signal(state);
}

void AudioPlayerProcessor::stop()
{
    state.isPlaying = false;
    signal(state);
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
