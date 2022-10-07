#include <iostream>
#include <iomanip>
using namespace std;

void splitName(string&);

int main()
{
    int players = 7;
    int m = 12;
    int n = 14;
    string arr1[] = {"jovan", "BiG Boi", "Lier"};
    for (int i = 0; i < players; i++)
    {
        for (int j = 0; j < players; j++)
        {
            if (i == 0 && j == 0){
                setprecision(10);
                cout << " ------ ------ ------ " << endl;
                cout << "|  WIN | LOSS | DRAW |" << endl;
            }
            else if (i = j)
            {
                cout << " ------ ------ ------ " << endl;
                cout << arr1[i] << setw(j) << "|      |      |      |" << endl;
            }
            if (i == players - 1)
            {
                cout << " ------ ------ ------ " << endl;
            }

        }
    }
    cout << "name";
    cout << "jovan ford";
    cout << "big round indefinite";
//     int players;
//     string name;
//     bool gameStatus = true;
//     // getPlayers
//     cout << "How many players are playing: "; 
//     cin >> players;
//     while(1)
//     {
//         if(players < 2 || players > 7 || cin.fail())
//         {
//             cin.clear();
//             cin.ignore();
//             cout << "Error, must be 2-7 players" << endl;
//             cout << "How many players are playing: ";
//             cin >> players;
//         }
//         if((players >= 2 && players <= 7) && !cin.fail())
//         {
//             break;
//         }
//     }
//     cin.clear();
//     cin.ignore();
//     cout << endl;
//     string playerNames[players]; // cant have variable as array size, needs to be static
//     char test;
//     for (int i = 1; i <= players; i++)
//     {
//         cout << "Enter player number " << i << "'s name: ";
//         getline(cin, name);
//         for (int j = 0; j < name.size(); j++)
//         {
//             test = name.at(j);
//             if (!((test >= 'a' && test <= 'z') || (test >= 'A' && test <= 'Z') || (test == ' ')))
//             {
//                 cout << "Error please only input alphabet characters" << endl;
//                 cout << "Enter player number " << i << "'s name: ";
//                 getline(cin, name);
//             }
//             if (name[0] >= 'a' && name[0] <= 'z')
//             {
//                 name[0] = char(name[0] - 32);
//             }
//         }
//         playerNames[i - 1] += name;
//     }
    
//     // makeBoard
//     int m;
//     int n;
//     string move;
//     cout << "How many rows: ";
//     cin >> m;
//     while(1)
//     {
//         if (m < 3 || m > 12 || cin.fail())
//         {
//             cin.clear();
//             cin.ignore();
//             cout << "Board size is not correct, please enter a number 3-12: ";
//             cin >> m;
//             cout << endl;
//         }
//         cout << endl;
//         if(m > 2 && m < 13 && !cin.fail())
//         {
//             break;
//         }
//     }
//     cout << endl << "How many columns: ";
//     cin >> n;
//     while(1)
//     {
//         if (n <= 2 || n >= 14 || cin.fail())
//         {
//             cin.clear();
//             cin.ignore();
//             cout << "Board size is not correct, please enter a number 3-14: ";
//             cin >> n;
//             cout << endl;
//         }
//         cout << endl;
//         if(n > 2 && n < 16 && !cin.fail())
//         {
//             break;
//         }
//     }
//     char currentBoard[n][m];
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             currentBoard[i][j] = ' ';
//         }
//     }

//     //displayBoard
//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if(j >= 10 && i == 1)
//             {
//                 cout << "  " << j;
//             }
//             else if (i == 1 && j < 10 && j == 1)
//             {
//                 cout << "    " << j; 
//             }
//             else if (i == 1 && j < 10 && j != 1)
//             {
//                 cout << "   " << j;;
//             }
//             if (j == n && i == 1)
//             {
//                 cout << endl;
//             }
//         }
//         for (int j = 1; j <= n; j++)
//         {
//             if(j == 1)
//             {
//                 cout << "   --- ";
//             }
//             else 
//             {
//                 cout << "--- ";
//             }
//         }
//         cout << endl;
//         for (int j = 1; j <= n; j++)
//         {
//             if(j == 1)
//             {
//                 cout << char(i + 64);
//             }
//             cout << " | " << currentBoard[i - 1][j - 1];
//             if(j == n)
//             {
//                 cout << " | " << char(i + 64);
//             }
//         }
//         cout << endl;
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == m && j == 1)
//             {
//                 cout << "   --- ";
//             }
//             else if(i == m && j > 1)
//             {
//                 cout << "--- ";
//             }
//         }
//         if(i == m)
//         {
//             cout << endl;
//         }
//         for (int j = 1; j <= n; j++)
//         {
//             if(j >= 10 && i == m)
//             {
//                 cout << "  " << j;
//             }
//             else if (i == m && j < 10 && j == 1)
//             {
//                 cout << "    " << j; 
//             }
//             else if (i == m && j < 10 && j != 1)
//             {
//                 cout << "   " << j;
//             }
//         }
//     }

//     //makeMove
//     cout << endl;
//     gameStatus = true;
//     int pturn = 1;
//     bool validMove = true;
//     int row1;
//     int column1;
//     do
//     {
//         gameStatus = true;
//         string temp1, temp2, convert;
//         char test;
//         if (pturn == 1)
//         {
//             while (validMove && gameStatus)
//             { 
//                 //splitName(playerNames[0]);
//                 cout << " make your move:";
//                 cin >> move;
//                 row1 = move[0];
//                 while(row1 >= 32)
//                 {
//                     if (row1 >= 32)
//                     {
//                         row1 -= 32;
//                     }
//                     else if (row1 < 32)
//                     {
//                         break;
//                     }
//                 }
//                 row1 -= 1;
//                 temp1 = move[1];
//                 temp2 = move[2];
//                 convert = temp1 + temp2;
//                 column1 = stoi(convert) - 1;
//                 if ((move[0] < 'A' || move[0] > 'Z') || (move[0] < 'a' || move[0] > 'z'))
//                 {
//                     validMove = false;
//                 }
//                 else
//                 {
//                     cout << "You can't make that move, try again" << endl;
//                     cout << " make your move:";
//                     cin >> move;
//                 }
//                 if (currentBoard[row1][column1] != ' ')
//                 {
//                     cout << "You can't make that move, try again" << endl;
//                     cout << " make your move:";
//                     cin >> move;
//                 }
//                 currentBoard[row1][column1] = 'a';
//                 gameStatus = false;
//             }
//             pturn++;
//         } 
//         if (pturn == 2)
//         {
//             while (validMove && gameStatus)
//             { 
//                 cout << " make your move:";
//                 cin >> move;
//                 row1 = move[0];
//                 while(row1 >= 32)
//                 {
//                     if (row1 >= 32)
//                     {
//                         row1 -= 32;
//                     }
//                     else if (row1 < 32)
//                     {
//                         break;
//                     }
//                 }
//                 row1 -= 1;
//                 temp1 = move[1];
//                 temp2 = move[2];
//                 convert = temp1 + temp2;
//                 column1 = stoi(convert) - 1;
//                 if ((move[0] < 'A' || move[0] > 'Z') || move[0] < 'a' || move[0] > 'z')
//                 {
//                     validMove = false;
//                 }
//                 else
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                 }
//                 if (currentBoard[row1][column1] != ' ')
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                     cin >> move;
//                 }
//                 currentBoard[row1][column1] = 'b';
//                 gameStatus = false;
//             }
//             if (players == 2)
//             {
//                 pturn = 1;
//             }
//             else
//             {
//                 pturn++;
//             }
//         }
//         if (pturn == 3)
//         {
//             while (validMove && gameStatus)
//             { 
//                 cout << " make your move:";
//                 cin >> move;
//                 row1 = move[0];
//                 while(row1 >= 32)
//                 {
//                     if (row1 >= 32)
//                     {
//                         row1 -= 32;
//                     }
//                     else if (row1 < 32)
//                     {
//                         break;
//                     }
//                 }
//                 row1 -= 1;
//                 temp1 = move[1];
//                 temp2 = move[2];
//                 convert = temp1 + temp2;
//                 column1 = stoi(convert) - 1;
//                 if ((move[0] < 'A' || move[0] > 'Z') || move[0] < 'a' || move[0] > 'z')
//                 {
//                     validMove = false;
//                 }
//                 else
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                 }
//                 if (currentBoard[row1][column1] != ' ')
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                     cin >> move;
//                 }
//                 currentBoard[row1][column1] = 'c';
//                 gameStatus = false;
//             }
//             if (players == 3)
//             {
//                 pturn = 1;
//             }
//             else
//             {
//                 pturn++;
//             }
//         }
//         if (pturn == 4)
//         {
//             while (validMove && gameStatus)
//             { 
//                 cout << " make your move:";
//                 cin >> move;
//                 row1 = move[0];
//                 while(row1 >= 32)
//                 {
//                     if (row1 >= 32)
//                     {
//                         row1 -= 32;
//                     }
//                     else if (row1 < 32)
//                     {
//                         break;
//                     }
//                 }
//                 row1 -= 1;
//                 temp1 = move[1];
//                 temp2 = move[2];
//                 convert = temp1 + temp2;
//                 column1 = stoi(convert) - 1;
//                 if ((move[0] < 'A' || move[0] > 'Z') || move[0] < 'a' || move[0] > 'z')
//                 {
//                     validMove = false;
//                 }
//                 else
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                 }
//                 if (currentBoard[row1][column1] != ' ')
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                     cin >> move;
//                 }
//                 currentBoard[row1][column1] = 'd';
//                 gameStatus = false;
//             }
//             if (players == 4)
//             {
//                 pturn = 1;
//             }
//             else
//             {
//                 pturn++;
//             }
//         }
//         if (pturn == 5)
//         {
//             while (validMove && gameStatus)
//             { 
//                 cout << " make your move:";
//                 cin >> move;
//                 row1 = move[0];
//                 while(row1 >= 32)
//                 {
//                     if (row1 >= 32)
//                     {
//                         row1 -= 32;
//                     }
//                     else if (row1 < 32)
//                     {
//                         break;
//                     }
//                 }
//                 row1 -= 1;
//                 temp1 = move[1];
//                 temp2 = move[2];
//                 convert = temp1 + temp2;
//                 column1 = stoi(convert) - 1;
//                 if ((move[0] < 'A' || move[0] > 'Z') || move[0] < 'a' || move[0] > 'z')
//                 {
//                     validMove = false;
//                 }
//                 else
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                 }
//                 if (currentBoard[row1][column1] != ' ')
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                     cin >> move;
//                 }
//                 currentBoard[row1][column1] = 'e';
//                 gameStatus = false;
//             }
//             if (players == 5)
//             {
//                 pturn = 1;
//             }
//             else
//             {
//                 pturn++;
//             }
//         }
//         if (pturn == 6)
//         {
//             while (validMove && gameStatus)
//             { 
//                 cout << " make your move:";
//                 cin >> move;
//                 row1 = move[0];
//                 while(row1 >= 32)
//                 {
//                     if (row1 >= 32)
//                     {
//                         row1 -= 32;
//                     }
//                     else if (row1 < 32)
//                     {
//                         break;
//                     }
//                 }
//                 row1 -= 1;
//                 temp1 = move[1];
//                 temp2 = move[2];
//                 convert = temp1 + temp2;
//                 column1 = stoi(convert) - 1;
//                 if ((move[0] < 'A' || move[0] > 'Z') || move[0] < 'a' || move[0] > 'z')
//                 {
//                     validMove = false;
//                 }
//                 else
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                 }
//                 if (currentBoard[row1][column1] != ' ')
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                     cin >> move;
//                 }
//                 currentBoard[row1][column1] = 'f';
//                 gameStatus = false;
//             }
//             if (players == 6)
//             {
//                 pturn = 1;
//             }
//             else
//             {
//                 pturn++;
//             }
//         }
//         if (pturn == 7)
//         {
//             while (validMove && gameStatus)
//             { 
//                 cout << endl << " make your move:";
//                 cin >> move;
//                 row1 = move[0];
//                 while(row1 >= 32)
//                 {
//                     if (row1 >= 32)
//                     {
//                         row1 -= 32;
//                     }
//                     else if (row1 < 32)
//                     {
//                         break;
//                     }
//                 }
//                 row1 -= 1;
//                 temp1 = move[1];
//                 temp2 = move[2];
//                 convert = temp1 + temp2;
//                 column1 = stoi(convert) - 1;
//                 if ((move[0] < 'A' || move[0] > 'Z') || move[0] < 'a' || move[0] > 'z')
//                 {
//                     validMove = false;
//                 }
//                 else
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                 }
//                 if (currentBoard[row1][column1] != ' ')
//                 {
//                     cout << "You can't make that move, try again:" << endl;
//                     cin >> move;
//                 }
//                 currentBoard[row1][column1] = 'g';
//                 gameStatus = false;
//             }
//             pturn = 1;
//         }
//         for (int i = 1; i <= m; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if(j >= 10 && i == 1)
//                 {
//                     cout << "  " << j;
//                 }
//                 else if (i == 1 && j < 10)
//                 {
//                     cout << "   " << j; 
//                 }
//                 if (j == n && i == 1)
//                 {
//                     cout << endl;
//                 }
//             }
//             for (int j = 1; j <= n; j++)
//             {
//                 if(j == 1)
//                 {
//                     cout << "   --- ";
//                 }
//                 else 
//                 {
//                     cout << "--- ";
//                 }
//             }
//             cout << endl;
//             for (int j = 1; j <= n; j++)
//             {
//                 if(j == 1)
//                 {
//                     cout << char(i + 64);
//                 }
//                 cout << " | " << currentBoard[i - 1][j - 1];
//                 if(j == n)
//                 {
//                     cout << " | " << char(i + 64);
//                 }
//             }
//             cout << endl;
//             for (int j = 1; j <= n; j++)
//             {
//                 if (i == m && j == 1)
//                 {
//                     cout << "   --- ";
//                 }
//                 else if(i == m && j > 1)
//                 {
//                     cout << "--- ";
//                 }
//             }
//             if(i == m)
//             {
//                 cout << endl;
//             }
//             for (int j = 1; j <= n; j++)
//             {
//                 if(j >= 10 && i == m)
//                 {
//                     cout << "  " << j;
//                 }
//                 else if (i == m && j < 10)
//                 {
//                     cout << "   " << j; 
//                 }
//             }
//         }    
//     } while (!gameStatus && validMove);
//     // horizontal check
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             // m = rows; n = columns
//             if (currentBoard[i][j] == 'a' && currentBoard[i + 1][j] == 'a' && currentBoard[i + 2][j] == 'a')
//             {
//                 cout << "Player 1 wins";
//             }
//         }
//     }
// }
}