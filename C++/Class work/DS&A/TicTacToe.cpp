#include <iostream>
using namespace std;

void setFirstPlayer(string, string);
void Board(char[]);
void move(int&, int, int&, int&, int&, int&, int&, int&, string, string, char[]);
void splitName(string);
void checkWinner(int&, int, int&, int&, int&, int&, int&, int&, string, string, char[]);
void resetBoard(char[]);
const int BOARDSIZE = 10;

int main()
{
  char board[BOARDSIZE] = {'j', '1', '2', '3', '4', '5', '6','7','8','9'};
  int p1wins = 0;
  int p1loss = 0;
  int p1draw = 0;
  int p2wins = 0;
  int p2loss = 0;
  int p2draw = 0;
  
  string player1, player2;
  int gamesPlayed = 0;
  string gameChoice;
  int gameStatus = 0;

  cout << "First player please enter your full name with a space between the two: ";
  getline(cin, player1);
  cout << "Second player please enter your full name with a space between the two: ";
  getline(cin, player2);
  cout << endl;

  do 
  {
    cout << "Current Board Status:" << endl;
    Board(board);
    cout << endl;
  
    setFirstPlayer(player1, player2);
    move(gameStatus, 1, p1wins, p1loss, p1draw, p2wins, p2loss, p2draw, player1, player2, board);
  
    if (gameStatus)
    {
      gamesPlayed++;
      cout << "There has been " << gamesPlayed; 
      cout << " games played so far." << endl << endl; 
      cout << player1 << ": " << endl << p1wins << " wins" << endl;
      cout << p1loss << " losses" << endl;
      cout << p1draw << " draws" << endl << endl;
      cout << player2 << ": " << endl << p2wins << " wins" << endl;
      cout << p2loss << " losses" << endl;
      cout << p2draw << " draws" << endl;
      cout << "Would you like to play again?";
      cout << endl << endl << "y for yes" << endl<< "n for no" << endl;
      Board(board);
  
      cin >> gameChoice;
      if (gameChoice == "y" || gameChoice == "yes")
      {
        resetBoard(board);
        gameStatus = 0;
      }  
      else if (gameChoice == "n" || gameChoice == "no")
      {
        cout << "There has been " << gamesPlayed << " games played so far.";
      }  
      else 
      {
        cout << "invalid input" << endl;
        cin >> gameChoice; 
      }
    }
  } while (gameStatus != 1);
}

void setFirstPlayer(string player1, string player2)
{
  string tempPlayer;
  for (int i = 0; i < player1.size() || i < player2.size(); i++)
  {
    if ((int) player1[i] == (int) player2[i])
    {

      continue;
    }
    else if ((int) player1[i] < (int) player2[i])
    {
      tempPlayer = player1;
      player1 = player2;
      player2 = tempPlayer;
      break;
    }
  }
}

void Board(char board[])
{
  cout << "+---+---+---+" << endl;
  cout << "| " << board[1] << " | " << board[4] << " | " << board[7] << " |" << endl;
  cout << "+---+---+---+" << endl;
  cout << "| " << board[2] << " | " << board[5] << " | " << board[8] << " |" << endl;
  cout << "+---+---+---+" << endl;
  cout << "| " << board[3] << " | " << board[6] << " | " << board[9] << " |" << endl;
  cout << "+---+---+---+" << endl;
}

void move(int &gameStatus, int turn, int &p1wins, int &p1loss, int &p1draw, int &p2wins, int &p2loss, int &p2draw, string player1, string player2, char board[])
{
  bool invalidMove = true;
  int nextMove;
  if(turn == 1)
  {
    while (invalidMove && gameStatus == 0)
    {
      splitName(player1); 
      cout << " make your move:" << endl;
      cin >> nextMove;
      if (nextMove >= 1 && nextMove <= 9)
      {
        invalidMove = false;
      }
      else
      {
        cout << "You can't make that move, try again:" << endl;
      }
      if (board[nextMove] == 'x' || board[nextMove] == 'o')
      {
        cout << "You can't make that move, try again:" << endl;
        cin >> nextMove;
      }
    }
  }

  board[nextMove] = 'x';
  Board(board);

  invalidMove = true;
  checkWinner(gameStatus, 1, p1wins, p1loss, p1draw, p2wins, p2loss, p2draw, player1, player2, board);
  if (gameStatus)
  {
    return;
  }
  
  turn = 2;
  if (turn == 2)
  {
    while (invalidMove && !gameStatus)
    {
      splitName(player2); 
      cout << " make your move." << endl;
      cin >> nextMove;

      if (nextMove >= 1 && nextMove <= 9)
      {
        invalidMove = false;
      }
      else 
      {
        cout << "You can't make that move, try again." << endl;
      }
      if (board[nextMove] == 'x' || board[nextMove] == 'o')
      {
        cout << "You can't make that move, try again:" << endl;
        cin >> nextMove;
      }
    }
  }

  board[nextMove] = 'o';
  invalidMove = true;
  checkWinner(gameStatus, 1, p1wins, p1loss, p1draw, p2wins, p2loss, p2draw, player1, player2, board);
  if (gameStatus)
  {
    return;
  }
  turn = 1;
}

void splitName(string name)
{
  //   char letters = {};
  for (int i = 0; i < name.length(); i++) 
  {
    if (name[i] != ' ') 
    {
      // letters = letters + name[i];
    } 
    else
    {
      break;
    }
    cout << name[i];
  }
}

void checkWinner(int &gameStatus, int turn, int &p1wins, int &p1loss, int &p1draw, int &p2wins, int &p2loss, int &p2draw, string player1, string player2, char board[])
{
  for (int i = 1; i < BOARDSIZE; i+=3)
  {
    if ((board[i] == 'x' || board[i] == 'X') && (board[i + 1] == 'x' || board[i + 1] == 'X') && (board[i + 2] == 'x' || board[i + 2] == 'X'))
    {
      p1wins++;
      p2loss++;
      gameStatus = true;
      board[i] = 'X'; 
      board[i + 1] = 'X';
      board[i + 2] = 'X';
    }
  }

  for (int i = 1; i < BOARDSIZE; i+=3)
  {
    if ((board[i] == 'o' || board[i] == 'O') && (board[i + 1] == 'o' || board[i + 1] == 'O') && (board[i + 2] =='o' || board[i + 2] =='O') )
    {
      p2wins++;
      p1loss++;
      gameStatus = true;
      board[i] = 'O'; 
      board[i + 1] = 'O';
      board[i + 2] = 'O';
      turn = 1;
    }
  }

  for (int i = 1; i < BOARDSIZE; i++)
  {
    if ((board[i] == 'x' || board[i] == 'X') && (board[i + 3] == 'x' || board[i + 3] == 'X') && (board[i + 6] =='x' || board[i + 6] =='X') )
    {
      p1wins++;
      p2loss++;
      gameStatus = true;
      board[i] = 'X'; 
      board[i + 3] = 'X';
      board[i + 6] = 'X';
    }
  }
  for (int i = 1; i < BOARDSIZE; i++)
  {
    if ((board[i] == 'o' || board[i] == 'O') && (board[i + 3] == 'o' || board[i + 3] == 'O') && (board[i + 6] =='o' || board[i + 6] =='O'))
    {
      p2wins++;
      p1loss++;
      gameStatus = true;
      board[i] = 'O'; 
      board[i + 3] = 'O';
      board[i + 6] = 'O';
      turn = 1;
    }
  }
  if ((board[3] == 'x' || board[3] == 'X') && (board[5] == 'x' || board[5] == 'X') && (board[7] == 'x' || board[7] == 'X'))
  {
    if ((board[1] == 'x' || board[1] == 'X') && (board[5] == 'x' || board[5] == 'X') && (board[9] == 'x' || board[9] == 'X'))
    {
    board[1] = 'X';
    board[5] = 'X';
    board[9] = 'X';
  }
    cout << player1 << " wins" << endl;
    p1wins++;
    p2loss++;
    gameStatus = true;
    board[3] = 'X';
    board[5] = 'X';
    board[7] = 'X';
  }
  else if ((board[3] == 'o' || board[3] == 'O') && (board[5] == 'o' || board[5] == 'O') && (board[7] == 'o' || board[7] == 'O'))
  {
    if ((board[1] == 'o' || board[1] == 'O') && (board[5] == 'o' || board[5] == 'O') && (board[9] == 'o' || board[9] == 'O'))
    {
      board[1] = 'O';
      board[5] = 'O';
      board[9] = 'O';
      turn = 1;
    }
    cout << player2 << " wins" << endl;
    p2wins++;
    p1loss++;
    gameStatus = true;
    board[3] = 'O';
    board[5] = 'O';
    board[7] = 'O';
    turn = 1;
  }
  else if ((board[1] == 'x' || board[1] == 'X') && (board[5] == 'x' || board[5] == 'X') && (board[9] == 'x' || board[9] == 'X'))
  {
    if ((board[3] == 'x' || board[3] == 'X') && (board[5] == 'x' || board[5] == 'X') && (board[7] == 'x' || board[7] == 'X'))
    {
      board[3] = 'X';
      board[5] = 'X';
      board[7] = 'X';
    }
    cout << player1 << " wins" << endl;
    p1wins++;
    p2loss++;
    gameStatus = true;
    board[1] = 'X';
    board[5] = 'X';
    board[9] = 'X';
  }
  else if ((board[1] == 'o' || board[1] == 'O') && (board[5] == 'o' || board[5] == 'O') && (board[9] == 'o' || board[9] == 'O'))
  {
    if ((board[3] == 'o' || board[3] == 'O') && (board[5] == 'o' || board[5] == 'O') && (board[7] == 'o' || board[7] == 'O'))
    {
      board[3] = 'O';
      board[5] = 'O';
      board[7] = 'O';
    }
    cout << player2 << " wins" << endl;
    p2wins++;
    p1loss++;
    gameStatus = true;
    board[1] = 'O';
    board[5] = 'O';
    board[9] = 'O';
    turn = 1;
  }
  for (int i = 1; i < BOARDSIZE; i++)
  {
    if (board[i] != 'x' && board[i] != 'o')
    {
      break;
    }
    else if (i == (BOARDSIZE - 1))
    {
      cout << "It was a draw" << endl;
      gameStatus = true;
      p1draw++;
      p2draw++;
    }
  }
}

void resetBoard(char board[])
{
  for (int i = 0; i < 10; i++)
  {
   board[i] = '1'+ i;
  }
}

//board[i] = (char(i+48));