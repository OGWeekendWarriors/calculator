#include "pch.h"
#include "CppUnitTest.h"
#include "Header Files/Integral.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Team11_UnitTests
{

    TEST_CLASS(IntegralUnitTests) {

        public:

            TEST_METHOD(Test_findIntegratedUpon) {

                // inputs
                Integral obj;
                std::string expression = "11x^2 / 4 + 1 dx";
                
                // outputs
                char expected_integratedUpon = 'x';

                // test code
                char actual_integratedUpon = obj.findIntegratedUpon(expression);

                // Assert statement(s)
                Assert::AreEqual(expected_integratedUpon, actual_integratedUpon);

            }

            TEST_METHOD(Test_splitExpressionIndex1) {

                // inputs
                Integral obj;
                std::string expression = "11x^2 / 4 + 1 dx";
                obj.integratedUpon = obj.findIntegratedUpon(expression);

                // outputs
                double expected_coeff1 = 11.0 / 4.0;
                int expected_exponent1 = 2;
                char expected_op1 = '+';

                // test code
                obj.splitExpression(expression);

                // Assert statement(s)
                Assert::AreEqual(expected_coeff1, obj.coeff.at(0));
                Assert::AreEqual(expected_exponent1, obj.exponent.at(0));
                Assert::AreEqual(expected_op1, obj.op.at(0));
                Assert::IsFalse(obj.integratedUponExponent.at(0));

            }

            TEST_METHOD(Test_splitExpressionIndex2) {

                // inputs
                Integral obj;
                std::string expression = "11x^2 / 4 + 1 dx";
                obj.integratedUpon = obj.findIntegratedUpon(expression);

                // outputs
                double expected_coeff2 = 1.0;
                int expected_exponent2 = 0;
                char expected_op2 = 'd';

                // test code
                obj.splitExpression(expression);

                // Assert statement(s)
                Assert::AreEqual(expected_coeff2, obj.coeff.at(1));
                Assert::AreEqual(expected_exponent2, obj.exponent.at(1));
                Assert::AreEqual(expected_op2, obj.op.at(1));
                Assert::IsFalse(obj.integratedUponExponent.at(1));

            }

            TEST_METHOD(Test_evalTermIndex1) {

                // inputs
                Integral obj;
                std::string expression = "11x^2 / 4 + 1 dx";
                obj.integratedUpon = obj.findIntegratedUpon(expression);
                obj.splitExpression(expression);
                obj.evalCoeff.resize(obj.coeff.size());
                obj.evalExponent.resize(obj.exponent.size());
                obj.evalOverln.resize(obj.evalCoeff.size());

                // outputs
                double expected_coeff1 = 11.0 / 12.0;
                int expected_exponent1 = 3;
                char expected_op1 = '+';

                // test code
                obj.evalTerm(0);

                // Assert statement(s)
                Assert::AreEqual(expected_coeff1, obj.evalCoeff.at(0));
                Assert::AreEqual(expected_exponent1, obj.evalExponent.at(0));
                Assert::AreEqual(expected_op1, obj.op.at(0));
                Assert::IsFalse(obj.evalOverln.at(0));

            }

            TEST_METHOD(Test_evalTermIndex2)
            {
                // inputs
                Integral obj;
                std::string expression = "11x^2 / 4 + 1 dx";
                obj.integratedUpon = obj.findIntegratedUpon(expression);
                obj.splitExpression(expression);
                obj.evalCoeff.resize(obj.coeff.size());
                obj.evalExponent.resize(obj.exponent.size());
                obj.evalOverln.resize(obj.evalCoeff.size());

                // outputs
                double expected_coeff2 = 1.0;
                int expected_exponent2 = 1;
                char expected_op2 = 'd';

                // test code
                obj.evalTerm(1);

                // Assert statement(s)
                Assert::AreEqual(expected_coeff2, obj.evalCoeff.at(1));
                Assert::AreEqual(expected_exponent2, obj.evalExponent.at(1));
                Assert::AreEqual(expected_op2, obj.op.at(1));
                Assert::IsFalse(obj.evalOverln.at(1));
            }

    };
}
