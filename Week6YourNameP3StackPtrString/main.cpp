#include <iostream>
using namespace std;

// create the stack class
class Stack
{
public:
    string data;
    Stack* next;
    Stack(string vaule)
    {
        data = vaule;
        next = NULL;
    }
};

Stack* top = NULL;
int size = 10;

// newPerson function
void newPerson(string vaule)
{

    Stack* node = new Stack(vaule);
    node->data = vaule;
    node->next = top;
    top = node;
    cout << vaule << "; is getting pushed." << endl;
}

bool isEmpty()
{
    if(top == NULL && size == 0)
        return true;
    else
        return false;
}

void pop()
{
    if(top == NULL)
        cout << "Stack is empty" << endl;
    else {
        cout << "The popped element is " << top->data << endl;
        top = top->next;
    }
}

void showTop()
{
    if(isEmpty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Element at the top is: " << top->data << endl;
}

int main()
{
    cout << "Michael Kuperman: 9/26/2021" << endl;
    newPerson("able");
    newPerson("bread");
    newPerson("corn");
    newPerson("dog");
    newPerson("elephant");
    newPerson("frog");
    newPerson("ground");
    newPerson("House");
    newPerson("Italy");
    newPerson("Jam");
    cout << size << endl;

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    return 0;
}
