#include <iostream>
#include <unordered_map>
using namespace std;


int main(){

}

bool isUnique(int arr1[], int size){
    unordered_map<string,int> map;
    for (int i = 0; i < size; i++){
        if (arr1[i] == map[i]){
            map[i] = 1;
        }
        else{
            return false;
        }
    }
    return true;
}