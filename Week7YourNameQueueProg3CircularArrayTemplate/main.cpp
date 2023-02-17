#include <iostream>
#define SIZE 12
using namespace std;

template <class T>

class queue
{
public:
    T items[SIZE];
    int Front, Rear;

    queue()
    {
        Front = -1;
        Rear = -1;
    }
    // Check if the queue is full
    bool isFull()
    {

        if(Front == 0 && Rear == SIZE - 1) {
            return true;
        }

        if(Front == Rear + 1) {
            
        }
        return false;
    }
    // Check if the queue is empty
    bool isEmpty()
    {
        if(Front == -1)
            return true;
        else
            return false;
    }
    // Adding an element
    void enqueue(T element)
    {
        if(isFull()) {
            cout << "OverFLOW" << endl;
        } else {
            if(Front == -1)
                Front = 0;
            Rear = (Rear + 1) % SIZE;
            items[Rear] = element;
            cout << "Inserted " << element << endl;
        }
    }
    //
    T dequeue()
    {
        if(isEmpty()) {
            cout << "UNDERFLOW" << endl;
            return items[0];
        }
        Rear = (Rear - 1) % SIZE;
        T a = items[0];

        for(int b = 0; b < 11; b++) {
            items[b] = items[b + 1];
        }

        return a;
    }
    //Keeps track of the  vaule at the front of the queue
    int front()
    {
        if(isEmpty()) {
            cout << "UnderFlow" << endl;
            return 0;
        }
        return Front;
    }
    //Keeps track of the vaule at the back of the queue
    int rear()
    {
        if(isFull()) {

            return 11;
        }
        return Rear;
    }
    //Returns the size of the Queue
    int size()
    {
        // Function to size of Circular Queue
        int i, count = 0;
        if(isEmpty()) {
            return 0;
        } else {
            for(i = Front; i != Rear; i = (i + 1) % SIZE)
                count++;

            return (count + 1);
        }
    }
};

int main()
{
    cout << "Michael Kuperman: 10/10/2021" << endl;
    queue<string> myQ;          //(Use default constructor to initialize front and end to zero.)
    cout << myQ.size() << endl; // number of elements in queue
    myQ.dequeue();              //  Try to deqeue when the queue is empty. Should catch UNDERFLOW
    myQ.enqueue("Fred");
    myQ.enqueue("Liv");
    myQ.enqueue("Julie");
    myQ.enqueue("Rich");
    myQ.enqueue("William");
    myQ.enqueue("Olo");
    myQ.enqueue("Xi");
    myQ.enqueue("Chu");
    myQ.enqueue("Annie");
    myQ.enqueue("Carlos");
    myQ.enqueue("Tuyet");
    myQ.enqueue("Sue");
    myQ.enqueue("Penny");        // Add 1 to many, should catch OVERFLOW
    cout << myQ.front() << endl; // index value
    cout << myQ.rear() << endl;  // index value
    cout << myQ.size() << endl;  // number of elements in queue
    cout << myQ.dequeue() << endl;
    cout << myQ.dequeue() << endl;
    cout << myQ.dequeue() << endl;
    myQ.enqueue("Olive");
    myQ.enqueue("Jim");
    cout << myQ.dequeue() << endl;
    cout << myQ.dequeue() << endl;
    cout << myQ.front() << endl; // index value
    cout << myQ.rear() << endl;  // index value
    cout << myQ.size() << endl;  // number of elements in queue

    cout << "-------------End of String template-----------" << endl;

    queue<int> myIntQ;
    cout << myIntQ.size() << endl;
    myIntQ.dequeue();
    myIntQ.enqueue(1);
    myIntQ.enqueue(2);
    myIntQ.enqueue(3);
    myIntQ.enqueue(4);
    myIntQ.enqueue(5);
    myIntQ.enqueue(6);
    myIntQ.enqueue(7);
    myIntQ.enqueue(8);
    myIntQ.enqueue(9);
    myIntQ.enqueue(10);
    myIntQ.enqueue(11);
    myIntQ.enqueue(12);
    myIntQ.enqueue(13);
    cout << myIntQ.front() << endl;
    cout << myIntQ.rear() << endl;
    cout << myIntQ.size() << endl;

    myIntQ.dequeue();
    myIntQ.dequeue();
    myIntQ.dequeue();

    myIntQ.enqueue(14);
    myIntQ.enqueue(15);

    myIntQ.dequeue();
    myIntQ.dequeue();

    cout << myIntQ.front() << endl;
    cout << myIntQ.rear() << endl;
    cout << myIntQ.size() << endl;

    cout << "-------------End of Int template-----------" << endl;

    queue<char> myCharQ;
    myCharQ.dequeue();
    myCharQ.enqueue('A');
    myCharQ.enqueue('B');
    myCharQ.enqueue('C');
    myCharQ.enqueue('D');
    myCharQ.enqueue('E');
    myCharQ.enqueue('F');
    myCharQ.enqueue('G');
    myCharQ.enqueue('H');
    myCharQ.enqueue('I');
    myCharQ.enqueue('J');
    myCharQ.enqueue('K');
    myCharQ.enqueue('L');
    myCharQ.enqueue('M');

    cout << myCharQ.front() << endl;
    cout << myCharQ.rear() << endl;
    cout << myCharQ.size() << endl;

    myCharQ.dequeue();
    myCharQ.dequeue();
    myCharQ.dequeue();

    myCharQ.enqueue('N');
    myCharQ.enqueue('O');

    myCharQ.dequeue();
    myCharQ.dequeue();

    cout << myCharQ.front() << endl;
    cout << myCharQ.rear() << endl;
    cout << myCharQ.size() << endl;

    cout << "---------------End of Char template--------------" << endl;

    queue<double> myDoubleQ;
    cout << myDoubleQ.size() << endl;
    myDoubleQ.dequeue();
    myDoubleQ.enqueue(3.20);
    myDoubleQ.enqueue(6.40);
    myDoubleQ.enqueue(8.45);
    myDoubleQ.enqueue(3.12);
    myDoubleQ.enqueue(1.70);
    myDoubleQ.enqueue(8.34);
    myDoubleQ.enqueue(4.85);
    myDoubleQ.enqueue(9.23);
    myDoubleQ.enqueue(8.43);
    myDoubleQ.enqueue(6.95);
    myDoubleQ.enqueue(8.09);
    myDoubleQ.enqueue(6.95);
    myDoubleQ.enqueue(8.09);
    myDoubleQ.enqueue(1.31);
    myDoubleQ.enqueue(2.52);

    cout << myDoubleQ.front() << endl;
    cout << myDoubleQ.rear() << endl;
    cout << myDoubleQ.size() << endl;

    myDoubleQ.dequeue();
    myDoubleQ.dequeue();
    myDoubleQ.dequeue();

    myDoubleQ.enqueue(7.32);
    myDoubleQ.enqueue(9.94);
    
    myDoubleQ.dequeue();
    myDoubleQ.dequeue();
    
    
    cout << myDoubleQ.front() << endl;
    cout << myDoubleQ.rear() << endl;
    cout << myDoubleQ.size() << endl;
    
    cout << "----------End of Double Template--------------" << endl;
}
