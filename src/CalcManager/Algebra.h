/*
This class was created by Nico Comendador for the purpose of
WSU CEG 4110-01. This class will handle and house all of the
functionality for any algebraic operations for a symbolic
calculator feature add on to the Microsoft Calculator.
*/

#pragma once

#include <string>
#include <iostream>

#ifndef _Algebra_
#define _Algebra_

using namespace std;

class Algebra
{
private:
    ///\return Each Algebra object will hold a
    /// a string continaing the information of
    /// the input given from a parent class.
    string expression;
    string unformattedExpression;

public:
    ///\return The following lets the compiler
    /// know that the following methods will be
    /// instantiated.
    inline Algebra(string expression);
    inline virtual ~Algebra();
    inline string simplifyExpression();
    inline int evaluate(string tokens);
    inline int applyOp(int a, int b, char op);
    inline int precedence(char op);
    inline string format(string expression);
    inline void newExpression(string expression);
    inline string solveForVariable();
};

#endif
