#include <iostream>
#include <string>
using namespace std;

string defangIPaddr(string);

int main(){
    defangIPaddr("1.1.1.1");
}

string defangIPaddr(string address) {
    string naddress;
    for (int i = 0; i < address.size(); i++){
        if(address[i] == '.'){
            naddress += "[.]" ;
        }
        else{
            naddress += address[i];
        }
    }
    address = naddress;
    cout << address;
    return address;
}