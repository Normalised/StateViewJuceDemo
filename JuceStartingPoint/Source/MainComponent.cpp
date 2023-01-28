#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize(800, 600);
    addAndMakeVisible(audioPlayerView);
}

void MainComponent::resized()
{
    audioPlayerView.setBounds(0, 0, 800, 600);
}

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
}

void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    audioPlayerProcessor.processAudio(bufferToFill);
}

void MainComponent::releaseResources()
{
}