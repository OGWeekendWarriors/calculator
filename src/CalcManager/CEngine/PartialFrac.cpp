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
    tmp.resize(2);
    //the following find statements scan for all types of ways the user could have typed their equation
    size_t pos = equation.find(")/(");
    if (pos != std::string::npos)
    {
        tmp[0] = equation.substr(0, pos + 1);
        tmp[1] = equation.substr(pos + 2, equation.length());
        return tmp;
    }
    pos = equation.find(")/");
    if (pos != std::string::npos)
    {
        tmp[0] = equation.substr(0, pos + 1);
        tmp[1] = equation.substr(pos + 2, equation.length());
        return tmp;
    }
    pos = equation.find("/(");
    if (pos != std::string::npos)
    {
        tmp[0] = equation.substr(0, pos);
        tmp[1] = equation.substr(pos + 1, equation.length());
        return tmp;
    }
    pos = equation.find("/");
    if (pos != std::string::npos)
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
    throw "Not implemented";
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
        //RHSexpressions.push_back(intermediate.simplifyExpression());
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
    /*Now that we have the expressions, now we need to add their scalars into the matrix
      Assuming that the Algebra class has return expressions ordered from highest power to lowest power with 'x' as the variable
      since we have them all in strings with white spaces separating terms and operators, we can parse the string for values.*/
    //extracting RHS coefficients
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
                    for (size_t k = buffer.size() - 1; k >= 0; k++)
                    {
                        ss << buffer[k];
                    }
                    ss >> RHScoeffs[i][innerpos++];
                }
                
            }
            else if (*rit == 'x' || *rit == '+' || *rit == '-' || *rit == '*' || *rit == '/') // ignoring variables and operations
                continue;
            else    //number detected
                buffer.push_back(*rit);
        }
    }
    //extracting LHS coefficients
    std::vector<int> LHScoeffs;
    int pos = 0;
    std::vector<char> buffer;
    for (std::string::reverse_iterator rit = LHSexpression.rbegin(); rit != LHSexpression.rend(); ++rit)
    {
        if (*rit == ' ')
        {
            if (buffer.size()
                != 0) // the above statement will trigger after we pass an operation character; this saves the code inside from executing on an empty buffer
            {
                std::stringstream ss;
                for (size_t k = buffer.size() - 1; k >= 0; k++)
                {
                    ss << buffer[k];
                }
                ss >> LHScoeffs[pos++];
            }
        }
        else if (*rit == 'x' || *rit == '+' || *rit == '-' || *rit == '*' || *rit == '/') // ignoring variables and operations
            continue;
        else
            buffer.push_back(*rit);
    }

    /*
        The matrix is formatted as follows:
                        ----------------------------------------------------------------------------------------------------------------
      s^n coeff of ->  | RHS[M][N-1]   | RHS[M][N-2]   | ... |    RHS[M][1]           |       RHS[M][0]        |       LHS[N-1]         |   matrix[x][0]
     s^n-1 coeff of->  | RHS[M-1][N-1] | RHS[M-1][N-2] | ... |    RHS[M-1][1]         |       RHS[M-1][0]      |       LHS[N-2]         |   matrix[x][1]
         ...           |    ...        |    ...        | ... |      ...               |         ...            |       ...              |   ...
        s coeff of ->  | RHS[1][N-1]   | RHS[1][N-2]   | ... |    RHS[1][1]           |       RHS[1][0]        |       LHS[1]           |   matrix[x][matrix[x].size()-2]
    const coeff of ->  | RHS[0][N-1]   | RHS[0][N-2]   | ... |    RHS[0][1]           |       RHS[0][0]        |       LHS[0]           |   matrix[x][matrix[x].size()-1]
                        ----------------------------------------------------------------------------------------------------------------
                         matrix[0]       matrix[1]       ...   matrix[matrix.size()-3]  matrix[matrix.size()-2]  matrix[matrix.size()-1]
    */

    //LHS coeffs
    //this will fill up the right-most column of the matrix
    for (int N = 0; N < LHScoeffs.size(); N++)
    {
        matrix[matrix.size() - 1][matrix.size() - (N+1)] = LHScoeffs[N];
    }

    //RHS coeffs
    //this will fill up the rest of the matrix
    int N = 0;
    size_t startpos = matrix.size() - 2;
    for (size_t i = matrix[startpos].size() - 1; i >= 0; i--)
    {
        for (int M = 0; M > RHScoeffs.size(); M++)
        {
            matrix[i][matrix[i].size() - (M + 1)] = RHScoeffs[M][N];
        }
        N++;
    }
    
    return matrix;
}

std::vector<std::string> PartialFrac::splitDenom(std::string denom)
{
    throw "Not implemented";
}

std::vector<int> PartialFrac::solveMatrix(std::vector<std::vector<int>> matrix)
{
    throw "Not implemented";
}

std::string PartialFrac::stringBuilder(std::vector<int> coeff, std::vector<std::string> factors)
{
    throw "Not implemented";
}
