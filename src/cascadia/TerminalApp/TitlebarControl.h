﻿//
// Declaration of the MainUserControl class.
//

#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "TitlebarControl.g.h"

namespace winrt::TerminalApp::implementation
{
    struct TitlebarControl : TitlebarControlT<TitlebarControl>
    {
        TitlebarControl();

        uint64_t ParentWindowHandle() const;
        void ParentWindowHandle(uint64_t handle);

        Windows::UI::Xaml::UIElement Content();
        void Content(Windows::UI::Xaml::UIElement content);

        void Root_SizeChanged(const IInspectable& sender, Windows::UI::Xaml::SizeChangedEventArgs const& e);

        void Minimize_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void Maximize_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void Close_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void DragBar_DoubleTapped(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs const& e);

    private:
        void _OnMaximize(byte flag);
        HWND _window{ nullptr }; // non-owning handle; should not be freed in the dtor.
    };
}

namespace winrt::TerminalApp::factory_implementation
{
    struct TitlebarControl : TitlebarControlT<TitlebarControl, implementation::TitlebarControl>
    {
    };
}