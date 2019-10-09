/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    struct RightSidePanel : public Component
    {
        #if JUCE_PROJUCER_LIVE_BUILD
            RightSidePanel ();
        #else
            RightSidePanel (Colour);
        #endif
        void paint (Graphics&) override;
        void resized() override;
        Colour backgroundColour;
        OwnedArray<TextButton>buttons;
    };
    RightSidePanel rightPanel;
    
    struct LeftSidePanel : public Component
    {
        #if JUCE_PROJUCER_LIVE_BUILD
            LeftSidePanel ();
        #else
            LeftSidePanel (Colour);
        #endif
        void paint(Graphics&) override;
        void resized() override;
        Colour backgroundColour;
        OwnedArray<Slider>knobs;
    };
    LeftSidePanel leftPanel;

    struct MainPanel : public Component
    {
        MainPanel();
        void paint (Graphics&) override;
        void resized() override;
        OwnedArray<Slider>sliders;
    };
    MainPanel mainPanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
