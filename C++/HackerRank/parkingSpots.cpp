#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cLen, sLen, spaceCount = 0;
    vector<int> cLoc;
    vector<int> scLen;
    int takenSpots[sLen];

    cLen = 2;
    sLen = 10;
    cLoc = {0,2,4,7};
    scLen = {1,1,1,1};

    for (int i = 0; i < sLen; i++){
        takenSpots[i] = 0;
    }

    for (int i = 0; i < scLen.size(); i++){
        takenSpots[cLoc[i]] = 1;
        int scount = 1;
        while(scount < scLen[i]){
            takenSpots[cLoc[i] + scount] = 1;
            scount++;
        }
    }
    for (int i = 0; i < sLen; i++){
        if(takenSpots[i] == 0){
            spaceCount++;
            if (spaceCount == cLen){
                cout << "true";
                break;
            }
        }
        else if(takenSpots[i] == 1){
            spaceCount = 0;
        }
        if (i == sLen - 1){
            cout << "false";
        }
    }

}