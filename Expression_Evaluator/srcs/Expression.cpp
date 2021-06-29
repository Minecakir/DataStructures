/*
* @author:Mine Çakýr -> 152120181058
* @author:Ezgi Özdikyar -> 152120171104
* @date: 09.12.2020
*/

#include <string>
#include <stack>
#include <iostream>
using namespace std;
int controlOperator(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
int calculate(char op, int a, int b) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
}

string Infix2Postfix(string& s)
{
    stack<char> S;
    string result;
    int i = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            result += " ";
        }
        if ((s[i] >= '0' && s[i] <= '9'))
        {
            result += s[i];
        }
        //When ’(’ is encountered, push it        
        else if (s[i] == '(')
        {
            S.push('(');
        }
        //When ’)’ is encountered, pop all symbols off the stack until ’(’ is encountered
        else if (s[i] == ')')
        {
            while (!S.empty() && S.top() != '(')
            {
                result += S.top();
                S.pop();
            }
            if (S.top() == '(')
            {
                char c = S.top();
                S.pop();
            }
        }

        //When an operator, +, -, *, / , is encountered,
        //pop symbols off the stack until you encounter a symbol that has lower priority

        else {
            while (!S.empty() && controlOperator(s[i]) <=
                controlOperator(S.top()))
            {
                result += S.top();
                S.pop();
            }
            S.push(s[i]);
        }
    }
    //Push the encountered operator to the stack

    while (!S.empty())
    {
        result += S.top();
        S.pop();
    }
    return result;
}// end-Infix2Postfix

///----------------------------------------------------------------------------------
/// Given a string in post-fix notation, evaluates it and returns the result
/// 

int EvaluatePostfixExpression(string& s)
{
	stack<int> S;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') continue;

		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {

			int value2 = S.top();
			S.pop();
			int value1 = S.top();
			S.pop();

			int result = calculate(s[i], value1, value2);

			S.push(result);
		}
		else if ((s[i] <= '9' && s[i] >= '0'))
		{
			int operand = 0;
			while (i < s.length() && (s[i] <= '9' && s[i] >= '0')) {
				operand = (operand * 10) + (s[i] - '0');
				i++;
			}

			i--;
			S.push(operand);
		}
	}

	return S.top();
}
// end-EvaluatePostfixExpression
