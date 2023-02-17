#include <iostream>
using namespace std;

class myBinaryMaxHeap
{
private:
    int myArr[32];
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
        int temp = myArr[i];
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

    int viewMax()
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
    void insert(int ele)
    {
        if(isFull()) {
            cout << "Heap is full" << endl;
        }
        // increase size of heap
        currentSize++;

        // store the element
        myArr[currentSize - 1] = ele;
        shiftUp(currentSize - 1);
    }

    void deleteMax()
    {
        if(isEmpty()) {
            cout << "Heap is emtpy" << endl;
        }
        // swap root with last element of heap and reduce size
        swap(0, currentSize - 1);
        currentSize--;

        // heapify the reduce heap
        shiftDown(0);
    }

    int count()
    {
        return currentSize;
    }
};

int main()
{
    cout << "Michael Kuperman: 10/17/2021" << endl;
    myBinaryMaxHeap H1;
    H1.insert(1);
    H1.insert(3);
    H1.insert(27);
    H1.insert(22);
    H1.insert(18);
    H1.insert(4);
    H1.insert(11);
    H1.insert(26);
    H1.insert(420);
    H1.insert(19);
    H1.insert(6);
    H1.insert(2);
    H1.insert(15);
    H1.insert(16);
    H1.insert(13);

    cout << "Count=" << H1.count() << endl;
    cout << "Max value is " << H1.viewMax() << endl;
    H1.deleteMax();
    cout << "Count= " << H1.count() << endl;
    cout << "Max value is " << H1.viewMax() << endl;

    return 0;
}