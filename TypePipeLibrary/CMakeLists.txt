cmake_minimum_required(VERSION 3.21)
project(TypePipeDemo VERSION 0.0.1)

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
        NAME TypePipe
        GITHUB_REPOSITORY normalised/TypePipe
        GIT_TAG origin/main
)

add_library(TypePipe INTERFACE IMPORTED)
target_include_directories(TypePipe INTERFACE ${TypePipe_SOURCE_DIR})

juce_add_gui_app(TypePipeDemo)

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

target_compile_features(TypePipeDemo PRIVATE cxx_std_17)

target_sources(TypePipeDemo PRIVATE ${SourceFiles})

set_target_properties(TypePipeDemo PROPERTIES FOLDER "")

target_include_directories(TypePipeDemo PRIVATE "${SourceFolders}")

target_link_libraries(TypePipeDemo
    PRIVATE
    ${JUCE_DEPENDENCIES}
        TypePipe
    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)
