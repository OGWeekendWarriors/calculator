#include "Header Files/Integral.h"

Integral::Integral()
{

}

Integral::~Integral()
{

}

std::string Integral::evaluateIntegral(std::string expression)
{

    expression = simplify(expression);
    //find integratedUpon variable
    integratedUpon = findIntegratedUpon(expression);

    //make sure there is something in form of 'dx' at end of expression - if not, add it
    std::string tmp = "d";
    tmp.push_back(integratedUpon);
    int pos = expression.find(tmp);
    if (pos == std::string::npos) { //expression not found
        expression.append(" ");
        expression.append(tmp);
    }

    coeff.resize(1);
    exponent.resize(1);
    op.resize(1);

    //split coefficients and exponents
    splitExpression(expression);
    
    //evaluate integal for each section partitioned by oeprators
    //a^x form has normal coeff, 0 for exponent, and true for integradedUponExponent
    //e^x form has 0 for coeff, 0 for exponent, and true for integratedUponExponent
    for (int i = 0; i < op.size(); i++) {
        evalTerm(i);
    }

    //build string and add C constant to end of string
    
    std::string finalString = stringBuilder(evalCoeff, evalExponent, evalOp, evalIntegratedUponExponent);

}

std::string Integral::simplify(std::string expression)
{

    /* Algebra Class implementation for later
    Algebra algebraExpression = Algebra(Expression);
    algebraExpression.format();
    std::string simpExpression = algebraExpression.simplifyExpression();
    return simpExpression;
    */

    //temp return to avoid errors
    return expression;
}

std::string Integral::stringBuilder(std::vector<double> evalCoeff, std::vector<int> evalExponent, std::vector<char> evalOp, std::vector<bool> evalIntegratedUponExponent) //add functionality
{
    return std::string();
}

char Integral::findIntegratedUpon(std::string expression)
{

    //find 'dx' form and take just the char after 'd'
    int pos = expression.find_last_of("d");
    if (pos != std::string::npos && pos!= expression.length-1)
    {
        return expression.at(pos + 1);
    } else {
        return 'x';
    }

}

void Integral::splitExpression(std::string expression) {
    
    expression = expression.substr(0, expression.length() - 1); //remove integratedUpon after 'd' (last char)

    int termIndex = 0;       //keeps track of which term for coeff, exponent, op vectors

    for (std::string::iterator it = expression.begin(); it != expression.end(); it++) {

        if (*it == ' ') { //skip spaces
            continue;
        } else if (*it == '+' || *it == '-' || 'd') { //operator of + or - or d is found
            op.push_back(*it);
            termIndex++;
        } else { //term is found

            if (*it == integratedUpon) { //no leading coefficient
                coeff.at(termIndex) = 1;
            } else { // has leading coefficient

                if (*it = 'e') {
                    coeff.at(termIndex) = 0;
                    ++it;
                } else {
                    std::string coeffTmp = ""; // coeffTmp holds digits until next non-digit char
                    while (*it != integratedUpon || *it != '/' || *it != ' ' || *it != '+' || *it != '-') {
                        coeffTmp.push_back(*it);
                        ++it;
                    }
                    double coeffDouble = stod(coeffTmp);
                    coeff.at(termIndex) = coeffDouble; // write parsed double value to coeff vector

                    coeffTmp = ""; // reset string to hold denominator if present
                    if (*it == '/') { // leading coefficient is a fraction

                        ++it;
                        while (*it != integratedUpon || *it != ' ' || *it != '+' || *it != '-') {
                            coeffTmp.push_back(*it);
                            ++it;
                        }
                        coeffDouble = coeff.at(termIndex) / stod(coeffTmp);
                        coeff.at(termIndex) = coeffDouble; // overwrite parsed double value in coeff vector

                    }
                }

            }

            if (*it == integratedUpon) { //integratedUpon is present in term

                if (*(it + 1) == '^') {
                    integratedUponExponent.at(termIndex) = false;
                    std::string exponentTmp = ""; // exponentTmp holds digits until next non-digit char
                    it += 2;                      // moves it over integratedUpon var and ^ char
                    while (*it != ' ' || *it != '+' || *it != '-' || *it != '/' || *it != 'd') {
                        exponentTmp.push_back(*it);
                        ++it;
                    }
                    int exponentInt = stoi(exponentTmp);
                    exponent.at(termIndex) = exponentInt;
                }

                // check for '/' (fraction) in it - if fraction, change coefficient for this term to match
                if (*it == '/') { //leading coefficient is a fraction

                    std::string coeffTmp = ""; //coeffTmp holds digits until next non-digit char
                    ++it;
                    while (*it != ' ' || *it != '+' || *it != '-') {
                        coeffTmp.push_back(*it);
                        ++it;
                    }
                    double coeffDouble = stod(coeffTmp);
                    coeff.at(termIndex) = coeffDouble; //overwrite parsed double value in coeff vector

                }

            } else {
                integratedUponExponent.at(termIndex) = false;
                exponent.at(termIndex) = 0;
                if (*it == '^' && *(it + 1) == integratedUpon) { //checks for ^x form
                    it += 2;
                    integratedUponExponent.at(termIndex) = true;
                }
            }

        }

    }

}

void Integral::evalTerm(int termIndex)
{

}
