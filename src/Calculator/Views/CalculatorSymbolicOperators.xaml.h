
//
// CalculatorStandardOperators.xaml.h
// Declaration of the CalculatorStandardOperators class
//

#pragma once

#include "Views/CalculatorSymbolicOperators.g.h"
#include "Views/NumberPad.xaml.h"

namespace CalculatorApp
{
    [Windows::Foundation::Metadata::WebHostHidden] public ref class CalculatorSymbolicOperators sealed
    {
    public:
        CalculatorSymbolicOperators();

        DEPENDENCY_PROPERTY_OWNER(CalculatorSymbolicOperators);

        property bool IsErrorVisualState
        {
            bool get();
            void set(bool value);
        }

    private:
        bool m_isErrorVisualState;
    };
}
