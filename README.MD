# State -> View Notification Juce Demo Apps

This is a collection of small demo apps to show the basics of *State Change Notification* 
and how to decouple the UI from the other parts of the application.

Each app is based around a single technique or library and is buildable via CMake on its own.

1. Juce Change Broadcaster - Processor

This uses the JUCE Change Broadcaster class and makes the Processor the broadcaster.

2. Juce Change Broadcaster - State

This uses the JUCE Change Broadcaster class and makes the State broadcast changes.

3. Juce Listener List

This uses a JUCE Listener List and a Listener / Broadcaster pair of interfaces.

4. Rocket Library

This uses the [rocket library](https://github.com/tripleslash/rocket) which is a signals / slots implementation.

5. RxCpp Library

This uses the [rxcpp library](http://reactivex.io/RxCpp/) which is an RX / Reactive Streams implementation.


## App Structure

The 4 objects involved are

1. AudioPlayerProcessor

This is where the DSP happens. (There is no actual DSP code, but it would be here if there was)

2. AudioPlayerView

The UI. Contains buttons and labels. Button click actions are used to invoke named lambdas such as *onPlay* which another object can bind to.

3. AudioPlayerState

The state of the Processor but made into its own external state object. Owned by the Processor.

4. AudioPlayer

This owns both the Processor and View and glues them together. View events become actions which act on the processor.

## Notes

The Main.cpp and MainComponent files are just JUCE setup and are identical in every demo app.