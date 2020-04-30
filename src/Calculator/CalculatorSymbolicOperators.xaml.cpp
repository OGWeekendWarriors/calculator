// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

//
// CalculatorSymbolicOperators.xaml.cpp
// Implementation of the CalculatorSymbolicOperators class
//

#include "pch.h"
#include "CalculatorSymbolicOperators.xaml.h"
#include "Controls/CalculatorButton.h"

using namespace CalculatorApp;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

CalculatorSymbolicOperators::CalculatorSymbolicOperators()
    : m_isErrorVisualState(false)
{
    InitializeComponent();
}

bool CalculatorSymbolicOperators::IsErrorVisualState::get()
{
    return m_isErrorVisualState;
}

void CalculatorSymbolicOperators::IsErrorVisualState::set(bool value)
{
    if (m_isErrorVisualState != value)
    {
        m_isErrorVisualState = value;
        String ^ newState = m_isErrorVisualState ? L"ErrorLayout" : L"NoErrorLayout";
        VisualStateManager::GoToState(this, newState, false);
        NumberPad->IsErrorVisualState = m_isErrorVisualState;
    }
}
