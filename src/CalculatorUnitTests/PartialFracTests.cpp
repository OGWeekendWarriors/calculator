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
        //this method WILL fail since the algebra class is not implemented
        TEST_METHOD(test_createCeoffMatrix)
        {
            PartialFrac testObj = PartialFrac();

            std::vector<PartialFrac::factor> num;
            PartialFrac::factor tmp1;
            tmp1.variable = "x";
            tmp1.operation = "+";
            tmp1.constant = 1;
            num.push_back(tmp1);

            std::vector<PartialFrac::factor> denom;
            tmp1.variable = "x";
            tmp1.operation = "+";
            tmp1.constant = 2;
            denom.push_back(tmp1);
            tmp1.variable = "x";
            tmp1.operation = "+";
            tmp1.constant = 3;
            denom.push_back(tmp1);

            /*
            expected matrix
            -------------
            | 1 | 1 | 1 |
            | 3 | 2 | 1 |
            -------------
            */
            std::vector<std::vector<int>> expectedOutput;
            expectedOutput.resize(3);
            expectedOutput[0].push_back(1);
            expectedOutput[0].push_back(3);
            expectedOutput[1].push_back(1);
            expectedOutput[1].push_back(2);
            expectedOutput[3].push_back(1);
            expectedOutput[3].push_back(1);

            std::vector<std::vector<int>> output = testObj.createCoeffMatrix(num, denom);

            Assert::AreEqual(output, expectedOutput);
        }
    };
}
