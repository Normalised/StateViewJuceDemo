#include "AudioPlayerProcessor.h"

/**
 * State Handling
 */
norm::Subscription<AudioPlayerState> AudioPlayerProcessor::addStateListener(std::function<void(AudioPlayerState)> listener)
{
    auto subscription = pipe.add(listener);
    pipe.send(state);
    return subscription;
}

/**
 * Actions
 */
void AudioPlayerProcessor::load(juce::File file)
{
    state.hasLoadedFile = file.existsAsFile();
    pipe.send(state);
}

void AudioPlayerProcessor::play()
{
    state.isPlaying = true;
    pipe.send(state);
}

void AudioPlayerProcessor::stop()
{
    state.isPlaying = false;
    pipe.send(state);
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
