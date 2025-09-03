#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

bool isBalanced(char expr[])
{
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
                return false;
            char popped = pop();
            if ((ch == ')' && popped != '(') ||
                (ch == '}' && popped != '{') ||
                (ch == ']' && popped != '['))
                return false;
        }
    }
    return (top == -1);
}

int main()
{
    char expr[SIZE];
    cout << "Enter expr: ";
    cin >> expr;
    if (isBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}
