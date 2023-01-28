#include "AudioPlayerProcessor.h"

/**
 * State
 */
AudioPlayerState& AudioPlayerProcessor::getState()
{
    return state;
}

/**
 * Actions
 */
void AudioPlayerProcessor::load(juce::File file)
{
    state.hasLoadedFile = file.existsAsFile();
    state.sendChangeMessage();
}

void AudioPlayerProcessor::play()
{
    state.isPlaying = true;
    state.sendChangeMessage();
}

void AudioPlayerProcessor::stop()
{
    state.isPlaying = false;
    state.sendChangeMessage();
}

/**
 * DSP
 */
void AudioPlayerProcessor::processAudio(const juce::AudioSourceChannelInfo& bufferToFill)
{
    if (state.hasLoadedFile && state.isPlaying)
    {
        // Play the audio
    }
}
