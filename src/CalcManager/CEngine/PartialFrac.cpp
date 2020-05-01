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
    std::vector<std::string> RHSexpressions;
    std::string LHSexpression;
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

    //finding LHS expression
    std::string expression;
    for (int i = 0; i < num.size(); i++)
    {
            std::string tmp = "(" + num[i].variable + " " + num[i].operation + " " + std::to_string(num[i].constant) + ")";
            if (i == num.size() - 1)
                expression += tmp;
            else
                expression += tmp + " * ";
    }
    // Algebra intermediate = Algebra(expression);
    // intermediate.format();
    // LHSexpression = intermediate.simplifyExpression();

    //creating the matrix to store the values; I am resizing the vectors since I need to start at the bottom right instead of the top left
    std::vector<std::vector<int>> matrix;
    matrix.resize(RHSexpressions.size() + 1);
    for (int i = 0; i < matrix.size(); i++)
    {
        matrix[i].resize(RHSexpressions.size());
    }
    //now that we have the expressions, now we need to add their scalars into the matrix
    // assuming that the Algebra class has return expressions ordered from highest power to lowest power with 'x' as the variable
    //since we have them all in strings with white spaces separating terms and operators, we can parse the string for values.
    std::vector<std::vector<int>> RHScoeffs;
    for (int i = 0; i < RHSexpressions.size(); i++)
    {
        int innerpos = 0;
        std::vector<char> buffer;
        for (std::string::reverse_iterator rit = RHSexpressions[i].rbegin(); rit != RHSexpressions[i].rend(); ++rit)
        {
            if (*rit == ' ')
            {
                if (buffer.size() != 0) //the above statement will trigger after we pass an operation character; this saves the code inside from executing on an empty buffer
                {
                    std::stringstream ss;
                    for (int k = buffer.size() - 1; k >= 0; k++)
                    {
                        ss << buffer[k];
                    }
                    ss >> RHScoeffs[i][innerpos];
                    innerpos++;
                }
                
            }
            else if (*rit == 'x' || *rit == '+' || *rit == '-' || *rit == '*' || *rit == '/') // ignoring variables and operations
                continue;
            else
                buffer.push_back(*rit);
        }
    }
    std::vector<int> LHScoeffs;

    
}
