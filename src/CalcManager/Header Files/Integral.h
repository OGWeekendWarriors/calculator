#pragma once
/**
 * Module Name: Integral.h
 * Author: Josh Ehlinger
 * Module Description:
 *      The class definition for the Integral class responsible for performing
 *      basic integration (polynomials, trig functions, ln, a^x, e^x)
 * Updated 01-May-2020
 */
class Integral
{

    public:
        Integral();
        ~Integral();
        ///\returns the integral of the expression provided
        std::string evaluateIntegral(std::string expression);

    private:

        ///\returns a simplified expression using Algebra class
        std::string simplify(std::string expression);

        ///\returns a string that represents the integrated expression
        std::string stringBuilder(std::vector<int> coeff, std::vector<int> factors);

        ///Variable to decide what is being integrated upon
        char integratedUpon;

        ///\returns a char that represetns the variable being integrated on (if no defined, dx assumed)
        char findIntegratedUpon(std::string expression);

        ///Vector which holds the coefficients of the expression
        std::vector<int> coeff;
        ///Vector which holds the exponents tied to each term (2 from x^2 etc.)
        std::vector<int> exponent;

        ///\returns
        void splitExpression(std::string expression);

};
