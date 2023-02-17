#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()

{
    cout << "Michael Kuperman: 10/31/2021 " << endl;
    int nameCount;
    string name;

    cout << "How many first names do you want to input? ";
    cin >> nameCount;
    cout << endl;

    // creating the file
    ofstream fileWriter;
    fileWriter.open("savedNames.txt");
   
    for(int i = 0; i < nameCount; i++)

    {
        cout << "Enter the name #" << (i + 1) << ": ";
        getline(cin >> ws, name); // inputting the name, allowing white space
        fileWriter << name << "\n"; // writting to file one at a time
    }

    fileWriter.close(); // closing the file
}