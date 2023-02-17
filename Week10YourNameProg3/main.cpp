#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int priority;
    string name;
    node *connect;
};

class Priority_Queue
{
    private:
        node *top;
    public:
        Priority_Queue()
        {
            top = NULL;
        }
        
        void enqueue(string name, int priority)
        {
            node *read, *q;
            read = new node;
            read->name = name;
            read->priority = priority;
            if (top == NULL || priority > top->priority)
            {
                read->connect = top;
                top = read;
            }
            else
            {
                q = top;
                while (q->connect != NULL && q->connect->priority >= priority)
                    q=q->connect;
                read->connect = q->connect;
                q->connect = read;
            }
        }
        
        void dequeue()
        {
            node *read;
            if(top == NULL)
                cout<<"Priority_Queue Underflow\n";
            else
            {
                read = top;
                cout<<"Deleted value is: "<<read->name<<endl;
                top = top->connect;
                free(read);
            }
        }
        
        void display()
        {
            node *input;
            input = top;
            if (top == NULL)
                cout<<"Queue is empty\n";
            else
            {    cout<<"Queue is :\n";
                cout<<"Priority       value\n";
                while(input != NULL)
                {
                    cout<<input->priority<<"                 "<<input->name<<endl;
                    input = input->connect;
                }
            }
        }
};

int main()
{
    cout << "Michael Kuperman: 10/24/2021" <<endl;
    int option, priority;string value;
    Priority_Queue pq;
    do
    {
        cout<<"1.Enqueue\n";
        cout<<"2.Dequeue\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your option : ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Input the name to be added in the queue : ";
            cin>>value;
            cout<<"Enter its priority : ";
            cin>>priority;
            pq.enqueue(value, priority);
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            break;
        default :
            cout<<"Wrong option\n";
        }
    }
    while(option != 4);
    return 0;
}