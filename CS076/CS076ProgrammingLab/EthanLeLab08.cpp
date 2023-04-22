// Write your own version of a class template that will create a static queue of any data type.
// Demonstrate the class with a driver program.
// Ethan Le

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

// driver program to test the StaticQueue class
int main() {
    // Create a queue of integers with capacity 5
    StaticQueue<int, 5> intQueue;

    // Enqueue some elements
    cout << "Enqueueing 1..5" << endl;
    for (int i = 1; i <= 5; i++) {
        intQueue.enqueue(i);
    }

    // Dequeue and print some elements
    cout << "Dequeueing 3 elements" << endl;
    for (int i = 1; i <= 3; i++) {
        cout << intQueue.dequeue() << endl;
    }

    // Enqueue more elements
    cout << "Enqueueing 6..8" << endl;
    for (int i = 6; i <= 8; i++) {
        intQueue.enqueue(i);
    }

    // Print all elements in the queue
    cout << "Elements in queue: ";
    while (!intQueue.isEmpty()) {
        cout << intQueue.dequeue() << " ";
    }
    cout << endl;

    // test intQueue empty
    cout << "Testing empty queue" << endl;
    cout << "Dequeueing 1 element" << endl;
    intQueue.dequeue();
    
    // test intQueue full
    cout << "Testing full queue" << endl;
    cout << "Enqueueing 1..6" << endl;
    for (int i = 1; i <= 6; i++) {
        intQueue.enqueue(i);
    }
    

    // Create a queue of doubles with capacity 10
    StaticQueue<double, 10> doubleQueue;

    // Enqueue some elements
    cout << "Enqueueing 4.4, 2.2, 8.8" << endl;
    doubleQueue.enqueue(4.4);
    doubleQueue.enqueue(2.2);
    doubleQueue.enqueue(8.8);

    // Print all elements in the queue
    cout << "Elements in queue: ";
    while (!doubleQueue.isEmpty()) {
        cout << doubleQueue.dequeue() << " ";
    }
    cout << endl;

    // test doubleQueue peek, with some data
    cout << "Testing peek with data" << endl;
    cout << "Enqueueing 4.4, 2.2, 8.8" << endl;
    doubleQueue.enqueue(4.4);
    doubleQueue.enqueue(2.2);
    doubleQueue.enqueue(8.8);
    cout << "Peeking" << endl;
    cout << doubleQueue.peek() << endl;

    // test doubleQueue peek, with no data
    cout << "Testing peek with no data" << endl;
    cout << "Dequeueing 3 elements" << endl;
    for (int i = 1; i <= 3; i++) {
        doubleQueue.dequeue();
    }
    cout << "Peeking" << endl;
    cout << doubleQueue.peek() << endl;
    
    return 0;
}
