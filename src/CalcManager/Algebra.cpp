/*
This class was created by Nico Comendador for the purpose of
WSU CEG 4110-01. This class will handle and house all of the
functionality for any algebraic operations for a symbolic
calculator feature add on to the Microsoft Calculator.
*/
#include "Algebra.h"

using namespace std;

///\return Constructor will instantiate the expression variable.
Algebra::Algebra(string expression)
{
    this->expression = expression;
}

///\return Since there is no garbage collector for C++, we must
/// include a destructor for the class. Every class with a contructor
/// must have one.
Algebra::~Algebra()
{
}

///\return This method is used to simplify an expression by
/// multpliying out the terms to get rid of parenthesis and
/// exponents.
string Algebra::simplifyExpression()
{
    string result;

    return result;
}

///\return This method is responsible for parsing through
/// and evaluating the expression. Once evaluated, we can
/// then simplify.
inline int Algebra::evaluate(string tokens)
{
    return 0;
}

///\return This method applies the operation on the expression
/// based off of a simple case switch. This is used for
/// evaluating and so it is needed in order to simplify.
inline int Algebra::applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}

///\return This method determines the precedence an operator
/// has. This helps set up the rules (PEMDAS) for evalutaing
/// and simplifying expressions.
inline int Algebra::precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
