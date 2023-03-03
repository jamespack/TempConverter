// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"
#include <microsoft.ui.xaml.window.h>
#include <winrt/Microsoft.UI.Windowing.h>

#include "MainViewModel.h"

namespace winrt::TempConverter::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        winrt::TempConverter::MainViewModel ViewModel();


    private:
        HWND m_nativeWindow{ nullptr };
        winrt::Microsoft::UI::Windowing::AppWindow m_appWindow{ nullptr };
        winrt::TempConverter::MainViewModel m_viewModel;
        void SetWindowSize();
    public:
    };
}

namespace winrt::TempConverter::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
