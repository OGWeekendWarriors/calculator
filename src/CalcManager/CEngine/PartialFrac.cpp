#include "PartialFrac.h"

PartialFrac::PartialFrac()
{

}

std::string PartialFrac::PartialFracDecomp(std::string equation)
{
    std::vector<std::string> fraction = splitEquationString(equation);
    std::string num = fraction[0];
    std::string denom = fraction[1];
    std::vector<PartialFrac::factor> factoredNum;
    std::vector<PartialFrac::factor> factoredDenom;
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

std::vector<PartialFrac::factor> PartialFrac::factorExpr(std::string equation)
{
    //probably going to use some Algebra class logic here, so I am going to leave this blank for now
}

std::vector<std::vector<int>> PartialFrac::createCoeffMatrix(std::vector<PartialFrac::factor> num, std::vector<PartialFrac::factor> denom)
{
    //finding the RHS equation
    //for each position, the value is equal to all other positions multiplied together.
    std::vector<std::string> RHS;
    for (int i = 0; i < denom.size(); i++)
    {
        std::string expression;
        for (int j = 0; j < denom.size(); j++)
        {
            if (i != j)
            {
                std::string tmp = "(" + denom[j].variable + " " + denom[j].operation + " " + std::to_string(denom[j].constant) + ")";
                if (j == denom.size() - 1)
                    expression += tmp;
                else
                    expression += tmp + " * ";
            }
        }
        //Algebra intermediate = Algebra(expression);
        //intermediate.format();
        //RHS[i] = intermediate.simplifyExpression();
    }

    //finding LHS equation
    std::vector<std::string> LHS;
    for (int i = 0; i < num.size(); i++)
    {
        std::string expression;
        for (int j = 0; j < num.size(); j++)
        {
            if (i != j)
            {
                std::string tmp = "(" + num[j].variable + " " + num[j].operation + " " + std::to_string(num[j].constant) + ")";
                if (j == num.size() - 1)
                    expression += tmp;
                else
                    expression += tmp + " * ";
            }
        }
        // Algebra intermediate = Algebra(expression);
        // intermediate.format();
        // LHS[i] = intermediate.simplifyExpression();
    }
    //now that we have the expressions, now we need to add their scalars into the matrix
    //assuming that the Algebra class has return expressions ordered from highest power to lowest power

    
}
