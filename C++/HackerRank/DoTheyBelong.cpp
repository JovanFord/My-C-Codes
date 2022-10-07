#include <iostream>
#include <cmath>

using namespace std;

int pointsBelong(int, int, int, int, int, int ,int, int ,int, int);

int main (){
    cout << pointsBelong(0, 0, 2, 0, 4, 0, 2, 0, 4, 0);
}

int pointsBelong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq) {
    int ab, bc, ac;
    int ab1, bc1, ac1;
    bool p, q;

    ab1 = pow((x2 - x1), 2) + pow((y2 - y1), 2);
    ab = sqrt(ab1);
    bc1 = pow((x3 - x2), 2) + pow((y3 - y2), 2);
    bc = sqrt(bc1);
    ac1 = pow((x3 - x1), 2) + pow((y3 - y1), 2);
    ac = sqrt(ac1);
    
    if ((xp && yp > ab) || (xp && yp > bc) || (xp && yp > ac)){
        p = true;
    }
    else if((xq && yq > ab) || (xq && yq > bc) || (xq && yq > ac)){
        q = true;
    }

    if( (ab + bc <= ac) || (bc + ac <= ab) || (ab + ac <= bc)){
        return 0;
    }
    else if (p && !q){
        return 1;
    }
    else if (q && !p){
        return 2;
    }
    else if (q && p){
        return 3;
    }
    else{
        return 4;
    }
}