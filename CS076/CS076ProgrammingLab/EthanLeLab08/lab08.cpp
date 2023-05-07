// Write your own version of a class template that will create a static queue of any data type.
// Demonstrate the class with a driver program.
// Ethan Le
#include <iostream>

using namespace std;
// StaticQueue of any type
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

// Driver program

int main() {
    // Create a queue of integers with capacity 5
    StaticQueue<int, 5> intQueue;

    // Enqueue some elements
    cout << "Enqueueing 1..5" << endl;
    for (int i = 1; i <= 5; i++) {
        intQueue.enqueue(i);
    }

    // Dequeue some elements
    cout << "Dequeueing 1..3" << endl;
    for (int i = 1; i <= 3; i++) {
        cout << intQueue.dequeue() << endl;
    }

    // Enqueue some more elements
    cout << "Enqueueing 6..8" << endl;
    for (int i = 6; i <= 8; i++) {
        intQueue.enqueue(i);
    }

    // Dequeue some more elements
    cout << "Dequeueing 4..8" << endl;
    for (int i = 4; i <= 8; i++) {
        cout << intQueue.dequeue() << endl;
    }

    // Enqueue some more elements
    cout << "Enqueueing 9..11" << endl;
    for (int i = 9; i <= 11; i++) {
        intQueue.enqueue(i);
    }

    // Dequeue some more elements
    cout << "Dequeueing 5..11" << endl;
    for (int i = 5; i <= 11; i++) {
        cout << intQueue.dequeue() << endl;
    }

    // Enqueue some more elements
    cout << "Enqueueing 12..14" << endl;
    for (int i = 12; i <= 14; i++) {
        intQueue.enqueue(i);
    }

    // Dequeue some more elements
    cout << "Dequeueing 6..14" << endl;
    for (int i = 6; i <= 14; i++) {
        cout << intQueue.dequeue() << endl;
    }

    // Enqueue some more elements
    cout << "Enqueueing 15..17" << endl;
    for (int i = 15; i <= 17; i++) {
        intQueue.enqueue(i);
    }

    // Dequeue some more elements
    cout << "Dequeueing 7..17" << endl;
    for (int i = 7; i <= 17; i++) {
        cout << intQueue.dequeue() << endl;
    }

    // Test a double queue
    StaticQueue<double, 5> doubleQueue;
    //Enqueue 5 elements
    cout << "Enqueueing 1.1..5.5" << endl;
    for (double i = 1.1; i <= 5.5; i += 1.0) {
        doubleQueue.enqueue(i);
    }

    // Test empty and full
    cout << "Is doubleQueue empty? " << boolalpha << doubleQueue.isEmpty() << endl;
    cout << "Is doubleQueue full? " << boolalpha << doubleQueue.isFull() << endl;

    //Enqueue 1 more element
    cout << "Enqueueing 6.6" << endl;
    doubleQueue.enqueue(6.6);

    //Dequeue till empty
    cout << "Dequeueing 1.1..6.6" << endl;
    while (!doubleQueue.isEmpty()) {
        cout << doubleQueue.dequeue() << endl;
    }

    // Test empty and full
    cout << "Is doubleQueue empty? " << boolalpha << doubleQueue.isEmpty() << endl;
    cout << "Is doubleQueue full? " << boolalpha << doubleQueue.isFull() << endl;

    //Test peek
    cout << "Peeking at doubleQueue" << endl;
    cout << doubleQueue.peek() << endl;
    return 0;
}
