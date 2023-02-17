#include <iostream>
using namespace std;

void myFunction(int counter)
{
    int i;
    for(i = counter; i > 0; i--) {
        cout << i << endl;
    }
}

int main()
{
    cout << "Michael Kuperman: 10/10/2021" << endl;
    int x = 10;
    myFunction(x);
}
