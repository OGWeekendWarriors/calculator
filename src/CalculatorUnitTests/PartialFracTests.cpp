#include "pch.h"
#include "CppUnitTest.h"
#include "CEngine\PartialFrac.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Team11_UnitTests
{
    TEST_CLASS(PartialFracUnitTests)
    {
    public:
        TEST_METHOD(test_splitEquationString)
        {
            PartialFrac testObj = PartialFrac();

            std::string input1 = "(x+1)/(x+2)(x+3)";
            std::string expectedNum1 = "(x+1)";
            std::string expectedDenom1 = "(x+2)(x+3)";
            std::vector<std::string> output1 = testObj.splitEquationString(input1);
            Assert::AreEqual(output1[0], expectedNum1);
            Assert::AreEqual(output1[1], expectedDenom1);

            std::string input2 = "x+1/(x+2)(x+3)";
            std::string expectedNum2 = "x+1";
            std::string expectedDenom2 = "(x+2)(x+3)";
            std::vector<std::string> output2 = testObj.splitEquationString(input2);
            Assert::AreEqual(output2[0], expectedNum2);
            Assert::AreEqual(output2[1], expectedDenom2);

            std::string input3 = "x+1/x+2";
            std::string expectedNum3 = "x+1";
            std::string expectedDenom3 = "x+2";
            std::vector<std::string> output3 = testObj.splitEquationString(input3);
            Assert::AreEqual(output3[0], expectedNum3);
            Assert::AreEqual(output3[1], expectedDenom3);
        }
    };
}
