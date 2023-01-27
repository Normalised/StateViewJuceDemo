#include "AudioPlayerProcessor.h"

/**
 * State Handling
 */
void AudioPlayerProcessor::notifyStateChange()
{
    stateSubject.get_subscriber().on_next(state);
}

rxcpp::composite_subscription AudioPlayerProcessor::addStateListener(std::function<void(AudioPlayerState)> listener)
{
    auto subscription = stateSubject.get_observable().subscribe(listener);
    notifyStateChange();
    return subscription;
}

/**
 * Actions
 */
void AudioPlayerProcessor::load(juce::File file)
{
    state.hasLoadedFile = file.existsAsFile();
    notifyStateChange();
}

void AudioPlayerProcessor::play()
{
    state.isPlaying = true;
    notifyStateChange();
}

void AudioPlayerProcessor::stop()
{
    state.isPlaying = false;
    notifyStateChange();
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
