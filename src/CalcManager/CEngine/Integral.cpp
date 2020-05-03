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

    //split coefficients and exponents
    splitExpression(expression);
    
    //evaluate integal for each section partitioned by oeprators
    //build string and add C constant to end of string
    
    std::string finalString = stringBuilder(coeff, exponent, op);

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
    return std::string();
}

std::string Integral::stringBuilder(std::vector<double> coeff, std::vector<int> exponent, std::vector<char> op) //add functionality
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

void Integral::splitExpression(std::string expression)
{

    //functionality here (run through string, first char is coefficient if not integratedUpon, char after ^ is exponent - if no integratedUpon, exponent is 0)
    //each coefficient should be paired with an exponent for each term

    //remove last char from expression (will be integratedUpon)

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
            }
            else { // has leading coefficient

                std::string coeffTmp = ""; // coeffTmp holds digits until next non-digit char
                while (*it != integratedUpon || *it != '/' || *it != ' ' || *it != '+' || *it != '-') {
                    coeffTmp.push_back(*it);
                    ++it;
                }
                double coeffDouble = stod(coeffTmp);
                coeff.at(termIndex) = coeffDouble; //write parsed double value to coeff vector

                coeffTmp = ""; //reset string to hold denominator if present
                if (*it == '/') { //leading coefficient is a fraction

                    ++it;
                    while (*it != integratedUpon || *it != ' ' || *it != '+' || *it != '-') {
                        coeffTmp.push_back(*it);
                        ++it;
                    }
                    coeffDouble = coeff.at(termIndex) / stod(coeffTmp);
                    coeff.at(termIndex) = coeffDouble; //overwrite parsed double value in coeff vector

                }

            }

            if (*it == integratedUpon) //integratedUpon is present in term
            {
                if (*(it + 1) == '^') {
                    std::string exponentTmp = ""; // exponentTmp holds digits until next non-digit char
                    it += 2;                      // moves it over integratedUpon var and ^ char
                    while (*it != ' ' || *it != '+' || *it != '-' || *it != '/' || *it != 'd') {
                        exponentTmp.push_back(*it);
                        ++it;
                    }
                    --it; //places iterator at last digit read
                    // write exponentTmp to exponent vector (parse string to int) ----------------------------------------------------------------------------------------------------------------------------
                    int exponentInt = stoi(exponentTmp);
                    exponent.at(termIndex) = exponentInt;
                }

                // check for '/' (fraction) in it+1 - if fraction, change coefficient for this term to match
            } else {

                exponent.at(termIndex) = 0;

            }
            //else for checking if x is present (x is not present)
            //set exponent for this term to 0
            //check for '/' (fraction) in it - if fraction, change coefficient for this term to match

        }

    }

}
