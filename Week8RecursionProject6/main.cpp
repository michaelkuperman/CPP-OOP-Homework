#include <iostream>
using namespace std;

int myFunction(int integer)
{
    int sum = 0;
    if(integer == 1)
    {
        return 1;
    }
    for(int i = integer; i >= 1; i--) {
        cout << i << " + ";
        sum = sum + i;
       
    }
    cout << "0 = "<<  sum << endl;
    return sum;
    
}

int main()
{
    cout << "Michael Kuperman: 10/10/2021" << endl;
    int x = 10;
    myFunction(x);
}


//You changed total to sum and add comments before turning in.