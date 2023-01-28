#include "AudioPlayerProcessor.h"

/**
 * State
 */
bool AudioPlayerProcessor::isPlaying()
{
    return state.isPlaying;
}

bool AudioPlayerProcessor::hasLoadedFile()
{
    return state.hasLoadedFile;
}

/**
 * Actions
 */
void AudioPlayerProcessor::load(juce::File file)
{
    state.hasLoadedFile = file.existsAsFile();
    sendChangeMessage();
}

void AudioPlayerProcessor::play()
{
    state.isPlaying = true;
    sendChangeMessage();
}

void AudioPlayerProcessor::stop()
{
    state.isPlaying = false;
    sendChangeMessage();
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
