#include <iostream>
using namespace std;

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int x)
{
    if (top == SIZE - 1)
    {
        cout << "Overflow\n";
        return;
    }
    top++;
    stack[top] = x;
}

int pop()
{
    if (top == -1)
    {
        cout << "Underflow\n";
        return -1;
    }
    int val = stack[top];
    top--;
    return val;
}

void display()
{
    if (top == -1)
    {
        cout << "Empty\n";
        return;
    }
    cout << "Stack: ";
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

bool isEmpty()
{
    return (top == -1);
}

bool isFull()
{
    return (top == SIZE - 1);
}

int peek()
{
    if (top == -1)
        return -1;
    return stack[top];
}

int main()
{
    int ch, val;
    while (1)
    {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.isEmpty 6.isFull 7.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            push(val);
            break;
        case 2:
            cout << "Popped: " << pop() << endl;
            break;
        case 3:
            cout << "Peek: " << peek() << endl;
            break;
        case 4:
            display();
            break;
        case 5:
            cout << (isEmpty() ? "Empty\n" : "Not Empty\n");
            break;
        case 6:
            cout << (isFull() ? "Full\n" : "Not Full\n");
            break;
        case 7:
            return 0;
        }
    }
}
