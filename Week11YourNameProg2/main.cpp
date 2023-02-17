#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Person {
    string firstName;
    string lastName;
    int age;
};

int main()
{
    Person p[5];
    ifstream infile;
    infile.open("../firstLastAge.txt");
    int i = 0;
    while(infile >> p[i].firstName >> p[i].lastName >> p[i].age) {
        i++;
    }

    int yongestIndex = 0, oldestIndex = 0;
    int yongestAge = p[0].age, oldestAge = p[0].age;

    for(int i = 1; i < 5; i++) {
        if(yongestAge > p[i].age) {
            yongestAge = p[i].age;
            yongestIndex = i;
        }
        if(oldestAge < p[i].age) {
            oldestAge = p[i].age;
            oldestIndex = i;
        }
    }
    cout << "Youngest Persons is :" << p[yongestIndex].firstName << " " << p[yongestIndex].lastName << " "
         << p[yongestIndex].age << endl;
    cout << "Oldest Persons is :" << p[oldestIndex].firstName << " " << p[oldestIndex].lastName << " "
         << p[oldestIndex].age << endl;
    system("pause");
    return 0;
}