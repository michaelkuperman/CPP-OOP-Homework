#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    int priority;
};

// Implement prioroty queue class
class PriorityQueue
{

private:
    Node array[10];
    int capacity;
    int front;
    int rear;

public:
    PriorityQueue()
    {
        front = 0;
        rear = 0;
        capacity = 10;
    }

    // adding elements

    void enQueue(string name, int priority)
    {
        if(isFull()) {
            cout << "Error : Queue Full" << endl;
            return;
        }
        Node node;
        node.name = name;
        node.priority = priority;
        array[rear] = node;
        rear = (rear + 1) % capacity;
        displayElements();
    }

    // popping elements
    void deQueue()
    {
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        if(rear > front) {
            int highPriorityIndex = findMaxPriorityNode(front, rear - 1);
            shiftElements(highPriorityIndex, rear - 1);
        } else {
            int indexOne = findMaxPriorityNode(front, capacity - 1);
            int indexTwo = findMaxPriorityNode(0, rear - 1);

            if(array[indexOne].priority >= array[indexTwo].priority) {
                shiftElements(front, capacity - 1);
                return;
            }
            shiftElements(0, rear);
        }
        rear = (rear - 1) % capacity;
        displayElements();
    }

    bool isEmpty()
    {
        if(front == rear)
            return true;
        return false;
    }

    bool isFull()
    {
        if((rear + 1) % capacity == front)
            return true;
        return false;
    }

    // showing elements
    void displayElements()
    {
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "The contents of th Queue are : ";
        if(rear > front) {
            printElems(front, rear - 1);
        } else {
            printElems(front, capacity - 1);
            printElems(0, rear - 1);
        }
        cout << endl;
    }

    /**
     *
     * Private helper methods
     */
private:
    int findMaxPriorityNode(int start, int end)
    {
        int highPriority = -1;
        int highPriorityIndex = -1;
        for(int i = start; i <= end; i++) {
            Node node = array[i];
            if(node.priority > highPriority) {
                highPriorityIndex = i;
                highPriority = node.priority;
            }
        }
        return highPriorityIndex;
    }

    // shifting elements
    void shiftElements(int start, int end)
    {
        for(int i = start; i < end; i++) {
            array[i] = array[i + 1];
        }
    }
    // printing elements
    void printElems(int start, int end)
    {
        for(int i = start; i <= end; i++) {
            cout << "[" << array[i].name << "," << array[i].priority << "] ";
        }
    }
};

int main()
{
    cout << "Michael Kuperman: 10/24/2021" << endl;
    PriorityQueue p;
    p.enQueue("Rog", 3);
    p.enQueue("Fred", 1);
    p.enQueue("Tuyet", 9);
    p.enQueue("Jose", 6);
    p.deQueue();
    p.enQueue("Jing", 2);
    p.enQueue("Xi", 5);
    p.enQueue("Moe", 3);
    p.deQueue();
    p.deQueue();
    p.deQueue();
    p.deQueue();
    p.deQueue();
    p.deQueue();

    return 0;
}