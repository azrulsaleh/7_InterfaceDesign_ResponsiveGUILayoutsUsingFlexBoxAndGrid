/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : rightPanel(Colours::lightgrey), leftPanel(Colours::lightblue)
{
    setSize (600, 400);
    
    addAndMakeVisible(rightPanel);
    addAndMakeVisible(leftPanel);
    addAndMakeVisible(mainPanel);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    auto bounds = getLocalBounds();
    auto panelWidth = bounds.getWidth() / 4;
    rightPanel.setBounds(bounds.removeFromRight(panelWidth));
    leftPanel.setBounds(bounds.removeFromLeft(panelWidth));
    mainPanel.setBounds(bounds);
}

//==============================================================================
MainComponent::RightSidePanel::RightSidePanel (Colour c) : backgroundColour(c)
{
    for(int i = 0; i < 9; ++i)
        addAndMakeVisible(buttons.add(new TextButton (String(i))));
}

void MainComponent::RightSidePanel::paint (Graphics& g)
{
    g.fillAll(backgroundColour);
}

void MainComponent::RightSidePanel::resized()
{
    auto bounds = getLocalBounds();
    auto buttonSize = bounds.getWidth() / 3;
    for(int i = 0; i < buttons.size(); ++i)
    {
        buttons[i] -> setBounds (buttonSize * (i % 3),
                                 buttonSize * (i / 3) + bounds.getHeight() / 3,
                                 buttonSize,
                                 buttonSize);
    }
}

//==============================================================================
MainComponent::LeftSidePanel::LeftSidePanel (Colour c) : backgroundColour(c)
{
    for (int i = 0; i < 6; ++i)
    {
        auto* slider = new Slider();
        slider -> setSliderStyle(Slider::SliderStyle::Rotary);
        slider -> setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        addAndMakeVisible(knobs.add(slider));
    }
}
void MainComponent::LeftSidePanel::paint (Graphics& g)
{
    g.fillAll (backgroundColour);
}
void MainComponent::LeftSidePanel::resized()
{
    auto bounds = getLocalBounds();
    auto knobSize = bounds.getWidth() / 3;
    for (int i = 0; i < knobs.size(); ++i)
    {
        knobs[i] -> setBounds(knobSize * (i %3),
                              bounds.getHeight() / 2 * (i / 3),
                              knobSize,
                              knobSize);
    }
}

//==============================================================================
MainComponent::MainPanel::MainPanel()
{
    for (int i = 0; i < 5; ++i) {
        addAndMakeVisible(sliders.add(new Slider()));
        sliders.getLast() -> setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    }
}
void MainComponent::MainPanel::paint(Graphics& g)
{
    g.fillAll(Colours::hotpink);
}
void MainComponent::MainPanel::resized()
{
    auto bounds = getLocalBounds();
    auto sliderHeight = bounds.getHeight() / sliders.size();
    for (auto* slider : sliders) {
        slider -> setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        slider -> setBounds(bounds.removeFromTop(sliderHeight));
        OwnedArray<Slider>sliders;
    }
}
