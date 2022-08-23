#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
using namespace std;

int main (){
    vector <int> vec = {1,2,3,4,5,6,7};
    int holder;
    int old;
    int rotates;
    cout << "How many rotations do you want" << endl;
    cin >> rotates;
    for (int i = 0; i < vec.size(); i++){
        if(vec[i] == vec[-1]){
            holder = vec[0];
            vec[i] = holder;
        }
        else{
            holder = vec[i + 1];
            vec[i] = holder;
        }

    }
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}