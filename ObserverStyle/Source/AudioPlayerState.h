#pragma once

struct AudioPlayerState
{
    bool isPlaying = false;
    bool hasLoadedFile = false;

    struct Listener
    {
        virtual void onStateChange(AudioPlayerState newState) = 0;
    };

    struct Broadcaster
    {
        virtual void addStateListener(Listener* listener) = 0;
        virtual void removeStateListener(Listener* listener) = 0;
    };
};
