#include <iostream>

using namespace std;

void swap();
int main(){
    int arr1[] = {1, 6, 0, 2, 7, 5};
    for (int i = 0; i < 6; i++){
        for ( int j = 0; j < 6; j++){
            if (arr1[i] < arr1[j]){
                swap(arr1[i],arr1[j]);
            }
        }
    }
    for (int i = 0; i < 6; i++){
        cout << arr1[i] << endl;
    }
}
void swap(int i, int j){
    int a = i;
    i = j;
    j = a;
}