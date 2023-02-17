#include <iostream>
#define MAX_SIZE 10000
#define NULL_VAL (-100000)
int pq_ind = 0;

int top(int pq[]);
void pop(int pq[]);
void push(int pq[], int val);
void quickSort(int a[], int first, int last);
int pivot(int a[], int first, int last);
void swap(int& a, int& b);
void swapNoTemp(int& a, int& b);
void print(int array[], const int& N);
using namespace std;
int main()
{
    cout << "Michael Kuperman: 10/24/2021" <<endl;
    int test[] = { 7, -13, 1, 3, 10, 5, 2, 4 };
    int N = sizeof(test) / sizeof(int);
    cout << "Size of test array :" << N << endl;
    cout << "Before sorting : " << endl;
    print(test, N);
    quickSort(test, 0, N - 1);
    cout << endl << endl << "After sorting : " << endl;
    print(test, N);

    printf("\n\npriority queue Testing \n\n");
    /* priority Queue testing */
    int pq[MAX_SIZE];
    push(pq, 45);
    push(pq, 10);
    push(pq, 78);
    printf("\nafter inserting  45 10 78,the content of priority queue is\n");
    print(pq, pq_ind);
    pop(pq);
    printf("\nafter removing top, the content of priority queue is \n");
    print(pq, pq_ind);

    return 0;
}

/*
 * @param pq -- priority queue int array
 * @param val  --- value to be inserted
 */
void push(int pq[], int val)
{
    pq[pq_ind++] = val;
    quickSort(pq, 0, pq_ind - 1);
}

/*
 *@param pq -- priority queue int array
 */
void pop(int pq[])
{
    --pq_ind;
}

/*
 *@param pq -- priority queue int array
 */
int top(int pq[])
{
    if(pq_ind == 0) {
        cout << "no value present in pq\n";
        return NULL_VAL;
    }
    return pq[pq_ind - 1];
}

/**
 * Quicksort.
 * @param a -The array to be sorted.
 * @param first -The start of the sequence to be sorted.
 *@param last -The end of the sequence to be sorted.
 */
void quickSort(int a[], int first, int last)
{
    int pivotElement;
    if(first < last) {
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement - 1);
        quickSort(a, pivotElement + 1, last);
    }
}
/**
 * Find and return  the index of pivot element.
 * @param a -The array.
 * @param first -The start of the sequence.
 * @param last -The end of the sequence.
 * @return  -the pivot element
 */
int pivot(int a[], int first, int last)
{
    int p = first;
    int pivotElement = a[first];
    for(int i = first + 1; i <= last; i++) {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivotElement) {
            p++;
            swap(a[i], a[p]);
        }
    }
    swap(a[p], a[first]);
    return p;
}
/**
 * Swap the parameters.
 * @param a -The first parameter.
 * @param b -The second parameter.
 */
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
/**
 * Swap the parameters without a temp variable.
 * Warning! Prone to overflow/underflow.
 * @param a -The first parameter.
 * @param b -The second parameter.
 */
void swapNoTemp(int& a, int& b)
{
    a -= b;
    b += a;      // b gets the original value of a
    a = (b - a); // a gets the original value of b
}
/**
 * Print  an array.
 * @param a -The array.
 * @param N -The size of the array.
 */
void print(int a[], const int& N)
{
    for(int i = 0; i < N; i++)
        cout << "array[" << i << "] = " << a[i] << endl;
}
