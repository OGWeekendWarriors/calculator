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
    //find integratedUpon variable
    integratedUpon = findIntegratedUpon(expression);

    //split coefficients and exponents
    splitExpression(expression);
    
    //evaluate integal for each section partitioned by oeprators
    //build string and add C constant to end of string
    
    std::string finalString = stringBuilder(coeff, exponent);

}

std::string Integral::simplify(std::string expression)
{

    /* Algebra Class implementation for later
    Algebra algebraExpression = Algebra(Expression);
    algebraExpression.format();
    std::string simpExpression = algebraExpression.simplifyExpression();
    return simpExpression;
    */

    //temp return to avoid errors
    return std::string();
}

std::string Integral::stringBuilder(std::vector<int> coeff, std::vector<int> factors) //add functionality
{
    return std::string();
}

char Integral::findIntegratedUpon(std::string expression)
{

    //find 'dx' form and take just the char after 'd'
    int pos = expression.find_last_of("d");
    if (pos != std::string::npos && pos!= expression.length-1)
    {
        return expression.at(pos + 1);
    } else {
        return 'x';
    }

}

void Integral::splitExpression(std::string expression)
{

    //functionality here (run through string, first char is coefficient if not integratedUpon, char after ^ is exponent - if no integratedUpon, exponent is 0)
    //each coefficient should be paired with an exponent for each term

}
