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
    ///\return The following lets the class have
    /// the following variables.
    string in;
    bool isExpression;

public:
    ///\return The following lets the compiler
    /// know that the following methods will be
    /// instantiated.
    inline Algebra();
    inline ~Algebra();
    inline bool expressionCheck(string);
    inline void expression(string);
    inline string simplifyExpression();
};

#endif
