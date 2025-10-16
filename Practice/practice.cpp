#include <iostream>
using namespace std;

class LinearArrayQueue {
public:
  int max_size;
  int* elements;
  int rear;
  
  LinearArrayQueue() {
    max_size = 12;
    elements = new int[max_size];
    int rear = -1;
  }
  
  LinearArrayQueue(int size) {
    max_size = size;
    elements = new int[max_size];
    int rear = 0;
  }
  
  ~LinearArrayQueue() {
    delete[] elements;
  }
  
  bool isEmpty() {
    return (rear == -1);
  }
  
  bool isFull() {
    return (rear == max_size - 1);
  }
  
  void enqueue(int value) {
    if (!this->isFull()) {
      rear++;
      elements[rear] = value;
    }
  }
  
  int dequeue() {
    if (!this->isEmpty()) {
      int popped = elements[0];
      for (int i = 1; i < rear; i++) {
        elements[i-1] = elements[i];
      }
      rear--;
      return popped;
    }
    return -1;
  }
  
  int peek_rear() {
    if (!this->isEmpty()) {
      return elements[rear];
    }
    return -1;
  }
  
  int peek_() {
    if (!this->isEmpty()) {
      return elements[0];
    }
    return -1;
  }
};
  
int main() {
  
}
