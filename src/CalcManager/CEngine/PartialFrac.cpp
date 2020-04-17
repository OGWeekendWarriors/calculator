#include "PartialFrac.h"

PartialFrac::PartialFrac()
{

}

std::string PartialFrac::PartialFracDecomp(std::string equation)
{
    std::vector<std::string> fraction = splitEquationString(equation);
    std::string num = fraction[0];
    std::string denom = fraction[1];
    std::vector<std::vector<PartialFrac::factor>> factoredNum;
    std::vector<std::vector<PartialFrac::factor>> factoredDenom;
    factoredNum = factorExpr(num);
    factoredDenom = factorExpr(denom);
    std::vector<std::vector<int>> coeffMatrix = createCoeffMatrix(factoredNum, factoredDenom);
    std::vector<int> coeff = solveMatrix(coeffMatrix);
    std::vector<std::string> factors = splitDenom(denom);
    std::string finalstring = stringBuilder(coeff, factors);
    return finalstring;
}

std::vector<std::string> PartialFrac::splitEquationString(std::string equation)
{
    std::vector<std::string> tmp;
    //the following find statements scan for all types of ways the user could have typed their equation
    int pos = equation.find(")/(");
    if (!pos == std::string::npos)
    {
        tmp[0] = equation.substr(0, pos + 1);
        tmp[1] = equation.substr(pos + 2, equation.length());
        return tmp;
    }
    pos = equation.find(")/");
    if (!pos == std::string::npos)
    {
        tmp[0] = equation.substr(0, pos + 1);
        tmp[1] = equation.substr(pos + 2, equation.length());
        return tmp;
    }
    pos = equation.find("/(");
    if (!pos == std::string::npos)
    {
        tmp[0] = equation.substr(0, pos);
        tmp[1] = equation.substr(pos + 1, equation.length());
        return tmp;
    }
    pos = equation.find("/");
    if (!pos == std::string::npos)
    {
        tmp[0] = equation.substr(0, pos);
        tmp[1] = equation.substr(pos + 1, equation.length());
        return tmp;
    }
    else
    {
        throw "Error in splitEquationString method; could not find a division symbol";
    }
}

//bool PartialFrac::factoredForm(std::string denom)
//{
//    int pos = denom.find("^");
//    if (pos == std::string::npos)
//        return true;
//    else
//        return false;
//}

std::vector<std::vector<PartialFrac::factor>> PartialFrac::factorExpr(std::string equation)
{
    //probably going to use some Algebra class logic here, so I am going to leave this blank for now
}

std::vector<std::vector<int>> PartialFrac::createCoeffMatrix(std::vector<std::vector<PartialFrac::factor>> num, std::vector<std::vector<PartialFrac::factor>> denom)
{
    

}
