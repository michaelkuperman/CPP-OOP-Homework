#include <iostream>
#define SIZE 12
using namespace std;

class queue
{
public:
    string items[SIZE];
    int Front, Rear;


    queue()
    {
        Front = -1;
        Rear = -1;
    }
    // Check if the queue is full
    bool isFull()
    {
       
        if(Front == 0 && Rear == SIZE - 1)  {
            return true;
            
        }
       
        if(Front == Rear + 1) {
            //return true;
            
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
    void enqueue(string element)
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

    string dequeue()
    {
        if(isEmpty()) {
            cout << "UNDERFLOW" << endl;
            return "";
        }
        Rear = (Rear - 1) % SIZE;
        string a = items[0];
        
        for (int b = 0; b < 11; b++){
            items[b] = items[b+1];
            
        }

        return a;
    }

    int front()
    {
        if(isEmpty()) {
            cout << "UnderFlow" << endl;
            return 0;
        }
        return Front;
    }

    int rear()
    {
        if(isFull()) {

            return 11;
        }
        return Rear;
    }

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
    cout << "Michael Kuperman: 10/3/2021" << endl;
    queue myQ;                  //(Use default constructor to initialize front and end to zero.)
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
    return 0;
}
