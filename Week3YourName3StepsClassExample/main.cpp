#include <iostream>
using namespace std;

//Declaring a Class and calling it CarTransmission
class CarTransmission {

//Defining the different functions used in a cars transmission    
public:
    void Parked() {
        cout << "You are parked" << endl;
    }
    
    void Reversing() {
        cout << "You are reversing" << endl;
    }
    
    void Nuetral() {
        cout << "You are in Nuetral" << endl;
    }
    
    void Accelerating() {
        cout << "You are speeding up" << endl;
    }
    
};

int main()
{
    cout << "Michael Kuperman - 9/4/2021" << endl;
    //In order to use the function we needed to create an object in this case vehicle.
    //Now it knows what I want to use in the code as its linked to the CarTansmission class.
    CarTransmission vehicle;
    vehicle.Parked();
    vehicle.Reversing();
    vehicle.Nuetral();
    vehicle.Accelerating();
	return 0;
}
