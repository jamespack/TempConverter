// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include <winrt/Windows.UI.Core.h>
#include <winrt/Microsoft.UI.Interop.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.ApplicationModel.h>
#include "MainViewModel.h"
#include <filesystem>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Windows::Foundation;
using namespace Microsoft::UI::Windowing;
using namespace Microsoft::UI;


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::TempConverter::implementation
{

    winrt::TempConverter::MainViewModel MainWindow::ViewModel()
    {
        return m_viewModel;
    }
    MainWindow::MainWindow()
    {
        m_viewModel = winrt::make<winrt::TempConverter::implementation::MainViewModel>();
        InitializeComponent();
        this->mainGrid().DataContext(m_viewModel);
        auto nativeWindow = this->try_as<IWindowNative>();
        
        nativeWindow->get_WindowHandle(&m_nativeWindow);
        SetWindowSize();
    }
    
    void MainWindow::SetWindowSize()
    {
        if (nullptr == m_nativeWindow)
        {
            return;
        }
        std::filesystem::path packagePath{ winrt::Windows::ApplicationModel::Package::Current().InstalledLocation().Path().c_str() };
        packagePath.concat(L"\\Assets\\TempConverter.ico");

        this->Title(L"Temperature Converter");
        SetWindowPos(m_nativeWindow, nullptr, 0, 0, 480, 600, NULL);
       
        m_appWindow = AppWindow::GetFromWindowId(GetWindowIdFromWindow(m_nativeWindow));
        m_appWindow.SetIcon(packagePath.c_str());
        
        m_appWindow.TitleBar().IconShowOptions(IconShowOptions::HideIconAndSystemMenu);
        m_appWindow.TitleBar().ExtendsContentIntoTitleBar(true);
        
        
        this->SetTitleBar(this->MyTitleBar());
        auto presenter = m_appWindow.Presenter().as<IOverlappedPresenter>();
        
        presenter.IsResizable(false);
        presenter.IsMaximizable(false);
       
    }
    

}






