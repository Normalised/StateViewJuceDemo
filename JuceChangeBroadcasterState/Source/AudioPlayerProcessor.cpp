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
    state.setLoaded(file.existsAsFile());
}

void AudioPlayerProcessor::play()
{
    state.setPlaying(true);
}

void AudioPlayerProcessor::stop()
{
    state.setPlaying(false);
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
