#pragma once
#include "MainViewModel.g.h"

// WARNING: This file is automatically generated by a tool. Do not directly
// add this file to your project, as any changes you make will be lost.
// This file is a stub you can use as a starting point for your implementation.
//
// To add a copy of this file to your project:
//   1. Copy this file from its original location to the location where you store 
//      your other source files (e.g. the project root). 
//   2. Add the copied file to your project. In Visual Studio, you can use 
//      Project -> Add Existing Item.
//   3. Delete this comment and the 'static_assert' (below) from the copied file.
//      Do not modify the original file.
//
// To update an existing file in your project:
//   1. Copy the relevant changes from this file and merge them into the copy 
//      you made previously.
//    
// This assertion helps prevent accidental modification of generated files.

namespace winrt::TempConverter::implementation
{
    struct MainViewModel : MainViewModelT<MainViewModel>
    {
        MainViewModel();

        hstring InputDegrees();
        void InputDegrees(hstring const& value);
        bool IsCelciusInput();
        void IsCelciusInput(bool value);


        int Minimum();
        void Minimum(int const& value);

        hstring ResultUnit();
        void ResultUnit(hstring const& value);
        int CurrentValue();
        void CurrentValue(int const& value);
        int Maximum();
        void Maximum(int const& value);
        hstring Result();
        void Result(hstring const& value);
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        void UnitSelection_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e);
        void Slider_ValueChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e);


    private:
        void OnPropertyChanged(hstring const& propertyName);
        hstring m_inputDegress;
        hstring m_result;
        hstring m_resultUnit;
        int m_minimum;
        int m_maximum;
        int m_value;
        bool m_isCelcius;
        event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;

    };
}
namespace winrt::TempConverter::factory_implementation
{
    struct MainViewModel : MainViewModelT<MainViewModel, implementation::MainViewModel>
    {
    };
}
