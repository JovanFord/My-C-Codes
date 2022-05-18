#include <iostream>
#include <vector>

using namespace std;

// given an vector. Delete the duplicates and return the new array 

vector<int> removeDupe(vector<int>);

int main(){
    vector<int> myvec = {1,2,3,1,3,4,6,2};
    removeDupe(myvec);
    for (int i = 0; i < myvec.size(); i++){
        cout << myvec[i] << endl;
    }
}

vector<int> removeDupe(vector<int> vec1){
    for (int i = 0; i < vec1.size(); i++){
        for (int j = i + 1; j < vec1.size(); i++){
            if (vec1[i] == vec1[j]){
                vec1.erase(vec1.begin() + i);
            }
        }
    }
    return vec1;
}