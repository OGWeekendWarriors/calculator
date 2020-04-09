/*
This class was created by Nico Comendador for the purpose of
WSU CEG 4110-01. This class will handle and house all of the
functionality for any algebraic operations for a symbolic
calculator feature add on to the Microsoft Calculator.
*/
#include "Algebra.h"

///\return Constructor will initialize class variables.
Algebra::Algebra()
{
    in = "";
    isExpression = false;
}

///\return Since there is no garbage collector for C++, we must
/// include a destructor for the class. Since no array was used
/// we dont actually need to delete anything.
Algebra::~Algebra()
{
}

///\return This will create an expression of the given input and
/// will allow the class to perform expression related operations.
void Algebra::expression(string input)
{
    input = in;
    if (expressionCheck(in))
    {
        isExpression = true;
    }
}

///\return An expression is a combination of numbers, variables
/// and at least one arithmetic operation. If it contains an equal
/// sign, then it is an equation.
bool Algebra::expressionCheck(string input)
{
    if (input.find("="))
        return false;
    else
        return true;
}

///\return This method is used to simplify an expression by
/// multpliying out the terms to get rid of parenthesis and
/// exponents.
string Algebra::simplifyExpression()
{
    if (isExpression)
    {
        string expression = "";
        return expression;
    }
    else
    {
        return "Cannot simplify, not an expression.";
    }
}
