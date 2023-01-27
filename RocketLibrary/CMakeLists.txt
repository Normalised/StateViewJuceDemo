cmake_minimum_required(VERSION 3.21)
project(RocketDemo VERSION 0.0.1)

#including CPM.cmake, a package manager:
#https://github.com/TheLartians/CPM.cmake
include(../CMake/CPM.cmake)

#Adds all the module sources so they appear correctly in the IDE
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)
option(JUCE_BUILD_EXTRAS "Build JUCE Extras" OFF)
option(JUCE_BUILD_EXAMPLES "Build JUCE Examples" OFF)

CPMAddPackage(
        NAME JUCE
        GITHUB_REPOSITORY juce-framework/JUCE
        GIT_TAG origin/master)

CPMAddPackage(
        NAME rocket
        GITHUB_REPOSITORY tripleslash/rocket
        GIT_TAG origin/master
        OPTIONS "BUILD_EXAMPLES OFF"
)
add_library(rocket INTERFACE IMPORTED)
target_include_directories(rocket INTERFACE ${rocket_SOURCE_DIR})

juce_add_gui_app(RocketDemo)

set(SourceFolders
    Source)

set(SourceFiles

    Source/Main.cpp
    Source/MainComponent.cpp
    Source/MainComponent.h
    Source/AudioPlayer.h
    Source/AudioPlayerProcessor.cpp
    Source/AudioPlayerProcessor.h
    Source/AudioPlayerState.h
    Source/AudioPlayerView.h
    Source/AudioPlayerView.cpp
)

set(JUCE_DEPENDENCIES
        juce::juce_gui_basics
        juce::juce_audio_utils
)

target_compile_features(RocketDemo PRIVATE cxx_std_17)

target_sources(RocketDemo PRIVATE ${SourceFiles})

set_target_properties(RocketDemo PROPERTIES FOLDER "")

target_include_directories(RocketDemo PRIVATE "${SourceFolders}")

target_link_libraries(RocketDemo
    PRIVATE
    ${JUCE_DEPENDENCIES}
        rocket
    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)
