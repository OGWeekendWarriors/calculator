/*
This class was created by Nico Comendador for the purpose of
WSU CEG 4110-01. This class will handle and house all of the
functionality for any algebraic operations for a symbolic
calculator feature add on to the Microsoft Calculator.
*/
#include "Algebra.h"
#include <WinNls.h>

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
