#include <iostream>
#include <stack>
#include <string>

using namespace std;

int isOperand(char x)
{
    if(x=='+' || x=='-' ||x=='*' ||x=='/' || x=='^' || x=='(' || x==')')
    {
        return 0;
    }
    return 1;
}


int precOutsideStack(char x)
{
    if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x=='*' || x=='/')
    {
        return 3;
    }
    else if(x=='^')
    {
        return 6;
    }
    else if(x=='(')
    {
        return 7;
    }
    else if(x==')')
    {
        return 0;
    }

    return -1;
}

int preceInsideStack(char x)
{
    if(x=='+' || x=='-')
    {
        return 2;
    }
    else if(x=='*' || x=='/')
    {
        return 4;
    }
    else if(x=='^')
    {
        return 5;
    }
    else if(x=='(')
    {
        return 0;
    }

    return -1;
}




string convertToPostfix(string infix)
{
    stack<char> stk;
    string postfix;

    int infixLen = (int)infix.length();
    int i=0;

    while(i != infixLen)
    {
        if(isOperand(infix[i]))
        {
            postfix += infix[i];
            i++;
        }
        else
        {
            if(stk.empty() || precOutsideStack(infix[i]) > preceInsideStack(stk.top()))
            {
                stk.push(infix[i]);
                i++;
            }
            else if (precOutsideStack(infix[i]) == preceInsideStack(stk.top()))
            {
//                this condition get executed only
//                when precOutsideStack(infix[i]) is closing bracket and
//                preceInsideStack(stk.top()) is opening bracket of same type
//                i.e.  both are parenthesis
//                then Pop stack once and Don't add brackets in postfix exp
                stk.pop();
                i++;
            }
            else
            {
                postfix += stk.top();
                stk.pop();
            }
        }
    }

    while (!stk.empty() && stk.top()!= ')')
    {
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}


int main()
{
    string infix = "((a+b)*c)-d^e^f";

    cout << convertToPostfix(infix) << endl;
    return 0;
}
