#include <iostream>
#include <queue>
using namespace std;

 queue<string> myQ; 
 
 for (string i = front; i < 12; i++)
 {
     cout << "enqueuing " << i << endl;
 }
 
 
 cout << "Size of myQ: " << myQ.size() << endl;
 cout << "The back of myQ" << myQ.rear() << endl;
 
 while(!myQ.empty())
 {
     cout << "dequing " << myQ.front() << endl;
 }


int main()
{
  
    queue<string> myQ;
    cout << myQ.size() << endl; // number of elements in queue
    
    myQ.dequeue();           //  Try to dequeue when the queue is empty. Should catch UNDERFLOW
    myQ.push("Fred");
    myQ.push("Liv");
    myQ.push("Julie");
    myQ.push("Rich");
    myQ.push("William");
    myQ.push("Olo");
    myQ.push("Xi");
    myQ.push("Chu");
    myQ.push("Annie");
    myQ.push("Carlos");
    myQ.push("Tuyet");
    myQ.push("Sue");
    myQ.push("Penny");
    
    cout << myQ.front() << endl; // index value
    cout << myQ.rear() << endl;  // index value
    cout << myQ.size() << endl;  // number of elements in queue
   
   
 
    myQ.dequeue(); 
    myQ.dequeue();  
    myQ.dequeue();     
   
    myQ.push("Olive");
    myQ.push("Jim");
    
    myQ.dequeue();  
    myQ.dequeue(); ;    
    
    cout << myQ.front() << endl; // name at front, if not empty
    cout << myQ.rear() << endl;
    cout << myQ.size() << endl;  // number of elements in queue

    return 0;
}
