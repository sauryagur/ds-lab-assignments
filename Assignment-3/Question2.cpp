#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char x)
{
    if (top < SIZE - 1)
        stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

void reverse(char str[])
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
        push(str[i]);
    for (int i = 0; i < len; i++)
        str[i] = pop();
}

int main()
{
    char str[SIZE];
    cout << "Enter string: ";
    cin >> str;
    reverse(str);
    cout << "Reversed: " << str << endl;
    return 0;
}
