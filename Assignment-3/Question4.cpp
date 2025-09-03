#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[SIZE], postfix[SIZE];
    cout << "Enter infix: ";
    cin >> infix;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if (isalnum(c))
            postfix[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // pop '('
        }
        else
        {
            while (top != -1 && prec(stack[top]) >= prec(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    cout << "Postfix: " << postfix << endl;
}
