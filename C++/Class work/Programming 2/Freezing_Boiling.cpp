#include <iostream>
#include <string>
#include "Freeze_Boil.h"

using namespace std;



int main(){
    int temp;

    cout << "Enter a Temperature " << endl;
    cin >> temp;
    Temperature t(temp);

    t.setTemp(temp);

    if(t.isEthylFreezing()){
        cout << " Ethyl is freezing" << endl;
    }
    if(t.isEthylBoiling()){
        cout << " Ethyl is boiling" << endl;
    }
    if(t.isOxygenFreezing()){
        cout << " Oxygen is freezing" << endl;
    }
    if(t.isOxygenBoiling()){
        cout << " Oxygen is boiling" << endl;
    }
    if(t.isWaterFreezing()){
        cout << " Water is freezing" << endl;
    }
    if(t.isWaterBoiling()){
        cout << " Water is boiling" << endl;
    }

}