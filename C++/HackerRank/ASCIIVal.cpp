#include <iostream>
#include <string>
using namespace std;

int main(){
    string encode = "23511011501782351112179911801562340161171141148";
    string tempEncode;
    string temp1;
    string temp2;
    string temp3;
    string translate;
    string holder;
    int converter;
    char letter;
    for (int i = encode.size(); i >= 0; i--){
        tempEncode += encode[i];
    }
    encode = tempEncode;
    for (int i = 1; i < encode.size(); i++){
        temp1 = encode[i];
        temp2 = encode[i + 1];
        temp3 = encode[i + 2];
        holder = temp1 + temp2 + temp3;
        if (holder < "122" && holder >= "100"){
            converter = stoi(holder);
            letter = char(converter);
            translate += letter;
            i += 2;
        } 
        else if (holder > "122"){
            holder = temp1 + temp2;
            converter = stoi(holder);
            if ((holder > "64" && holder < "90") || (holder > "96" && holder < "100")){
            letter = char(converter);
            translate += letter;
            i += 1;
            }
            else if (holder == "32"){
                letter = char(converter);
                translate += letter;
                i += 1;
            }
        }
    }
    cout << translate;
}