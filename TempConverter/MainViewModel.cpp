#include "pch.h"
#include "MainViewModel.h"
#include "MainViewModel.g.cpp"
#include <cwchar>
#include <cmath>

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
	float ToCelcius(float value);
	float ToFahrenheit(float value);


	MainViewModel::MainViewModel() : m_inputDegress(L""), m_result(L""), m_isCelcius(false)
	{}

	hstring MainViewModel::InputDegrees()
	{
		return m_inputDegress;
	}
	void MainViewModel::InputDegrees(const hstring& value)
	{
		m_inputDegress = value;
		auto valueAsLong = wcstol(value.c_str(), nullptr, 10);
		Result(winrt::to_hstring(std::round((valueAsLong - 32.f) / 1.8f)));
		OnPropertyChanged(L"InputDegrees");

	}

	int MainViewModel::Minimum()
	{
		return m_isCelcius ? 0 : 32;
	}

	int MainViewModel::Maximum()
	{
		return m_isCelcius ? 100 : 212;
	}


	bool MainViewModel::IsCelciusInput()
	{
		return m_isCelcius;
	}
	void MainViewModel::IsCelciusInput(bool value)
	{
		m_isCelcius = value;
		OnPropertyChanged(L"Minimum");
		OnPropertyChanged(L"Maximum");
		OnPropertyChanged(L"IsCelciusInput");
	}
	hstring MainViewModel::Result()
	{
		return m_result;
	}
	void MainViewModel::Result(hstring const& value)
	{
		m_result = value;
		OnPropertyChanged(L"Result");
	}




	void MainViewModel::Minimum(int const& value)
	{
		m_minimum = value;
		OnPropertyChanged(L"Minimum");
	}

	void MainViewModel::Maximum(int const& value)
	{
		m_maximum = value;
		OnPropertyChanged(L"Maximum");
	}



	winrt::event_token MainViewModel::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_propertyChanged.add(handler);
	}
	void MainViewModel::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_propertyChanged.remove(token);
	}
	void MainViewModel::OnPropertyChanged(hstring const& propertyName)
	{
		m_propertyChanged(*this, winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ propertyName });
	}

	void MainViewModel::UnitSelection_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
	{
		const std::wstring CELCIUS{ L"Celcius" };
		const std::wstring FAHRENHEIT{ L"Fahrenheit" };
		auto radioButtons = sender.as<Microsoft::UI::Xaml::Controls::RadioButtons>();
		auto selected = e.AddedItems().GetAt(0);
		auto value = selected.try_as<hstring>();
		if (value.has_value())
		{
			std::wstring stdValue{ value.value() };
			if (CSTR_EQUAL == CompareStringEx(LOCALE_NAME_SYSTEM_DEFAULT, NORM_IGNORECASE, CELCIUS.c_str(), CELCIUS.length(), stdValue.c_str(), stdValue.length(), nullptr, nullptr, NULL))
			{

				auto value = CurrentValue();

				IsCelciusInput(true);

				CurrentValue(ToCelcius(value));

				ResultUnit(L"F");
			}
			else
			{
				auto value = CurrentValue();
				IsCelciusInput(false);
				CurrentValue(ToFahrenheit(value));
				ResultUnit(L"C");
			}
			

		}
	}

	void MainViewModel::ResultUnit(hstring const& value)
	{
		m_resultUnit = value;
		OnPropertyChanged(L"ResultUnit");
	}

	hstring MainViewModel::ResultUnit()
	{
		return m_resultUnit;
	}

	void MainViewModel::Slider_ValueChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& e)
	{
		auto value = e.NewValue();
		if (m_isCelcius)
		{
			Result(winrt::to_hstring(ToFahrenheit(value)));
		}
		else
		{
			Result(winrt::to_hstring(ToCelcius(value)));
		}
	}

	int MainViewModel::CurrentValue()
	{
		return m_value;
	}
	
	void MainViewModel::CurrentValue(int const& value)
	{
		m_value = value;
		OnPropertyChanged(L"CurrentValue");
	}

	float ToCelcius(float value)
	{
		return std::round((value - 32.0f) * 5/9);
	}

	float ToFahrenheit(float value)
	{
		return std::round(((value * 9) / 5) + 32);
	}

}
