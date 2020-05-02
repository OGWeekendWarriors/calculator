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
        ///\returns ...
        
        ///\returns a string that represents the integrated expression
        std::string stringBuilder(std::vector<int> coeff, std::vector<std::string> factors);

};
