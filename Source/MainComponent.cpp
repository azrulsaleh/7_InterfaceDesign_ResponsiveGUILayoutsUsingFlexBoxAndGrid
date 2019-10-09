/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() 
    #if ! JUCE_PROJUCER_LIVE_BUILD
        :   rightPanel(Colours::lightgrey), 
            leftPanel(Colours::lightblue)
    #endif
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
    Grid grid;
    using Track = Grid::TrackInfo;
    grid.templateRows = {Track(1_fr) };
    grid.templateColumns = { Track(1_fr), Track(2_fr), Track(1_fr) };
    grid.items = {GridItem (leftPanel), GridItem (mainPanel), GridItem (rightPanel) };
    grid.performLayout(getLocalBounds());
    
    //FlexBox fb;
    //FlexItem left (getWidth() / 4.0f, getHeight(), leftPanel);
    //FlexItem right (getWidth() / 4.0f, getHeight(), rightPanel);
    //FlexItem main (getWidth() / 2.0f, getHeight(), mainPanel);
    //fb.items.addArray( { left, main, right } );
    //fb.performLayout (getLocalBounds().toFloat());
    
    //auto bounds = getLocalBounds();
    //auto panelWidth = bounds.getWidth() / 4;
    //rightPanel.setBounds(bounds.removeFromRight(panelWidth));
    //leftPanel.setBounds(bounds.removeFromLeft(panelWidth));
    //mainPanel.setBounds(bounds);
}

//==============================================================================
#if JUCE_PROJUCER_LIVE_BUILD
MainComponent::RightSidePanel::RightSidePanel () : backgroundColour(Colours::lightblue)
#else
MainComponent::RightSidePanel::RightSidePanel (Colour c) : backgroundColour(c)
#endif
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
    FlexBox fb;
    fb.flexWrap = FlexBox::Wrap::wrap;
    fb.justifyContent = FlexBox::JustifyContent::center;
    fb.alignContent = FlexBox::AlignContent::center;
    for (auto* b : buttons)
        fb.items.add (FlexItem (*b).withMinWidth(50.0f).withMinHeight(50.0f));
    fb.performLayout(getLocalBounds().toFloat());
    
    //auto bounds = getLocalBounds();
    //auto buttonSize = bounds.getWidth() / 3;
    //for(int i = 0; i < buttons.size(); ++i)
    //{
    //    buttons[i] -> setBounds (buttonSize * (i % 3),
    //                             buttonSize * (i / 3) + bounds.getHeight() / 3,
    //                             buttonSize,
    //                             buttonSize);
    //}
}

//==============================================================================
#if JUCE_PROJUCER_LIVE_BUILD
MainComponent::LeftSidePanel::LeftSidePanel () : backgroundColour(Colours::lightgrey)
#else
MainComponent::LeftSidePanel::LeftSidePanel (Colour c) : backgroundColour(c)
#endif
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
    FlexBox knobBox;
    knobBox.flexWrap = FlexBox::Wrap::wrap;
    knobBox.justifyContent = FlexBox::JustifyContent::spaceBetween;
    for (auto* k : knobs)
        knobBox.items.add (FlexItem(*k).withMinHeight(50.0f).withMinWidth(50.0f).withFlex(1));
    FlexBox fb;
    fb.flexDirection = FlexBox::Direction::column;
    fb.items.add(FlexItem(knobBox).withFlex(2.5));
    fb.performLayout(getLocalBounds().toFloat());
    
    //auto bounds = getLocalBounds();
    //auto knobSize = bounds.getWidth() / 3;
    //for (int i = 0; i < knobs.size(); ++i)
    //{
    //    knobs[i] -> setBounds(knobSize * (i %3),
    //                          bounds.getHeight() / 2 * (i / 3),
    //                          knobSize,
    //                          knobSize);
    //}
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
    auto isPortrait = getLocalBounds().getHeight() > getLocalBounds().getWidth();
    FlexBox fb;
    fb.flexDirection = isPortrait ? FlexBox::Direction::column : FlexBox::Direction::row;
    for(auto* s : sliders)
    {
            s->setSliderStyle (isPortrait ? Slider::SliderStyle::LinearHorizontal : Slider::SliderStyle::LinearVertical);
            fb.items.add(FlexItem(*s).withFlex(0, 1, isPortrait ? getHeight() / 5.0f : getWidth() / 5.0f));
    }
    fb.performLayout (getLocalBounds().toFloat());

    //auto bounds = getLocalBounds();
    //auto sliderHeight = bounds.getHeight() / sliders.size();
    //for (auto* slider : sliders) {
    //    slider -> setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    //    slider -> setBounds(bounds.removeFromTop(sliderHeight));
    //    OwnedArray<Slider>sliders;
    //}
}
