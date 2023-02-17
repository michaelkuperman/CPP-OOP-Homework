#include <iostream>
using namespace std;

class mySet
{
private:
    char myMembers[10];
    int count = 0;

public:
    void addMember(char inChar)
    {
        // check for duplicates
        for(int i = 0; i < count; i++) {
            if(myMembers[i] == inChar) {
                return; // return if duplicate found
            }
        }
        // otherwise add the character to the set
        if(!isFull()) {
            myMembers[count] = inChar;
            count++;
        }
    }

    void deleteMember(char delChar)
    {
        // check for duplicates
        for(int i = 0; i < count; i++) {
            if(myMembers[i] == delChar) {
                // shift all members to left
                for(int j = i; j < count - 1; j++) {
                    myMembers[j] = myMembers[j + 1];
                }
                count--; // decrement the count variable
                return;  // return if duplicate found
            }
        }
    }

    // following method prints all the members
    void printAllMembers()
    {
        if(isEmpty()) {
            cout << "\nSet is Empty\n";
            return;
        }
        cout << "[ " << myMembers[0];
        for(int i = 1; i < count; i++) {
            cout << ", " << myMembers[i];
        }
        cout << " ].\n";
    }

    // following method prints intersect members of two sets
    void Intersect(mySet inSetB)
    {
        char intercectElems[10];
        int countElms = 0;
        for(int i = 0; i < count; i++) {
            for(int j = 0; j < inSetB.count; j++) {
                if(myMembers[i] == inSetB.myMembers[j]) {
                    intercectElems[countElms] = myMembers[i];
                    countElms++;
                }
            }
        }
        if(countElms == 0) {
            cout << "No intersecting element found";
            return;
        }

        cout << "Intersecting element => [ " << intercectElems[0];
        for(int i = 1; i < countElms; i++) {
            cout << ", " << intercectElems[i];
        }
        cout << " ]. \n";
    }

    // following method returns true if set is empty
    bool isEmpty()
    {
        return (count == 0);
    }

    // following method returns true if set is full
    bool isFull()
    {
        return (count == 10);
    }
};
int main()
{
    cout << "Michael Kuperman: 11/21/2021 " << endl;
    mySet A;
    A.addMember('r');
    A.addMember('+');
    A.addMember('+');
    A.addMember('x');
    A.addMember('a');
    A.addMember('b');
    A.addMember('c');
    A.addMember('d');
    A.addMember('e');
    A.addMember('f');
    A.addMember('g');

    cout << "Set A => ";
    A.printAllMembers();

    cout << "\nRemoving char \'x\' from set..\n";
    A.deleteMember('x');
    cout << "Set A => ";
    A.printAllMembers();

    mySet B;
    B.addMember('r');
    B.addMember('2');
    B.addMember('+');
    B.addMember('a');
    B.addMember('b');
    B.addMember('k');
    B.addMember('l');
    B.addMember('m');
    B.addMember('n');

    cout << "\nSet B => ";
    B.printAllMembers();
    B.Intersect(A);
    cout << endl;
    return 0;
}