#include <iostream>

using namespace std;

class Temperature{
private:
    int temp;
public:
    Temperature(int tempa){
        temp = tempa;
    }
    bool isEthylFreezing(){
        if (temp <= -173){
            return true;
        }
        else{
            return false;
        }
    }
    bool isEthylBoiling(){
        if (temp >= 172){
            return true;
        }
        else{
            return false;
        }
    }
    bool isOxygenFreezing(){
        if (temp <= -362){
            return true;
        }
        else{
            return false;
        }
    }
    bool isOxygenBoiling(){
        if (temp >= -306){
            return true;
        }
        else{
            return false;
        }
    }
    bool isWaterFreezing(){
        if (temp <= 32){
            return true;
        }
        else{
            return false;
        }
    }
    bool isWaterBoiling(){
        if (temp >= 212){
            return true;
        }
        else{
            return false;
        }
    }
    void setTemp(int tempa){
        temp = tempa;
    }
    int getTemp(){
        return temp;
    }
};