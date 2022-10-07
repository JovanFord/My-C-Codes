#include <iostream>
#include <vector>

using namespace std;

bool checkRow(vector<int>, int);
bool checkCol(vector<vector<int>>, int, int);

int main(){
    vector<vector<int>> board
    {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    }; 
    int currentMagicNum = -1, largestMagicNum = -1;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
          // skip current magic number
          // check if everything to the row is increasing
          // check if everything in the column is increasing 
          if (checkRow(board[i], j) && checkCol(board, i, j)){
          // if both check and finish the loop AND trueMagicNum is less than currentMagicNum then set my trueMagicNum to currentMagicNum
            currentMagicNum = board[i][j];
            if (largestMagicNum < currentMagicNum){
              largestMagicNum = currentMagicNum;
            }
          }
        }
    }
    cout << largestMagicNum;
}

bool checkRow(vector<int> currRow, int j){
  int counter = 0;
  for (int k = 0; k < currRow.size(); k++)
  {
    if (k == j){
      counter++;
      continue;
    }
    else{
      if (k + 1 == currRow.size() ||
        (currRow[k] <= currRow[k + 1] 
        && k + 1 != j) 
        || k + 1 == j){
        counter++;
      }
    }
  }
  if (counter == currRow.size()){
    return true;
  }
  else
    return false;
}

bool checkCol(vector<vector<int>> board, int i, int j)
{
  int counter = 0;
  for (int row = 0; row < board.size(); row++) {
    // board[row][j]
    if (row == i)
    {
      counter++;
      continue;
    }
    else
    {
      if (row + 1 == board.size() 
        || (board[row][j] <= board[row + 1][j] 
        && row + 1 != i)
        || row + 1 == i)
      {
        counter++;
      }
    }
  }
    if(counter == board.size())
    {
      return true;
    }
    else
      return false;
}