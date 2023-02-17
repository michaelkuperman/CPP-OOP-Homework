#include <iostream>
using namespace std;

int myFunction(int integer) 
{
    //creating a return to meet a condition for the recursion
    if(integer==1)
        {
            cout << "1 = " << endl;
           return 1;
        } 
        else
            {
            //Adding the numbers together
            cout << integer << " + ";
            return (integer + myFunction(integer - 1));
   }
        }
       


int main()
{
	cout << "Michael Kuperman: 10/10/2021" << endl;
    int x = 10;
    cout << myFunction(x) << endl;
    
    
	return 0;
}
