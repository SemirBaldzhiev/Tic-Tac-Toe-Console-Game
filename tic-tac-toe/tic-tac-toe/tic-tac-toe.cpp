#include <iostream>
#include<stdlib.h>

using std::cout;
using std::cin;
using std::endl;


char boardElements[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void drawBoard() 
{

    cout << "       |       |       " << endl;
    cout << "   "<< boardElements[0] << "   |   "<< boardElements[1] << "   |" <<"   "<< boardElements[2] << "   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << boardElements[3] << "   |   " << boardElements[4] << "   |" << "   " << boardElements[5] << "   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << boardElements[6] << "   |   " << boardElements[7] << "   |" << "   " << boardElements[8] << "   " << endl;
    cout << "       |       |       " << endl;
}


bool haveMoves()
{
    for (int i = 0; i < 9; i++)
    {
        if ((boardElements[i] != 'X') && (boardElements[i] != 'O'))
        {
            return true;
        }
    }

    return false;
}

int checkWin()
{
    bool firstPlayerWin = (boardElements[0] == 'X' && boardElements[1] == 'X' && boardElements[2] == 'X') ||
        (boardElements[3] == 'X' && boardElements[4] == 'X' && boardElements[5] == 'X') ||
        (boardElements[6] == 'X' && boardElements[7] == 'X' && boardElements[8] == 'X') ||
        (boardElements[0] == 'X' && boardElements[3] == 'X' && boardElements[6] == 'X') ||
        (boardElements[1] == 'X' && boardElements[4] == 'X' && boardElements[7] == 'X') ||
        (boardElements[2] == 'X' && boardElements[5] == 'X' && boardElements[8] == 'X') ||
        (boardElements[0] == 'X' && boardElements[4] == 'X' && boardElements[8] == 'X') ||
        (boardElements[2] == 'X' && boardElements[4] == 'X' && boardElements[6] == 'X');

    bool secondPlayerWin = (boardElements[0] == 'O' && boardElements[1] == 'O' && boardElements[2] == 'O') ||
        (boardElements[3] == 'O' && boardElements[4] == 'O' && boardElements[5] == 'O') ||
        (boardElements[6] == 'O' && boardElements[7] == 'O' && boardElements[8] == 'O') ||
        (boardElements[0] == 'O' && boardElements[3] == 'O' && boardElements[6] == 'O') ||
        (boardElements[1] == 'O' && boardElements[4] == 'O' && boardElements[7] == 'O') ||
        (boardElements[2] == 'O' && boardElements[5] == 'O' && boardElements[8] == 'O') ||
        (boardElements[0] == 'O' && boardElements[4] == 'O' && boardElements[8] == 'O') ||
        (boardElements[2] == 'O' && boardElements[4] == 'O' && boardElements[6] == 'O');


    if (!firstPlayerWin && !secondPlayerWin && !haveMoves())
    {
        return 0;
    }

    if (firstPlayerWin)
    {
        return 1;
    }
    else if (secondPlayerWin)
    {
        return 2;
    }

    return -1;
    
}

void setMark(char mark, int position)
{
    if (boardElements[position - 1] == (char)('0' + position))
    {
        boardElements[position - 1] = mark;
    }
}


int main()
{
    char firstPlayerName[32];
    char secondPlayerName[32];
    int firstPlayerNum = 0;
    int secondPlayerNum = 0;

    cout << "Enter first player name: ";
    cin.getline(firstPlayerName, 32);

    cout << "Enter second player name: ";
    cin.getline(secondPlayerName, 32);
    
    system("cls");
    
    int move = 1;
    int winner = -1;

    do
    {

        cout << "Player " << firstPlayerName << " - X" << "        " << "Player " << secondPlayerName << " - O" << endl;
        cout << endl;

        drawBoard();
        cout << endl;
        cout << "Player " << (move % 2 == 0 ? secondPlayerName : firstPlayerName) << " enter number: ";
        
        if (move % 2 == 0)
        {
            cin >> secondPlayerNum;
        }
        else 
        {
            cin >> firstPlayerNum;
        }
        
        char mark = move % 2 == 0 ? 'O' : 'X';
        int playerNum = move % 2 == 0 ? secondPlayerNum : firstPlayerNum;

        setMark(mark, playerNum);

        winner = checkWin();

        move++;

        system("cls");

    } while (winner == -1);

    cout << "Player " << firstPlayerName << " - X" << "        " << "Player " << secondPlayerName << " - O" << endl;
    cout << endl;
    drawBoard();

    cout << endl;
    if (winner != 0)
    {
        cout << "Congratulation " << (winner == 1 ? firstPlayerName : secondPlayerName) << ". You win!!!" << endl;
    }
    else
    {
        cout << "Draw!!" << endl;
    }
    
}