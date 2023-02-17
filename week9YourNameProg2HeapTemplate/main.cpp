#include <iostream>
using namespace std;
template <class Type>

class myBinaryMaxHeap
{
private:
    Type myArr[32];
    int currentSize;
    void shiftUp(int k)
    {
        while(k > 0 && myArr[k / 2] < myArr[k]) {
            swap(k, k / 2);
            k /= 2;
        }
    }
    void swap(int i, int j)
    {
        Type temp = myArr[i];
        myArr[i] = myArr[j];
        myArr[j] = temp;
    }
    void shiftDown(int k)
    {
        while(2 * k < currentSize) {
            int largest = k;
            int left = 2 * k + 1;
            int right = 2 * k + 2;
            if(left < currentSize && myArr[left] > myArr[largest])
                largest = left;
            if(right < currentSize && myArr[right] > myArr[largest])
                largest = right;
            if(k != largest)
                swap(k, largest);
            else
                break;
            k = largest;
        }
    }

public:
    myBinaryMaxHeap()
    {
        for(int i = 0; i < 32; i++)
            myArr[i] = 0;
        currentSize = 0;
    }
    Type viewMax()
    {
        if(isEmpty()) {
            cout << "Heap is empty please add some elements" << endl;
            return -1;
        }
        return myArr[0];
    }
    bool isEmpty()
    {
        if(currentSize == 0)
            return true;
        return false;
    }
    bool isFull()
    {
        if(currentSize == 32)
            return true;
        return false;
    }
    void insert(Type ele)
    {
        if(isFull()) {
            cout << "Heap is full" << endl;
        }
        currentSize++;
        myArr[currentSize - 1] = ele;
        shiftUp(currentSize - 1);
    }
    void deleteMax()
    {
        if(isEmpty()) {
            cout << "Heap is empty" << endl;
        }
        swap(0, currentSize - 1);
        currentSize--;
        shiftDown(0);
    }
    int count()
    {
        return currentSize;
    }
};
// driver function
int main()
{
    cout << "Michael Kuperman: 10/17/2021" << endl;
    
    cout <<"==================Testing with integers===================" << endl;
    myBinaryMaxHeap<int> H1;
    H1.insert(1);
    H1.insert(52);
    H1.insert(65);
    H1.insert(43);
    H1.insert(197);
    H1.insert(54);
    H1.insert(11);
    H1.insert(5);
    H1.insert(32);
    H1.insert(54);
    cout << "Count = " << H1.count() << endl;
    cout << "Max value is " << H1.viewMax() << endl;
    H1.deleteMax();
    cout << "Count = " << H1.count() << endl;
    cout << "Max value is " << H1.viewMax() << endl;
    
    cout << "==================Testing with doubles===================" << endl;
    myBinaryMaxHeap<double> H2;
    H2.insert(1);
    H2.insert(52.2);
    H2.insert(65.5);
    H2.insert(43.3);
    H2.insert(197.7);
    H2.insert(54.4);
    H2.insert(11.1);
    H2.insert(5.5);
    H2.insert(322);
    H2.insert(54.5);
    cout << "Count = " << H2.count() << endl;
    cout << "Max value is " << H2.viewMax() << endl;
    H2.deleteMax();
    cout << "Count = " << H2.count() << endl;
    cout << "Max value is " << H2.viewMax() << endl;
    
    cout << "==================Testing with chars===================" << endl;
    myBinaryMaxHeap<char> H3;
    H3.insert('A');
    H3.insert('a');
    H3.insert('z');
    H3.insert('P');
    H3.insert('$');
    H3.insert('b');
    H3.insert('&');
    H3.insert('r');
    H3.insert('m');
    H3.insert('*');
    H3.insert('i');
    cout << "Count = " << H3.count() << endl;
    cout << "Max value is " << H3.viewMax() << endl;
    H3.deleteMax();
    cout << "Count = " << H3.count() << endl;
    cout << "Max value is " << H3.viewMax() << endl;
    return 0;
}
