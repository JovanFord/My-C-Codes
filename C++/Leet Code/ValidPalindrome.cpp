#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string ns;
//         for (int i = s.size(); i > 0; i--){
//             if (s[i] == ' '){
//                 continue;
//             }
//             else{
//                 ns += s[i];
//             }
//         }
//         if (s == ns){
//             return true;
//         }
//         else
//             return false;
//     }
// };

bool isPalindrome(string);

int main(){
    isPalindrome("A NUT FOR A JAR OF TUNA");
}

bool isPalindrome(string s) {
        string ns;
        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] == ' '){
                continue;
            }
            else{
                ns += s[i];
            }
        }
        if (s == ns){
            cout << "true";
            return true;
        }
        else
            cout << "false";
            return false;
    }