#include <iostream>
#include <string>

using namespace std;

bool checkSub(string, string);

int main(){
    checkSub("kid", "people");
}

bool checkSub(string s, string t){
    int j = 0;
        for (int i = 0; i < t.length() && j < s.length(); i++){
            if (s[j] == t[i]){
                j++;
            } 
        }
    return (j == s.length());
    }

