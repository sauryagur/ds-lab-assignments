//  infix to postfix

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#define MAX_SIZE 100
using namespace std;

class CharStack {
public:
  int max_size;
  int top;
  char* elements;
  
  // default constructor
  CharStack() {
    this->top = -1;
    this->max_size = MAX_SIZE;
    this->elements = new char[MAX_SIZE];
  }
  
  // clean up elements
  ~CharStack() {
    delete[] elements;
  }
  
  void display() {
    if (top < 0) {
      return;
    }
    cout << "\t";
    for (int i = 0; i <= top; i++) {
      cout << elements[i] << " ";
    }
    cout << endl;
    return;
  }
  
  char pop() {
  if (this->isEmpty()) {
    cout << "UNDERFLOW CONDITION" << endl;
    return '\0';
  }
    top--;
    return elements[top+1];
  }
  
  char peek() {
  if (this->isEmpty()) {
    return '\0';
  }
    return elements[top];
  }
  
  void push(char character) {
    if (this->isFull()) {
      return;
    }
    top++;
    elements[top] = character;
  }
  
  bool isEmpty() {
    return (top == -1);
  }
  
  bool isFull() {
    return (top == max_size - 1);
  }
};

bool isOperator(char currentCharacter) {
  return (currentCharacter == '+' || 
  currentCharacter == '-' || 
  currentCharacter == '*' || 
  currentCharacter == '/' || 
  currentCharacter == '^')
}

// x > y
bool isHigherPriorityThan(char x, char y) {
  unordered_map<char, int> priority_lookup = {
    {'^', 3},
    {'*', 2},
    {'/', 2},
    {'+', 1},
    {'-', 1},
  };
  
  return priority_lookup[x] > priority_lookup[y]; 
}

string InfixToPostfix(string expression) {
  string answer = "";
  CharStack opStack;
  int n = expression.length();
  for (int i = 0; i < n; i++) {
    char currentCharacter = expression[i];
    // if its an operand add it to answer and move on
    if (!isOperator(currentCharacter)) {
      answer += currentCharacter;
      continue;
    }
    
    // otherwise check if it's an opening parenthesis
    if (currentCharacter == '(') {
      opStack.push('(');
      continue;
    }
    
    // otherwise check if it's an opening parenthesis
    if (currentCharacter == ')') {
      while (!opStack.isEmpty() && !opStack.peek() == '(') {
        answer += opStack.pop();
      }
      if (!opStack.isEmpty()) answer += opStack.pop();
      continue;
    }
    
    // otherwise if it has higher priority than operator stack's top    
    if (opStack.isEmpty() || isHigherPriorityThan(currentCharacter, opStack.peek())) {
      opStack.push(currentCharacter);
      continue;
    } else {
    // while your character isn't the highest priority
      while(isHigherPriorityThan(opStack.peek(), currentCharacter)) {
        answer += opStack.pop();
      }
      opStack.push(currentCharacter);
      continue;
    }
  }
  while(!(opStack.isEmpty())) {
    answer += opStack.pop();
  }
  return answer;
}

string reverse(string input) {
  string a = input;
  reverse(a.begin(), a.end());
  return a;
}

int main() {
  string expression;
  cout << "Enter expression: ";
  cin >> expression;
  cout << reverse(InfixToPostfix(reverse(expression)));
}
