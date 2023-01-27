# State -> View Notification Juce Demo Apps

This is a collection of small demo apps to show the basics of *State Change Notification* 
and how to decouple the UI from the other parts of the application.

Each app is based around a single technique or library and is buildable via CMake on its own.

1. Juce Listener List

This uses plain JUCE only and demonstrates a simple implementation of the Observer pattern using a Listener / Broadcaster pair of interfaces along with the JUCE ListenerList class.

2. Rocket Library

This uses the [rocket library](https://github.com/tripleslash/rocket) which is a signals / slots implementation.

3. RxCpp Library

This uses the [rxcpp library](http://reactivex.io/RxCpp/) which is an RX / Reactive Streams implementation.
