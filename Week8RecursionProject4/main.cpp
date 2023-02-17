#include <iostream>
using namespace std;

void myFactorial(int integer)
{
    int i, factorial = 1;
    for(i = integer; i > 0; i--)
    {
        factorial = factorial*i;
    
    }
 cout<< factorial << endl;
}

int main()
{
    cout << "Michael Kuperman: 10/10/2021" << endl;
	myFactorial(7);
	return 0;
}
