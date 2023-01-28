#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize(800, 600);
    addAndMakeVisible(audioPlayer.view);
}

void MainComponent::resized()
{
    audioPlayer.view.setBounds(0, 0, 800, 600);
}

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
}

void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    audioPlayer.processor.processAudio(bufferToFill);
}

void MainComponent::releaseResources()
{
}