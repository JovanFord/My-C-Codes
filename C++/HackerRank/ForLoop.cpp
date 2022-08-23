#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int f;
    int l;
    cout << "First number:";
    cin >> f;
    cout << endl << "Last Number:";
    cin >> l;
    for (int i = f; i <= l; i++){
        if (i > 9){
            if (i % 2 == 0){
            cout << "even" << endl;
            }
            else{
                cout << "odd" << endl;
            }
            // cout << "Greater than 9" << endl;
        }
        else if (i == 9){
            cout << "nine" << endl;
        }
        else if (i == 8){
            cout << "eight" << endl;
        }
        else if (i == 7){
            cout << "seven" << endl;
        }
        else if (i == 6){
            cout << "six" << endl;
        }
        else if (i == 5){
            cout << "five" << endl;
        }
        else if(i == 4){
            cout << "four" << endl;
        }
        else if(i == 3){
            cout << "three" << endl;
        }
        else if(i == 2){
            cout << "two" << endl;
        }
        else if(i == 1){
            cout << "one" << endl;
        }
    }
    return 0;
}