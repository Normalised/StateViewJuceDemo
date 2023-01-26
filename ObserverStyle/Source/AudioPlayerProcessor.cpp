#include "AudioPlayerProcessor.h"

/**
 * State Handling
 */
void AudioPlayerProcessor::sendStateChange()
{
    listeners.call(
        [this](AudioPlayerState::Listener& l)
        {
        l.onStateChange(state);
    });
}

void AudioPlayerProcessor::addStateListener(AudioPlayerState::Listener* listener)
{
    listeners.add(listener);
    // Notify the new listener so it has the current state
    listener->onStateChange(state);
}

void AudioPlayerProcessor::removeStateListener(AudioPlayerState::Listener* listener)
{
    listeners.remove(listener);
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
