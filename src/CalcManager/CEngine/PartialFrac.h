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
    ///\returns true if demon is in factored form
    bool factoredForm(std::string denom);
    ///\returns a factored form of denom
    std::string factorDenom(std::string denom);
    ///\returns a vector that holds a factor at each index
    std::vector<std::string> splitDenom(std::string denom);
    ///\returns a matrix with the coefficients for the partial frac decomp
    std::vector<std::vector<int>> createCoeffMatrix(std::string num, std::string denom);
    ///\returns the coefficients of the partial fract decomp
    std::vector<int> solveMatrix(std::vector<std::vector<int>> matrix);
    ///\returns a string that represents the partial frac decomp
    std::string stringBuilder(std::vector<int> coeff, std::vector<std::string> factors);
    ///numerator of the equation string provided to PartialFracDecomp
    std::string num;
    ///denominator of the equation string provided to PartialFracDecomp
    std::string denom;
    ///coefficient matrix
    std::vector<std::vector<int>> coeffMatrix;
};
