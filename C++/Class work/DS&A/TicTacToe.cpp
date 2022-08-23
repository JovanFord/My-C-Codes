#include <iostream>
using namespace std;

void setFirstPlayer();
void Board();
void makeMove();
bool checkWin();
void updateBoard();
void splitName(string);
void checkWinner();
const int BOARDSIZE = 10;
char board[BOARDSIZE] = {'p', '1', '2', '3', '4', '5', '6','7','8','9'};
string player1;
string playerA;
int p1wins;
string player2;
string playerB;
int p2wins;
int turn = 1;
// was a char on line 21
int nextMove;
int gamesPlayed = 0;

int main() {
  cout << "First player please enter your full name with a space between the two: ";
  getline(cin, player1);
  playerA = player1;
  cout << "Second player please enter your full name with a space between the two: ";
  getline(cin, player2);
  playerB = player2;
  cout << endl;

  //start of whileloop1
  while(checkWin() != true){
    // cout << "Current Board Status:" << endl;
    // Board();
    cout << endl;
    setFirstPlayer();
    makeMove();
    checkWinner();
    //Then reset the game and go back into while loop1
  } //end of while loop 1
    
    cout << player1 << " won!";
    gamesPlayed++;
    cout << "There has been " << gamesPlayed << " games played so far. Would you like to play again?";
  
  //If player 1 won
}

void setFirstPlayer(){
  string tempPlayer;
  if((int)player1[0] > (int)player2[0]){
    tempPlayer = player1;
    player1 = player2;
    player2 = tempPlayer;
  }
}

void Board(){
  cout << "+---+---+---+" << endl;
  cout << "| " << board[1] << " | " << board[4] << " | " << board[7] << " |" << endl;
  cout << "+---+---+---+" << endl;
  cout << "| " << board[2] << " | " << board[5] << " | " << board[8] << " |" << endl;
  cout << "+---+---+---+" << endl;
  cout << "| " << board[3] << " | " << board[6] << " | " << board[9] << " |" << endl;
  cout << "+---+---+---+" << endl;
}

bool checkWin(){
  return false;
}

void makeMove(){
  bool invalidMove = true;

  //player one turn
  if(turn == 1){
    while(invalidMove){
      splitName(player1); 
      cout << " make your move:" << endl;
      cin >> nextMove;
      if(nextMove >= 1 && nextMove <= 9){
        invalidMove = false;
      }
      else{
        cout << "You can't make that move, try again:" << endl;
      }
      //checks to see if a player has already gone in that space
      if (board[nextMove] == 'x' ||board[nextMove] == 'o'){
        cout << "You can't make that move, try again:" << endl;
        cin >> nextMove;
      }
    }
  }
  board[nextMove] = 'x';
  turn = 2;
  Board();
  invalidMove = true;
  //player two turn
  if(turn == 2){
    while(invalidMove){
      splitName(player2); 
      cout << " make your move." << endl;
      cin >> nextMove;
      if(nextMove >= 1 && nextMove <= 9){
        invalidMove = false;
      }
      else{
        cout << "You can't make that move, try again." << endl;
      }
      //checks to see if a player has already gone in that space
      if (board[nextMove] == 'x' ||board[nextMove] == 'o'){
        cout << "You can't make that move, try again:" << endl;
        cin >> nextMove;
      }
    }
  }
  board[nextMove] = 'o';
  turn = 1;
  Board();
  invalidMove = true;
}

void updateBoard(){
  
}

void splitName(string name){
  char letters = {};
  // iterates through string and stops at space
  for (int i = 0; i < 100; i++) {
    if (name[i] != ' ') {
      letters = letters + name[i];
    } 
    else{
      break;
    }
    // made void function and just printed the word by chars
    cout << name[i];
  }
}

void checkWinner(){
  //check if vertical win 
  for (int i = 1; i < BOARDSIZE; i += 3){
    if (board[i] == board[i + 1] == board[i + 2] == 'x'){
      cout << player1 << " wins" << endl;
      board[i] = 'X';
      p1wins++;
    }
    else if(board[i] == board[i + 1] == board[i + 2] == 'o'){
      cout << player2 << " wins" << endl;
      board[i] = 'O';
      p2wins++;
    }
  }
  //check if horizontal win 
  for (int i = 1; i < BOARDSIZE; i += 3){
    if (board[i] == board[i + 3] == board[i + 6] == 'x'){
      cout << player1 << " wins" << endl;
      board[i] = 'X';
      p1wins++;
    }
    else if(board[i] == board[i + 1] == board[i + 2] == 'o'){
      cout << player2 << " wins" << endl;
      board[i] = 'O';
      p2wins++;
    }
  }
  //check if positive diagnal win P1 
  for (int i = 1; i < BOARDSIZE; i += 3){
    if (board[i + 2] == board[i + 4] == board[i + 6] == 'x'){
      cout << player1 << " wins" << endl;
      board[i] = 'X';
      p1wins++;
    }
    else if(board[i + 2] == board[i + 4] == board[i + 6] == 'o'){
      cout << player2 << " wins" << endl;
      board[i] = 'O';
      p2wins++;
    }
  }
  //check if negative diagnal win P1
  for (int i = 1; i < BOARDSIZE; i += 3){
    if (board[i] == board[i + 4] == board[i + 8] == 'x'){
      cout << player1 << " wins" << endl;
      board[i] = 'X';
      p1wins++;
    }
    else if(board[i] == board[i + 4] == board[i + 8] == 'o'){
      cout << player2 << " wins" << endl;
      board[i] = 'O';
      p2wins++;
    }
  }
}

