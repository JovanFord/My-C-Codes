#include <iostream>
#include <string>

using namespace std;

class Vehicle{
private:
    int yearModel;
    string make;
    int speed;
public:
    Vehicle (int yM, string m){
        yearModel = yM;
        make = m;
        speed = 0;
    }
    string getMake(){
        return make;
    }
    int getYearModel(){
        return yearModel;
    }
    int getSpeed(){
        return speed;
    }
    int accelerate(){
        return speed += 5;
    }
    int brake(){
        return speed -= 5;
    }
};

int main(){
    Vehicle v(2022, "Tesla");

    v.accelerate();
    cout << "Your speed right now is: " << v.getSpeed() << " MPH " << endl;
    v.accelerate();
    cout << "Your speed right now is: " << v.getSpeed() << " MPH " << endl;
    v.accelerate();
    cout << "Your speed right now is: " << v.getSpeed() << " MPH \n" << endl;

    v.brake();
    cout << "Your speed right now is: " << v.getSpeed() << " MPH " << endl;
    v.brake();
    cout << "Your speed right now is: " << v.getSpeed() << " MPH " << endl;
    v.brake();
    cout << "Your speed right now is: " << v.getSpeed() << " MPH " << endl;


}