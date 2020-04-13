/*
This class was created by Nico Comendador for the purpose of
WSU CEG 4110-01. This class will handle and house all of the
functionality for any algebraic operations for a symbolic
calculator feature add on to the Microsoft Calculator.
*/
#include "Algebra.h"

///\return Constructor.
Algebra::Algebra()
{
}

///\return Since there is no garbage collector for C++, we must
/// include a destructor for the class. Since no array was used
/// we dont actually need to delete anything.
Algebra::~Algebra()
{
}

///\return The calculator takes in wide strings and to make it easier for
/// calculations, this method was created to convert wide strings to strings.
inline string Algebra::wTos(wstring in)
{
    int len;
    int slength = (int)in.length() + 1;
    len = WideCharToMultiByte(CP_ACP, 0, in.c_str(), slength, 0, 0, 0, 0);
    char* buf = new char[len];
    WideCharToMultiByte(CP_ACP, 0, in.c_str(), slength, buf, len, 0, 0);
    std::string r(buf);
    delete[] buf;
    return r;
}

///\return To make this compatible with the calculator, we need to create a converter
/// that converts strings back into a wide string. This method does exactly that.
inline wstring Algebra::sTow(string out)
{
    int len;
    int slength = (int)out.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, out.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, out.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

///\return This method is used to evaluate an expression by
/// multpliying out the terms to get rid of parenthesis and
/// exponents.
wstring Algebra::evaluateExpression(wstring exp)
{
    
}
