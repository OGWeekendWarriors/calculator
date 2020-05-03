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

        /// Vector which holds the coefficients of the expression (either int or fraction)
        std::vector<double> coeff;
        /// Vector which holds the exponents tied to each term (2 from x^2 etc.) - assuming int exponents
        std::vector<int> exponent;
        /// Vector which holds the operator following a term (d operator following last term)
        std::vector<char> op;
        /// Vector which holds a bool representing if the exponent is the integratedUpon var
        std::vector<bool> integratedUponExponent;
        /// Char to decide what is being integrated upon
        char integratedUpon;

        /// Vector which holds the evaluated coefficients
        std::vector<double> evalCoeff;
        /// Vector which holds the evaluated exponents
        std::vector<int> evalExponent;
        /// vector which holds the evaluated operators
        std::vector<char> evalOp;
        /// Vector which holds the evaluated integratedUponExponent var
        std::vector<bool> evalIntegratedUponExponent;

        ///\returns a simplified expression using Algebra class
        std::string simplify(std::string expression);

        ///\returns a string that represents the integrated expression
        std::string stringBuilder(std::vector<double> evalCoeff, std::vector<int> evalExponent, std::vector<char> evalOp, std::vector<bool> evalIntegratedUponExponent);

        ///\returns a char that represetns the variable being integrated on (if no defined, dx assumed)
        char findIntegratedUpon(std::string expression);

        ///\returns nothing - splits expression into vectors to be integrated
        void splitExpression(std::string expression);

        ///\returns nothing - evaluates each term (integrates) and puts evaluated values in eval vectors
        void evalTerm(int termIndex);

};
