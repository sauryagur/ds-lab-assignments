#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char expr[SIZE];
    cout << "Enter postfix: ";
    cin >> expr;
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char c = expr[i];
        if (isdigit(c))
            push(c - '0');
        else
        {
            int b = pop();
            int a = pop();
            if (c == '+')
                push(a + b);
            else if (c == '-')
                push(a - b);
            else if (c == '*')
                push(a * b);
            else if (c == '/')
                push(a / b);
        }
    }
    cout << "Result: " << stack[top] << endl;
}
