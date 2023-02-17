#include <iostream>
using namespace std;

struct Node {
    string data;
    Node *prev, *next;
    // Function to get a new node
    Node(string data)
    {
        this->data = data;
        this->prev = this->next = NULL;
    }
};

class queue
{
    Node* head;
    Node* rear;
    int Size;

public:
    queue()
    {
        head = rear = NULL;
        Size = 0;
    }

    // Operations on queue
    void enqueue(string data);
    string dequeue();
    string front();
    string end();
    int size();
    bool isEmpty();
};

// Function to check whether deque is empty or not
bool queue::isEmpty()
{
    return (head == NULL);
}

// Function to return the number of elements in the deque
int queue::size()
{
    return Size;
}

// Function to insert an element at the rear end
void queue::enqueue(string data)
{
    Node* newNode = new Node(data);
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if(newNode == NULL)
        cout << "OverFlow\n";
    else {
        // If queue is empty
        if(rear == NULL)
            head = rear = newNode;

        // Inserts node at the rear end
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        Size++;
    }
}

// Function to delete the element from the front end
string queue::dequeue()
{
    string data = "";
    // If queue is empty then
    // 'Underflow' condition
    if(isEmpty())
        cout << "UnderFlow\n";

    // Deletes the node from the front end and makes the adjustment in the links
    else {
        Node* temp = head;
        data = temp->data;
        head = head->next;

        // If only one element was present
        if(head == NULL)
            rear = NULL;
        else
            head->prev = NULL;
        free(temp);

        Size--;
    }
    return data;
}

// Function to return the element  at the front end
string queue::front()
{
    // If deque is empty, then returns
    if(isEmpty())
        return "!empty!";
    return head->data;
}

// Function to return the element at the rear end
string queue::end()
{
    // If deque is empty, then return
    if(isEmpty())
        return "!empty!";
    return rear->data;
}

int main()
{
    cout << "Michael Kuperman: 10/3/2021" << endl;
    queue myQ;                  //(Use default constructor to initialize front and end to NULL.)
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
    cout << myQ.front() << endl; // name at front, if not empty
    cout << myQ.end() << endl;   // name at end, if not empty
    cout << myQ.size() << endl;  // number of elements in queue
    cout << myQ.dequeue() << endl;
    cout << myQ.dequeue() << endl;
    cout << myQ.dequeue() << endl;
    myQ.enqueue("Olive");
    myQ.enqueue("Jim");
    cout << myQ.dequeue() << endl;
    cout << myQ.dequeue() << endl;
    cout << myQ.front() << endl; // name at front, if not empty
    cout << myQ.end() << endl;   // name at end, if not empty
    cout << myQ.size() << endl;  // number of elements in queue

    return 0;
}
