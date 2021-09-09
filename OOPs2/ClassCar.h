#include "ClassVehicle.h"


class Car : public Vehicle {
public:
    int numGears;

    void print(){
        cout << "Num Tyres: " << numTyres << endl;
        cout << "Color: " << numTyres << endl;
        cout << "Num Gears: " << numGears << endl;
        // cout << "Max Speed: " << maxSpeed << endl; //inaccessible since private properties
    }
};    