#include <iostream>
#include <vector>

using namespace std;

vector<int> removeDupe(vector<int>);

int majorityElement(vector<int>& nums) {
    vector<int> vec1 = nums;
    int highestElem;
    vector<int> checker = {}; 
    for (int i = 0; i < nums.size(); i++){
        int counter = 0;
        for (int j = i + 1; j < nums.size(); j++){
            if (nums[i] == nums[j]){
                counter++;
                removeDupe(vec1);
            }
        }
        checker[i] == counter;
    }
    for (int i = 0; i < nums.size(); i++){
        
    }
    return highestElem;
}
int main (){
    
}

vector<int> removeDupe(vector<int> vec1){
    for (int i = 0; i < vec1.size(); i++){
        for (int j = i + 1; j < vec1.size(); i++){
            if (vec1[i] == vec1[j]){
                vec1.erase(vec1.begin() + j);
            }
        }
    }
    return vec1;
}