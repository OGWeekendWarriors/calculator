#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Team11_UnitTests
{
    ///
    /// An example to showcase how to create unit tests; in order to run tests
    /// In order to have VS detect your tests, go to 'Test' -> 'Run All Tests'
    /// After VS has detected your test, you can then go to 'Test' -> 'Test Explorer' to run individual tests
    ///
    TEST_CLASS(ExampleTestClass)
    {
    public:

        TEST_METHOD(TestA)
        {
            // inputs
            int a = 1;
            int b = 2;
            // outputs
            int expectedOut = 3;

            // test code
            int out = a + b;

            // Assert statement(s)
            Assert::AreEqual(out, expectedOut);
        }
    };
}
