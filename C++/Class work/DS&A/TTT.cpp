#include <iostream>
#include <iomanip>
using namespace std;

void displayBoard(int &, int &, char[12][14]);
void makeBoard(int &, int &, char[12][14]);
void getPlayers(int &, string, string[]);
void resetBoard(int &, int &, char[12][14]);
void splitName(string &);
void makeMove(bool &, int &, int &, char[12][14], int &, int &, string[]);
void checkWinner(bool &, int &, int &, char[12][14], int &, string[], int &, int[], int[], int[]);
void displayStats(int &, string[], int[], int[], int[]);

const int rows = 12;
const int columns = 14;
const int players1 = 8;
const int wins = 8;
const int losses = 8;
const int draws = 8;

int main()
{
  string name;
  int m, n;
  int players;
  bool gameStatus = true;
  int pturn = 1;
  string playerNames[players1];
  char currentBoard[rows][columns];
  int winCount[wins] = {0, 0, 0, 0, 0, 0, 0, 0};
  int lossCount[losses] = {0, 0, 0, 0, 0, 0, 0, 0};
  int drawCount[draws] = {0, 0, 0, 0, 0, 0, 0, 0};
  char again;

  getPlayers(players, name, playerNames);
  makeBoard(m, n, currentBoard);
  do
  {
    displayBoard(m, n, currentBoard);
    makeMove(gameStatus, m, n, currentBoard, players, pturn, playerNames);
    checkWinner(gameStatus, m, n, currentBoard, players, playerNames, pturn, winCount, lossCount, drawCount);
    if (!gameStatus)
    {
      displayBoard(m, n, currentBoard);
      cout << "Would you like to play again?" << endl;
      cin >> again;
      if (again == 'y')
      {
        gameStatus = true;
        resetBoard(m, n, currentBoard);
      }
      else if (again == 'n')
      {
        displayStats(players, playerNames, winCount, lossCount, drawCount);
        gameStatus = false;
      }
    }
  } while (gameStatus);
}

void makeBoard(int &m, int &n, char currentBoard[rows][columns])
{
  string move;
  cout << "How many rows: ";
  cin >> m;
  while (1)
  {
    if (m < 3 || m > 12 || cin.fail())
    {
      cin.clear();
      cin.ignore();
      cout << "Board size is not correct, please enter a number 3-12: ";
      cin >> m;
      cout << endl;
    }
    cout << endl;
    if (m > 2 && m < 13 && !cin.fail())
    {
      break;
    }
  }
  cout << endl
       << "How many columns: ";
  cin >> n;
  while (1)
  {
    if (n < 3 || n > 14 || cin.fail())
    {
      cin.clear();
      cin.ignore();
      cout << "Board size is not correct, please enter a number 3-14: ";
      cin >> n;
      cout << endl;
    }
    cout << endl;
    if (n > 2 && n < 15 && !cin.fail())
    {
      break;
    }
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      currentBoard[i][j] = ' ';
    }
  }
}

void displayBoard(int &m, int &n, char currentBoard[rows][columns])
{
  cout << endl;
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (j >= 10 && i == 1)
      {
        cout << "  " << j;
      }
      else if (i == 1 && j < 10 && j == 1)
      {
        cout << "    " << j;
      }
      else if (i == 1 && j < 10 && j != 1)
      {
        cout << "   " << j;
        ;
      }
      if (j == n && i == 1)
      {
        cout << endl;
      }
    }
    for (int j = 1; j <= n; j++)
    {
      if (j == 1)
      {
        cout << "   --- ";
      }
      else
      {
        cout << "--- ";
      }
    }
    cout << endl;
    for (int j = 1; j <= n; j++)
    {
      if (j == 1)
      {
        cout << char(i + 64);
      }
      cout << " | " << currentBoard[i - 1][j - 1];
      if (j == n)
      {
        cout << " | " << char(i + 64);
      }
    }
    cout << endl;
    for (int j = 1; j <= n; j++)
    {
      if (i == m && j == 1)
      {
        cout << "   --- ";
      }
      else if (i == m && j > 1)
      {
        cout << "--- ";
      }
    }
    if (i == m)
    {
      cout << endl;
    }
    for (int j = 1; j <= n; j++)
    {
      if (j >= 10 && i == m)
      {
        cout << "  " << j;
      }
      else if (i == m && j < 10 && j == 1)
      {
        cout << "    " << j;
      }
      else if (i == m && j < 10 && j != 1)
      {
        cout << "   " << j;
      }
    }
  }
  cout << endl;
}

void getPlayers(int &players, string name, string playerNames[])
{
  cout << "How many players are playing: ";
  cin >> players;
  playerNames[0] = " ";
  while (1)
  {
    if (players < 2 || players > 7 || cin.fail())
    {
      cin.clear();
      cin.ignore();
      cout << "Error, must be 2-7 players" << endl;
      cout << "How many players are playing: ";
      cin >> players;
    }
    if ((players >= 2 && players <= 7) && !cin.fail())
    {
      break;
    }
  }
  cin.clear();
  cin.ignore();
  cout << endl;
  char test;
  for (int i = 1; i <= players; i++)
  {
    cout << "Enter player number " << i << "'s name: ";
    getline(cin, name);
    for (int j = 0; j < name.size(); j++)
    {
      test = name.at(j);
      if (!((test >= 'a' && test <= 'z') || (test >= 'A' && test <= 'Z') || (test == ' ')))
      {
        cout << "Error please only input alphabet characters" << endl;
        cout << "Enter player number " << i << "'s name: ";
        getline(cin, name);
      }
      if (name[0] >= 'a' && name[0] <= 'z')
      {
        name[0] = char(name[0] - 32);
      }
      if (name[j - 1] == ' ')
      {
        name[j] = char(name[j] - 32);
      }
    }
    playerNames[i] += name;
  }
}

void resetBoard(int &m, int &n, char currentBoard[rows][columns])
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      currentBoard[i][j] = ' ';
    }
  }
}

void splitName(string &name)
{
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

void makeMove(bool &gameStatus, int &m, int &n, char currentBoard[rows][columns], int &players, int &pturn, string playerNames[])
{
  cout << endl;
  cout << endl;
  gameStatus = true;
  bool validMove = true;
  int row1;
  int column1;
  string move;
  gameStatus = true;
  string temp1, temp2, convert;
  char test;
  do
  {
    if (pturn == 1)
    {
      while (validMove && gameStatus)
      {
        splitName(playerNames[pturn]);
        cout << " make your move:";
        cin >> move;
        row1 = move[0];
        while (row1 >= 32)
        {
          if (row1 >= 32)
          {
            row1 -= 32;
          }
          else if (row1 < 32)
          {
            break;
          }
        }
        row1 -= 1;
        temp1 = move[1];
        temp2 = move[2];
        convert = temp1 + temp2;
        column1 = stoi(convert) - 1;
        while (1)
        {
          if ((row1 < 0 || row1 > m) || (column1 < 0 || column1 > n) || currentBoard[row1][column1] != ' ')
          {
            cin.clear();
            cin.ignore();
            cout << "You can't make that move, try again:" << endl;
            cin >> move;
            row1 = move[0];
            while (row1 >= 32)
            {
              if (row1 >= 32)
              {
                row1 -= 32;
              }
              else if (row1 < 32)
              {
                break;
              }
            }
            row1 -= 1;
            temp1 = move[1];
            temp2 = move[2];
            convert = temp1 + temp2;
            column1 = stoi(convert) - 1;
          }
          if ((row1 >= 0 && row1 <= m) && (column1 >= 0 && column1 <= n))
          {
            validMove = false;
            break;
          }
        }
        currentBoard[row1][column1] = 'b';
        pturn++;
      }
    }
    else if (pturn == 2)
    {
      while (validMove && gameStatus)
      {
        splitName(playerNames[pturn]);
        cout << " make your move:";
        cin >> move;
        row1 = move[0];
        while (row1 >= 32)
        {
          if (row1 >= 32)
          {
            row1 -= 32;
          }
          else if (row1 < 32)
          {
            break;
          }
        }
        row1 -= 1;
        temp1 = move[1];
        temp2 = move[2];
        convert = temp1 + temp2;
        column1 = stoi(convert) - 1;
        while (1)
        {
          if ((row1 < 0 || row1 > m) || (column1 < 0 || column1 > n) || currentBoard[row1][column1] != ' ')
          {
            cin.clear();
            cin.ignore();
            cout << "You can't make that move, try again:" << endl;
            cin >> move;
            row1 = move[0];
            while (row1 >= 32)
            {
              if (row1 >= 32)
              {
                row1 -= 32;
              }
              else if (row1 < 32)
              {
                break;
              }
            }
            row1 -= 1;
            temp1 = move[1];
            temp2 = move[2];
            convert = temp1 + temp2;
            column1 = stoi(convert) - 1;
          }
          if ((row1 >= 0 && row1 <= m) && (column1 >= 0 && column1 <= n))
          {
            validMove = false;
            break;
          }
        }
        currentBoard[row1][column1] = 'c';
      }
      if (players == 2)
      {
        pturn = 1;
      }
      else
      {
        pturn++;
      }
    }
    else if (pturn == 3)
    {
      while (validMove && gameStatus)
      {
        splitName(playerNames[pturn]);
        cout << " make your move:";
        cin >> move;
        row1 = move[0];
        while (row1 >= 32)
        {
          if (row1 >= 32)
          {
            row1 -= 32;
          }
          else if (row1 < 32)
          {
            break;
          }
        }
        row1 -= 1;
        temp1 = move[1];
        temp2 = move[2];
        convert = temp1 + temp2;
        column1 = stoi(convert) - 1;
        while (1)
        {
          if ((row1 < 0 || row1 > m) || (column1 < 0 || column1 > n) || currentBoard[row1][column1] != ' ')
          {
            cin.clear();
            cin.ignore();
            cout << "You can't make that move, try again:" << endl;
            cin >> move;
            row1 = move[0];
            while (row1 >= 32)
            {
              if (row1 >= 32)
              {
                row1 -= 32;
              }
              else if (row1 < 32)
              {
                break;
              }
            }
            row1 -= 1;
            temp1 = move[1];
            temp2 = move[2];
            convert = temp1 + temp2;
            column1 = stoi(convert) - 1;
          }
          if ((row1 >= 0 && row1 <= m) && (column1 >= 0 && column1 <= n))
          {
            validMove = false;
            break;
          }
        }
        currentBoard[row1][column1] = 'd';
      }
      if (players == 3)
      {
        pturn = 1;
      }
      else
      {
        pturn++;
      }
    }
    else if (pturn == 4)
    {
      while (validMove && gameStatus)
      {
        splitName(playerNames[pturn]);
        cout << " make your move:";
        cin >> move;
        row1 = move[0];
        while (row1 >= 32)
        {
          if (row1 >= 32)
          {
            row1 -= 32;
          }
          else if (row1 < 32)
          {
            break;
          }
        }
        row1 -= 1;
        temp1 = move[1];
        temp2 = move[2];
        convert = temp1 + temp2;
        column1 = stoi(convert) - 1;
        while (1)
        {
          if ((row1 < 0 || row1 > m) || (column1 < 0 || column1 > n) || currentBoard[row1][column1] != ' ')
          {
            cin.clear();
            cin.ignore();
            cout << "You can't make that move, try again:" << endl;
            cin >> move;
            row1 = move[0];
            while (row1 >= 32)
            {
              if (row1 >= 32)
              {
                row1 -= 32;
              }
              else if (row1 < 32)
              {
                break;
              }
            }
            row1 -= 1;
            temp1 = move[1];
            temp2 = move[2];
            convert = temp1 + temp2;
            column1 = stoi(convert) - 1;
          }
          if ((row1 >= 0 && row1 <= m) && (column1 >= 0 && column1 <= n))
          {
            validMove = false;
            break;
          }
        }
        currentBoard[row1][column1] = 'e';
      }
      if (players == 4)
      {
        pturn = 1;
      }
      else
      {
        pturn++;
      }
    }
    else if (pturn == 5)
    {
      while (validMove && gameStatus)
      {
        splitName(playerNames[pturn]);
        cout << " make your move:";
        cin >> move;
        row1 = move[0];
        while (row1 >= 32)
        {
          if (row1 >= 32)
          {
            row1 -= 32;
          }
          else if (row1 < 32)
          {
            break;
          }
        }
        row1 -= 1;
        temp1 = move[1];
        temp2 = move[2];
        convert = temp1 + temp2;
        column1 = stoi(convert) - 1;
        while (1)
        {
          if ((row1 < 0 || row1 > m) || (column1 < 0 || column1 > n) || currentBoard[row1][column1] != ' ')
          {
            cin.clear();
            cin.ignore();
            cout << "You can't make that move, try again:" << endl;
            cin >> move;
            row1 = move[0];
            while (row1 >= 32)
            {
              if (row1 >= 32)
              {
                row1 -= 32;
              }
              else if (row1 < 32)
              {
                break;
              }
            }
            row1 -= 1;
            temp1 = move[1];
            temp2 = move[2];
            convert = temp1 + temp2;
            column1 = stoi(convert) - 1;
          }
          if ((row1 >= 0 && row1 <= m) && (column1 >= 0 && column1 <= n))
          {
            validMove = false;
            break;
          }
        }
        currentBoard[row1][column1] = 'f';
      }
      if (players == 5)
      {
        pturn = 1;
      }
      else
      {
        pturn++;
      }
    }
    else if (pturn == 6)
    {
      while (validMove && gameStatus)
      {
        splitName(playerNames[pturn]);
        cout << " make your move:";
        cin >> move;
        row1 = move[0];
        while (row1 >= 32)
        {
          if (row1 >= 32)
          {
            row1 -= 32;
          }
          else if (row1 < 32)
          {
            break;
          }
        }
        row1 -= 1;
        temp1 = move[1];
        temp2 = move[2];
        convert = temp1 + temp2;
        column1 = stoi(convert) - 1;
        while (1)
        {
          if ((row1 < 0 || row1 > m) || (column1 < 0 || column1 > n) || currentBoard[row1][column1] != ' ')
          {
            cin.clear();
            cin.ignore();
            cout << "You can't make that move, try again:" << endl;
            cin >> move;
            row1 = move[0];
            while (row1 >= 32)
            {
              if (row1 >= 32)
              {
                row1 -= 32;
              }
              else if (row1 < 32)
              {
                break;
              }
            }
            row1 -= 1;
            temp1 = move[1];
            temp2 = move[2];
            convert = temp1 + temp2;
            column1 = stoi(convert) - 1;
          }
          if ((row1 >= 0 && row1 <= m) && (column1 >= 0 && column1 <= n))
          {
            validMove = false;
            break;
          }
        }
        currentBoard[row1][column1] = 'g';
      }
      if (players == 6)
      {
        pturn = 1;
      }
      else
      {
        pturn++;
      }
    }
    else if (pturn == 7)
    {
      while (validMove && gameStatus)
      {
        splitName(playerNames[pturn]);
        cout << " make your move:";
        cin >> move;
        row1 = move[0];
        while (row1 >= 32)
        {
          if (row1 >= 32)
          {
            row1 -= 32;
          }
          else if (row1 < 32)
          {
            break;
          }
        }
        row1 -= 1;
        temp1 = move[1];
        temp2 = move[2];
        convert = temp1 + temp2;
        column1 = stoi(convert) - 1;
        while (1)
        {
          if ((row1 < 0 || row1 > m) || (column1 < 0 || column1 > n) || currentBoard[row1][column1] != ' ')
          {
            cin.clear();
            cin.ignore();
            cout << "You can't make that move, try again:" << endl;
            cin >> move;
            row1 = move[0];
            while (row1 >= 32)
            {
              if (row1 >= 32)
              {
                row1 -= 32;
              }
              else if (row1 < 32)
              {
                break;
              }
            }
            row1 -= 1;
            temp1 = move[1];
            temp2 = move[2];
            convert = temp1 + temp2;
            column1 = stoi(convert) - 1;
          }
          if ((row1 >= 0 && row1 <= m) && (column1 >= 0 && column1 <= n))
          {
            validMove = false;
            break;
          }
        }
        currentBoard[row1][column1] = 'a';
      }
      pturn = 1;
    }
  } while (gameStatus && validMove);
}

void checkWinner(bool &gameStatus, int &m, int &n, char currentBoard[rows][columns], int &players, string playerNames[], int &pturn, int winCount[], int lossCount[], int drawCount[])
{
  ///////////////////////////////////////////////////////
  //                 Horizontal Wins                   //
  ///////////////////////////////////////////////////////
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (((currentBoard[i][j] == currentBoard[i][j + 1]) || (currentBoard[i][j] == char(currentBoard[i][j + 1]) - 32)) && ((currentBoard[i][j + 1] == currentBoard[i][j + 2]) || (currentBoard[i][j + 1] == char(currentBoard[i][j + 2]) - 32)) && (currentBoard[i][j] != ' '))
      {
        currentBoard[i][j] = char((currentBoard[i][j]) - 32);
        currentBoard[i][j + 1] = char((currentBoard[i][j + 1]) - 32);
        currentBoard[i][j + 2] = char((currentBoard[i][j + 2]) - 32);
        cout << playerNames[pturn - 1] << " wins ";
        for (int k = 0; k < 7; k++)
        {
          if (playerNames[k] != playerNames[pturn - 1])
          {
            lossCount[k]++;
          }
          else
            winCount[pturn - 1]++;
        }
        gameStatus = false;
        break;
      }
    }
  }
  ///////////////////////////////////////////////////////
  //                  Vertical Wins                    //
  ///////////////////////////////////////////////////////
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (((currentBoard[i][j] == currentBoard[i + 1][j]) || (currentBoard[i][j] == char(currentBoard[i + 1][j]) - 32)) && ((currentBoard[i + 1][j] == currentBoard[i + 2][j]) || (currentBoard[i + 1][j] == char(currentBoard[i + 2][j]) - 32)) && (currentBoard[i][j] != ' '))
      {
        currentBoard[i][j] = char((currentBoard[i][j]) - 32);
        currentBoard[i + 1][j] = char((currentBoard[i + 1][j]) - 32);
        currentBoard[i + 2][j] = char((currentBoard[i + 2][j]) - 32);
        cout << playerNames[pturn - 1] << " wins ";
        for (int k = 0; k < 7; k++)
        {
          if (playerNames[k] != playerNames[pturn - 1])
          {
            lossCount[k]++;
          }
          else
            winCount[pturn - 1]++;
        }
        gameStatus = false;
        break;
      }
    }
  }
  ///////////////////////////////////////////////////////
  //               Negative Diagonal Wins              //
  ///////////////////////////////////////////////////////
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (((currentBoard[i][j] == currentBoard[i + 1][j + 1]) || (currentBoard[i][j] == char(currentBoard[i + 1][j +
                                                                                                                 1]) -
                                                                                            32)) &&
          ((currentBoard[i + 1][j + 1] == currentBoard[i + 2][j + 2]) || (currentBoard[i + 1][j + 1] == char(currentBoard[i + 2][j + 2]) - 32)) && (currentBoard[i][j] != ' '))
      {
        currentBoard[i][j] = char((currentBoard[i][j]) - 32);
        currentBoard[i + 1][j + 1] = char((currentBoard[i + 1][j + 1]) - 32);
        currentBoard[i + 2][j + 2] = char((currentBoard[i + 2][j + 2]) - 32);
        cout << playerNames[pturn - 1] << " wins ";
        for (int k = 0; k < 7; k++)
        {
          if (playerNames[k] != playerNames[pturn - 1])
          {
            lossCount[k]++;
          }
          else
            winCount[pturn - 1]++;
        }
        gameStatus = false;
        break;
      }
    }
  }
  ///////////////////////////////////////////////////////
  //               Positive Diagonal Wins              //
  ///////////////////////////////////////////////////////
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (((currentBoard[i][j] == currentBoard[i - 1][j + 1]) || (currentBoard[i][j] == char(currentBoard[i - 1][j + 1]) - 32)) && ((currentBoard[i - 1][j + 1] == currentBoard[i - 2][j + 2]) || (currentBoard[i - 1][j + 1] == char(currentBoard[i - 2][j + 2]) - 32)) && (currentBoard[i][j] != ' '))
      {
        currentBoard[i][j] = char((currentBoard[i][j]) - 32);
        currentBoard[i - 1][j + 1] = char((currentBoard[i - 1][j + 1]) - 32);
        currentBoard[i - 2][j + 2] = char((currentBoard[i - 2][j + 2]) - 32);
        cout << playerNames[pturn - 1] << " wins ";
        for (int k = 0; k < 7; k++)
        {
          if (playerNames[k] != playerNames[pturn - 1])
          {
            lossCount[k]++;
          }
          else
            winCount[pturn - 1]++;
        }
        gameStatus = false;
        break;
      }
    }
  }
  ///////////////////////////////////////////////////////
  //                      Draw                         //
  ///////////////////////////////////////////////////////
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (currentBoard[i][j] == ' ')
      {
        break;
      }
      else if ((i == (m - 1)) && (j == (n - 1)))
      {
        cout << "It was a draw" << endl;
        for (int k = 0; k < players; k++)
        {
          drawCount[k + 1]++;
          gameStatus = false;
        }
      }
    }
  }
}

void displayStats(int &players, string playerNames[], int winCount[], int lossCount[], int drawCount[])
{
  cout << endl
       << "Here are the game Stats:";
  cout << endl
       << endl
       << endl;
  for (int i = 0; i < 21; i++)
  {
    cout << " ";
  }
  cout << " ------ ------ ------ " << endl;
  for (int i = 0; i < 21; i++)
  {
    cout << " ";
  }
  cout << "|  WIN | LOSS | DRAW |" << endl;
  for (int i = 0; i < 21; i++)
  {
    cout << " ";
  }
  cout << " ------ ------ ------ " << endl;

  for (int i = 1; i <= players; i++)
  {
    for (int j = 0; j < 20 - playerNames[i].size(); j++)
    {
      cout << " ";
    }
    cout << playerNames[i];
    cout << " |    " << winCount[i] << " |    " << lossCount[i] << " |    " << drawCount[i] << " |" << endl;
    for (int j = 0; j < 21; j++)
    {
      cout << " ";
    }
    cout << " ------ ------ ------ " << endl;
  }
}