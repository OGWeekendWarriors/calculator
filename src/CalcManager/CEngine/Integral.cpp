#include "Header Files/Integral.h"

Integral::Integral()
{

}

Integral::~Integral()
{

}

std::string Integral::evaluateIntegral(std::string expression)
{

    expression = simplify(expression);
    //split coefficients and exponents
    //make note of variable integating upon
    //evaluate integal for each section partitioned by oeprators
    //build string and add C constant to end of string
    std::vector<int> coeff/* = ...*/;
    std::vector<std::string> factors/* = ...*/;
    std::string finalString = stringBuilder(coeff, factors);

}

std::string Integral::simplify(std::string expression)
{

    //Algebra algebraExpression = Algebra(Expression);
    //algebraExpression.format();
    //std::string simpExpression = algebraExpression.simplifyExpression();
    //return simpExpression;

    //temp return to avoid errors
    return std::string();
}

std::string Integral::stringBuilder(std::vector<int> coeff, std::vector<std::string> factors)
{
    return std::string();
}
