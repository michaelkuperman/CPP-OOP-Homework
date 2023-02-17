#include <iostream>
using namespace std;

class Sorting
{
    // functions
public:
    bool isFull();
    bool isEmpty();
    int find();
    void Delete(int numbers);
    void PrintAll();
    void Sort();
    void Insert(int number);
    Sorting()
    {
        for(int i = 0; i <= 9; i++) {
            numbers[i] = 99999;
        }
    }
    ~Sorting()
    {
    }

    // variables
private:
    int i;
    int j;
    int temp;
    int current;
    int numbers[];
};

void Sorting::Sort()
{

    for(i = 0; i <= 9; i++) {
        cout << numbers[i] << endl;
    }

    for(i = 0; i <= 9; i++) {
        for(j = i + 1; j <= 9; j++) {
            if(numbers[i] > numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

void Sorting::PrintAll()
{
    for(i = 0; i < 9; i++) {
        cout << numbers[i] << endl;
    }
}



void Sorting::Delete(int numbers)
{
}

bool Sorting::isFull()
{
    if(current == 10)
        return true;
    else
        return false;
}

bool Sorting::isEmpty()
{
    if(current == 0)
        return true;
    else
        return false;
}

void Sorting::Insert(int number)
//declaring
//storing
//access
{
    //Write  a loop later to store
    numbers[1] = number;    
    
    
}

int main()
{
    int numbers;
    Sorting List; // use class definition and declare instance.

    List.Insert(23);

    List.Insert(42);

    List.Insert(75);

    List.Insert(104);

   List.Insert(32);

   List.Insert(21);

    List.Insert(11);

    List.Insert(49);

    //List.Sort(); // required in prog 1.   Should not be needed in prog 2 if you do insertion sort properly.

    List.PrintAll();

    // cout << List.Find(42) << endl;

    // cout << List.Find(91) << endl;

     //List.Delete(32);

  //  List.Sort(); // required in prog 1.   Should not be needed in prog 2 if you do insertion sort properly.

  //  List.PrintAll();

 cin >> numbers;
    return 0;
}
