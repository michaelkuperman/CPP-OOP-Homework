#include <iostream>
// to include the stack
#include <stack> 
using namespace std;


int main()
{
    cout << "Michael Kuperman: 9/26/2021" << endl;
    //declaring the stack vaules
	stack<string> myStack;  
    
    //inputting the 10 
    myStack.push("able");
    myStack.push("bread");
    myStack.push("corn");
    myStack.push("dog");
    myStack.push("elephant");
    myStack.push("frog");
    myStack.push("ground");
    myStack.push("house");
    myStack.push("italy");
    myStack.push("Jam");
    
    
    // Print the top of the Stack
    cout << "The Top of the Stack: " << myStack.top() << endl; 
    
    //Popping the elements of the stack
    cout << "Popping the elements: " << endl;
    while(!myStack.empty())
    {
        cout << myStack.top() << " " << endl;
        myStack.pop();
    }
    
	return 0;
}
