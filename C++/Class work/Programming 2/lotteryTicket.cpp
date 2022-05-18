#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>

using namespace std;

int main() {
  cout << "Enter you ticket numbers " << endl;
  // Random Number Generator (must be 1-50)
  srand (time(NULL));
  int lotWin[5]; 
  int ticket[5] = {}; 

  for (int i = 0; i < 5; i++){
    int numGen = rand() % 50;
    lotWin[i] = numGen;
    cout << lotWin[i] << endl;;
  }
  for (int i = 0; i < 5; i++){
    cin >> ticket[i];
  }
  for (int i = 0; i < 5; i++){
    if (ticket[i] != lotWin[i]){
      cout << "\nSorry you didn't win, better luck next time. :( " << endl;
    }
    else{
        cout << "\nCongrats you've won the lottery! " << endl;
    }
  }
}

