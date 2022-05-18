#include <iostream>
#include <algorithm>
#include <array>

// Given an array of int nus which are in ascending order
// write a function to search target in nums
// if target exists thn return index
// otherwise return-1

using namespace std;

int search(int, int, int);

int main(){
    search((1,2,3,5,6,7), 6, 3);
}

int search(int nums[], int size, int target){
    for (int i = 0; i < size; i++){
        if (nums[i] == target){
            cout << i << endl;
            return i;
        }
        else{
            continue;
        }
    }
    return -1;
}