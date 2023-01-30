cmake_minimum_required(VERSION 3.21)
project(RxCppDemo VERSION 0.0.1)

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
        NAME RxCpp
        VERSION 4.1.1
        GITHUB_REPOSITORY ReactiveX/RxCpp
        DOWNLOAD_ONLY YES
)

if (RxCpp_ADDED)
    # We only want the headers from Rx/v2/src
    add_library(RxCpp INTERFACE IMPORTED)
    set(RxSourceDir "${RxCpp_SOURCE_DIR}/Rx/v2/src")
    target_include_directories(RxCpp INTERFACE ${RxSourceDir})
endif ()

juce_add_gui_app(RxCppDemo)

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

target_compile_features(RxCppDemo PRIVATE cxx_std_17)

target_sources(RxCppDemo PRIVATE ${SourceFiles})

set_target_properties(RxCppDemo PROPERTIES FOLDER "")

target_include_directories(RxCppDemo PRIVATE "${SourceFolders}")

target_link_libraries(RxCppDemo
        PRIVATE
        ${JUCE_DEPENDENCIES}
        RxCpp
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
        )
