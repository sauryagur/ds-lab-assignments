#include <iostream>
#define MAX_SIZE 10
using namespace std;



class Stack {
public:
	int max_size;
	int* elements = nullptr;
	int top = -1;
	
	// default constructor
	Stack() {
	  max_size = MAX_SIZE;
	  elements = new int[max_size];
	  top = -1;
	  cout << "Created new stack: " << this->elements << endl;
	}
	
	Stack(int size) {
	  this->max_size = size;
	  elements = new int[max_size];
	  top = -1;
	  cout << "Created new stack: " << this->elements << endl;
	}
	
	// clean up
	~Stack() {
	  delete[] elements;
	}
	
	void push(int element) {
	  if (top == max_size - 1) {
	    cout << "OVERFLOW CONDITION" << endl;
	    return;
	  }
	  top++;
	  *(elements + top) = element;
	  this->display();
	}
	
	void pop() {
	  if (top == -1) {
	    cout << "UNDERFLOW CONDITION" << endl;
	    return;
	  }
	  top--;
	  this->display();
	}
	void display() {
	  if (top == -1) {
	    cout << "<EMPTY STACK>" << endl;
	    return;
	  }
	  cout << "[";
	  for (int i = 0; i < top; i++) {
	    cout << *(elements + i) << ", ";
	  }
	  cout << *(elements + top) << "]" << endl;
	}
	
	int peek() {
	  if (top == -1) {
	    return -1;
	  }
	  return *(elements + top);
	}
};

int main() {
  Stack s1;
  s1.display();
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.peek();
  s1.push(4);
  s1.peek();
  s1.pop();
  s1.peek();
}
