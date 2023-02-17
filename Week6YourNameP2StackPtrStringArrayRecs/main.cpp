#include <iostream>
using namespace std;

//created a class Record, this stores our variables.
class Record
{
public:
    string firstName;
    string lastName;
    int phone;
    //Constructor passing our parameters
    Record(string fN, string lN, int p);
    Record();
};
Record::Record(string fN, string lN, int p)
{
    firstName = fN;
    lastName = lN;
    phone = p;
}

Record::Record()
{
}
//Created a class Stack.
class Stack
{
    //Initalized top as -1
    int top = -1;

public:
    Stack();
    Record array[6]; // This array holds our record objects.

    //Push function to add records.
    void push(Record r)
    {
        if(top >= 5) {
            cout << "stack is full" << endl;
        } else {
            array[++top] = r;
            cout << "push is complete" << endl;
        }
    }
    
    //Pop function to remove records.
    void pop()
    {
        if(top < 0) {
            cout << "Stack is empty" << endl;

        } else {

            Record r = array[top--];
            cout << "Pop is complete" << endl;
        }
    }
};

Stack::Stack()
{
}

int main()
{
    cout << "Michael Kuperman: 9/26/2021" << endl;
    
    //Declare an instance of the Stack
    Stack s;
    
    //Creating the records
    Record r1("Michael", "Kuperman", 4156063214);
    Record r2("Andrew", "Mop", 4151724937);
    Record r3("Jen", "Sharpe", 4153845503);
    Record r4("Dylan", "Gutirez", 4152834762);
    Record r5("Rob", "Biggy", 4155032214);
    Record r6("Bob", "Julio", 4157283049);

    //Pushing the records one at a time
    s.push(r1);
    s.push(r2);
    s.push(r3);
    s.push(r4);
    s.push(r5);
    s.push(r6);

    //Popping the records one at a time
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
