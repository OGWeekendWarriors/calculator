/*
This class was created by Nico Comendador for the purpose of
WSU CEG 4110-01. This class will handle and house all of the
functionality for any algebraic operations for a symbolic
calculator feature add on to the Microsoft Calculator.
*/
#include "Algebra.h"
#include <stack>

using namespace std;

///\return Constructor will instantiate the class variables.
Algebra::Algebra(string expression)
{
    newExpression(expression);
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
    int result = evaluate(expression);
    return to_string(result);
}

///\return This method ensures that the expression has spaces
/// in between each token. Due to how this class parses and
/// simplifies things, it is best to first format before
/// continuing.
string Algebra::format(string expression)
{
    bool space = false;
    for (int x = 0; x < expression.length(); x++)
    {
        if (space)
        {
            expression.insert(x, " ");
            space = false;
        }
        else
        {
            space = true;
        }
    }

    return expression;
}

///\return This method is responsible for parsing through
/// and evaluating the expression. Once evaluated, we can
/// then simplify.
inline int Algebra::evaluate(string tokens)
{
    int i;

    stack<int> values;

    stack<char> ops;

    for (i = 0; i < tokens.length(); i++)
    {
        if (tokens[i] == ' ')
            continue;

        else if (tokens[i] == '(')
        {
            ops.push(tokens[i]);
        }

        else if (isdigit(tokens[i]))
        {
            int val = 0;

            while (i < tokens.length() && isdigit(tokens[i]))
            {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            values.push(val);
        }
        else if (tokens[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            if (!ops.empty())
                ops.pop();
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            ops.push(tokens[i]);
        }
    }

    while (!ops.empty())
    {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.top();
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

///\return This method allows the algebra object to create
/// new expressions without having to instantiate a new
/// algebra object. The constructor makes use of this.
void Algebra::newExpression(string expression)
{
    clearExpression();
    this->unformattedExpression = expression;
    this->expression = format(expression);
}

///\return This function is created so that a user may solve for a
/// variable in the symbolic calculator option.
string Algebra::solveForVariable()
{
    int n = unformattedExpression.size(), sign = 1, coeff = 0;
    int total = 0, i = 0;

    for (int j = 0; j < n; j++)
    {
        if (unformattedExpression[j] == '+' || unformattedExpression[j] == '-')
        {
            if (j > i)
                total += sign * stoi(unformattedExpression.substr(i, j - i));
            i = j;
        }

        else if (unformattedExpression[j] == 'x')
        {
            if ((i == j) || unformattedExpression[j - 1] == '+')
                coeff += sign;
            else if (unformattedExpression[j - 1] == '-')
                coeff -= sign;
            else
                coeff += sign * stoi(unformattedExpression.substr(i, j - i));
            i = j + 1;
        }
    }

    if (i < n)
        total += sign * stoi(unformattedExpression.substr(i));

    if (coeff == 0 && total == 0)
        return "Infinite solutions";

    if (coeff == 0 && total)
        return "No solution";

    int ans = -total / coeff;
    return "x = " + to_string(ans);
}

///\return A getter function is useful for a parent class to get
/// more information on what expression is being handled. It will
/// reutrn the raw unformatted version to avoid any complications.
string Algebra::getExpression()
{
    return unformattedExpression;
}

///\return This function is added for a manager class or a parent
/// class to empty the variables. It's purpose is to ensure that
/// the variables are cleared of everything before having something
/// set into them.
void Algebra::clearExpression()
{
    this->unformattedExpression = "";
    this->expression = "";
}
