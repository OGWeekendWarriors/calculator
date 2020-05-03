#pragma once
/**
 * Module Name: PartialFrac.h
 * Author: Jared Gibson
 * Module Description:
 *       The class definition for the PartialFrac class responsible for performing
 *       basic partial fraction decomposition (no long division, no repeated roots, no imaginary roots)
 * Created: 16-April-2020
 */

class PartialFrac
{
public:
    PartialFrac();
    ///\returns the partial fraction decomposition of the equation provided
    std::string PartialFracDecomp(std::string equation);

private:
    ///\returns a vector where [0] is the numerator and [1] is denominator
    std::vector<std::string> splitEquationString(std::string equation);
    struct factor {
        std::string variable;
        std::string operation;
        int constant; };
    ///\returns a factored form of denom using the factor struct to encapsulate a single factor
    std::vector<factor> factorExpr(std::string equation);
    ///\returns a vector that holds a factor at each index
    std::vector<std::string> splitDenom(std::string denom);
    ///\returns a matrix with the coefficients for the partial frac decomp
    std::vector<std::vector<int>> createCoeffMatrix(std::vector<factor> num, std::vector<factor> denom);
    ///\returns the coefficients of the partial fract decomp
    std::vector<int> solveMatrix(std::vector<std::vector<int>> matrix);
    ///\returns a string that represents the partial frac decomp
    std::string stringBuilder(std::vector<int> coeff, std::vector<std::string> factors);

    /***************
    Methods that I think I no longer need

    ///\returns true if denom is in factored form
    bool factoredForm(std::string denom);
    ***************/

};
