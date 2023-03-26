// Write your own version of a class template that will create a static queue of any data type.
// Demonstrate the class with a driver program.
// Ethan Le

#include <iostream>
using namespace std;

template <class T, int capacity>
class StaticQueue {
private:
    T data[capacity];
    int front, rear, size;

public:
    StaticQueue() : front(0), rear(0), size(0) {}

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void enqueue(T element) {
        if (isFull()) {
            cout << "Error: Queue is full" << endl;
            return;
        }
        data[rear] = element;
        rear = (rear + 1) % capacity;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl;
            return T();
        }
        T element = data[front];
        front = (front + 1) % capacity;
        size--;
        return element;
    }

    T peek() const {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl;
            return T();
        }
        return data[front];
    }
};

int main() {
    // Create a queue of integers with capacity 5
    StaticQueue<int, 5> intQueue;

    // Enqueue some elements
    cout << "Enqueueing 1..5" << endl;
    for(int i=1; i<=5; i++){
        intQueue.enqueue(i);
    }
    cout << "Dequeueing remaining elements" << endl;
    while(!intQueue.isEmpty()){
        cout << intQueue.dequeue() << endl;
    }

   // Enqueue some elements
    cout << "Enqueueing 11..15" << endl;
    for(int i=11; i<=15; i++){
        intQueue.enqueue(i);
    }

    // Enqueue one more element (queue is full)
    cout << "Enqueueing 16" << endl;
    intQueue.enqueue(16);

    // Dequeue and print remaining elements
    cout << "Dequeueing remaining elements" << endl;
    while(!intQueue.isEmpty()){
        cout << intQueue.dequeue() << endl;
    }

    // Dequeue one more element (queue is empty)
    cout << "Dequeueing one more element" << endl;
    intQueue.dequeue();

    return 0;
}
