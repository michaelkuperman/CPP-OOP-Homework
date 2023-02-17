#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    cout << "Michael Kuperman: 10/31/2021 " << endl;
    ofstream myfile;
    int a[10];

    myfile.open("savedTestScores.txt");
    for(int i = 0; i < 10; i++) {
        cout << "Enter score: " << endl;
        cin >> a[i];
        myfile << a[i] << endl;
    }
    int min = a[0], max = a[0], total = 0;
    for(int i = 0; i < 10; i++) {
        total += a[i];
        if(max < a[i]) {
            max = a[i];
        }
        if(min > a[i]) {
            min = a[i];
        }
    }
    cout << "Min Score: " << min << endl;
    cout << "Max Score: " << max << endl;
    cout << "Average: " << total / 10.0 << endl;
    cout << "Scores have been written\n";
    myfile.close();
    return 0;
}