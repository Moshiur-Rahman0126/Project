#include <iostream>
#include <conio.h>
#include<iomanip>
#include<stdlib.h>
#include <ctime>
#include <cstdio>
#include <cstdlib>
using namespace std;



int computerRandomPick;
int computerPick;
int playerChoice;
bool playerTurn;
int gameWin = 3;



char blockOne = '1';
char blockTwo = '2';
char blockThree = '3';
char blockFour = '4';
char blockFive = '5';
char blockSix = '6';
char blockSeven = '7';
char blockEight = '8';
char blockNine = '9';

int turnFirst;

int checkWinComputer()
{
    if(blockOne == 'O' && blockFive == 'O' && blockNine == 'O' && playerTurn == false)
        gameWin = 2;
    if(blockThree == 'O' && blockFive == 'O' && blockSeven == 'O' && playerTurn == false)
        gameWin = 2;
    if(blockOne == 'O' && blockTwo == 'O' && blockThree == 'O' && playerTurn == false)
        gameWin = 2;
    if(blockFour == 'O' && blockFive == 'O' && blockSix == 'O' && playerTurn == false)
        gameWin = 2;
    if(blockSeven == 'O' && blockEight == 'O' && blockNine == 'O' && playerTurn == false)
        gameWin = 2;
    if(blockOne == 'O' && blockFour == 'O' && blockSeven == 'O' && playerTurn == false)
        gameWin = 2;
    if(blockTwo == 'O' && blockFive == 'O' && blockEight == 'O' && playerTurn == false)
        gameWin = 2;
    if(blockThree == 'O' && blockSix == 'O' && blockNine == 'O' && playerTurn == false)
        gameWin = 2;
}
int checkWinPlayer()
{
    if(blockOne == 'X' && blockFive == 'X' && blockNine == 'X' && playerTurn == true)
        gameWin = 1; //This will make player win.
    if(blockThree == 'X' && blockFive == 'X' && blockSeven == 'X' && playerTurn == true)
        gameWin = 1;
    if(blockOne == 'X' && blockTwo == 'X' && blockThree == 'X' && playerTurn == true)
        gameWin = 1;
    if(blockFour == 'X' && blockFive == 'X' && blockSix == 'X' && playerTurn == true)
        gameWin = 1;
    if(blockSeven == 'X' && blockEight == 'X' && blockNine == 'X' && playerTurn == true)
        gameWin = 1;
    if(blockOne == 'X' && blockFour == 'X' && blockSeven == 'X' && playerTurn == true)
        gameWin = 1;
    if(blockTwo == 'X' && blockFive == 'X' && blockEight == 'X' && playerTurn == true)
        gameWin = 1;
    if(blockThree == 'X' && blockSix == 'X' && blockNine == 'X' && playerTurn == true)
        gameWin = 1;
}
int computerAI()
{
    playerTurn == false;

    if(blockOne == 'O' && blockTwo == 'O' && playerTurn == false && blockThree == '3')
    {
        blockThree = 'O';
        playerTurn = true;
    }

    if(blockFour == 'O' && blockFive == 'O' && playerTurn == false && blockSix == '6')
    {
        blockSix = 'O';
        playerTurn = true;
    }

    if(blockSeven == 'O' && blockEight == 'O' && playerTurn == false && blockNine == '9')
    {
        blockNine = 'O';
        playerTurn = true;
    }

    if(blockOne == 'O' && blockFour == 'O' && playerTurn == false && blockSeven == '7')
    {
        blockSeven = 'O';
        playerTurn = true;
    }

    if(blockTwo == 'O' && blockFive == 'O' && playerTurn == false && blockEight == '8')
    {
        blockEight = 'O';
        playerTurn = true;
    }

    if(blockThree == 'O' && blockSix == 'O' && playerTurn == false && blockNine == '9')
    {
        blockNine = 'O';
        playerTurn = true;
    }

    if(blockOne == 'O' && blockFive == 'O' && playerTurn == false && blockNine == '9')
    {
        blockNine = 'O';
        playerTurn = true;
    }

    if(blockThree == 'O' && blockFive == 'O' && playerTurn == false && blockSeven == '7')
    {
        blockSeven = 'O';
        playerTurn == true;
    }

    if((playerChoice == 1 || playerChoice == 5 || playerChoice == 9) && playerTurn == false)
    {
        if((blockOne == 'X' && blockFive == 'X') && playerTurn == false && blockNine == '9')
        {
            blockNine = 'O';
            playerTurn = true;
        }

        if((blockOne == 'X' && blockNine == 'X') && playerTurn == false && blockFive == '5')
        {
            blockFive = 'O';
            playerTurn = true;
        }

        if((blockFive == 'X' && blockNine == 'X') && playerTurn == false && blockOne == '1')
        {
            blockOne = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 3 || playerChoice == 5 || playerChoice == 7) && playerTurn == false)
    {
        if((blockSeven == 'X' && blockFive == 'X') && playerTurn == false && blockThree == '3')
        {
            blockThree = 'O';
            playerTurn = true;
        }

        if((blockSeven == 'X' && blockThree == 'X') && playerTurn == false && blockFive == '5')
        {
            blockFive = 'O';
            playerTurn = true;
        }

        if((blockFive == 'X' && blockThree == 'X') && playerTurn == false && blockSeven == '7')
        {
            blockSeven = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 1 || playerChoice == 2 || playerChoice == 3) && playerTurn == false)
    {
        if((blockOne == 'X' && blockTwo == 'X') && playerTurn == false && blockThree == '3')
        {
            blockThree = 'O';
            playerTurn = true;
        }

        if((blockOne == 'X' && blockThree == 'X') && playerTurn == false && blockTwo == '2')
        {
            blockTwo = 'O';
            playerTurn = true;
        }

        if((blockTwo == 'X' && blockThree == 'X') && playerTurn == false && blockOne == '1')
        {
            blockOne = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 4 || playerChoice == 5 || playerChoice == 6) && playerTurn == false)
    {
        if((blockFour == 'X' && blockFive == 'X') && playerTurn == false && blockSix == '6')
        {
            blockSix = 'O';
            playerTurn = true;
        }

        if((blockFour == 'X' && blockSix == 'X') && playerTurn == false && blockFive == '5')
        {
            blockFive = 'O';
            playerTurn = true;
        }

        if((blockFive == 'X' && blockSix == 'X') && playerTurn == false && blockFour == '4')
        {
            blockFour = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 7 || playerChoice == 8 || playerChoice == 9) && playerTurn == false)
    {
        if((blockSeven == 'X' && blockEight == 'X') && playerTurn == false && blockNine == '9')
        {
            blockNine = 'O';
            playerTurn = true;
        }

        if((blockSeven == 'X' && blockNine == 'X') && playerTurn == false && blockEight == '8')
        {
            blockEight = 'O';
            playerTurn = true;
        }

        if((blockEight == 'X' && blockNine == 'X') && playerTurn == false && blockSeven == '7')
        {
            blockSeven = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 1 || playerChoice == 4 || playerChoice == 7) && playerTurn == false)
    {
        if((blockOne == 'X' && blockFour == 'X') && playerTurn == false && blockSeven == '7')
        {
            blockSeven = 'O';
            playerTurn = true;
        }

        if((blockOne == 'X' && blockSeven == 'X') && playerTurn == false && blockFour == '4')
        {
            blockFour = 'O';
            playerTurn = true;
        }

        if((blockFour == 'X' && blockSeven == 'X') && playerTurn == false && blockOne == '1')
        {
            blockOne = 'O';
            playerTurn = true;
        }

    }

    if((playerChoice == 2 || playerChoice == 5 || playerChoice == 8) && playerTurn == false)
    {
        if((blockTwo == 'X' && blockFive == 'X') && playerTurn == false && blockEight == '8')
        {
            blockEight = 'O';
            playerTurn = true;
        }

        if((blockTwo == 'X' && blockEight == 'X') && playerTurn == false && blockFive == '5')
        {
            blockFive = 'O';
            playerTurn = true;
        }

        if((blockFive == 'X' && blockEight == 'X') && playerTurn == false && blockTwo == '2')
        {
            blockTwo = 'O';
            playerTurn = true;
        }
    }

    if((playerChoice == 3 || playerChoice == 6 || playerChoice == 9) && playerTurn == false)
    {
        if((blockThree == 'X' && blockSix == 'X') && playerTurn == false && blockNine == '9')
        {
            blockNine = 'O';
            playerTurn = true;
        }

        if((blockThree == 'X' && blockNine == 'X') && playerTurn == false && blockSix == '6')
        {
            blockSix = 'O';
            playerTurn = true;
        }

        if((blockSix == 'X' && blockNine == 'X') && playerTurn == false && blockThree == '3')
        {
            blockThree = 'O';
            playerTurn = true;
        }
    }
    else
    {
        do
        {

            if(blockOne == '1' && playerTurn == false)
            {
                playerTurn = true;
                blockOne = 'O';
            }
            if(blockTwo == '2' && playerTurn == false)
            {
                playerTurn = true;
                blockTwo = 'O';
            }
            if(blockThree == '3' && playerTurn == false)
            {
                playerTurn = true;
                blockThree = 'O';
            }
            if(blockFour == '4' && playerTurn == false)
            {
                playerTurn = true;
                blockFour = 'O';
            }
            if(blockFive == '5' && playerTurn == false)
            {
                playerTurn = true;
                blockFive = 'O';
            }
            if(blockSix == '6' && playerTurn == false)
            {
                playerTurn = true;
                blockSix = 'O';
            }
            if(blockSeven == '7' && playerTurn == false)
            {
                playerTurn = true;
                blockSeven = 'O';
            }
            if(blockEight == '8' && playerTurn == false)
            {
                playerTurn = true;
                blockEight = 'O';
            }
            if(blockNine == '9' && playerTurn == false)
            {
                playerTurn = true;
                blockNine = 'O';
            }
        }
        while(playerTurn = false);
    }
    return 0;
}

int checkPlayerInput()
{
    if(playerChoice == 1 && blockOne == '1')
        blockOne = 'X';
    if(playerChoice == 2 && blockTwo == '2')
        blockTwo = 'X';
    if(playerChoice == 3 && blockThree == '3')
        blockThree = 'X';
    if(playerChoice == 4 && blockFour == '4')
        blockFour = 'X';
    if(playerChoice == 5 && blockFive == '5')
        blockFive = 'X';
    if(playerChoice == 6 && blockSix == '6')
        blockSix = 'X';
    if(playerChoice == 7 && blockSeven == '7')
        blockSeven = 'X';
    if(playerChoice == 8 && blockEight == '8')
        blockEight = 'X';
    if(playerChoice == 9 && blockNine == '9')
        blockNine = 'X';


    return 0;
}

int checkComputerInput()
{
    if(computerPick == 1 && blockOne == '1')
        blockOne = 'O';
    if(computerPick == 2 && blockTwo == '2')
        blockTwo = 'O';
    if(computerPick == 3 && blockThree == '3')
        blockThree = 'O';
    if(computerPick == 4 && blockFour == '4')
        blockFour = 'O';
    if(computerPick == 5 && blockFive == '5')
        blockFive = 'O';
    if(computerPick == 6 && blockSix == '6')
        blockSix = 'O';
    if(computerPick == 7 && blockSeven == '7')
        blockSeven = 'O';
    if(computerPick == 8 && blockEight == '8')
        blockEight = 'O';
    if(computerPick == 9 && blockNine == '9')
        blockNine = 'O';

    return 0;
}

void gameBoard()
{
    cout << "+-----+-----+-----+" << endl;
    cout << "|  " <<blockOne << "  |  " << blockTwo << "  |  " << blockThree << "  |" << endl;
    cout << "+-----+-----+-----+" << endl;
    cout << "|  " <<blockFour << "  |  " << blockFive << "  |  " << blockSix << "  |" << endl;
    cout << "+-----+-----+-----+" << endl;
    cout << "|  " <<blockSeven << "  |  " << blockEight << "  |  " << blockNine << "  |\n";
    cout << "+-----+-----+-----+" << endl;
}

int checkTie()
{
    if(blockOne != '1' && blockTwo != '2' && blockThree != '3' && blockFour != '4' && blockFive != '5' && blockSix != '6' && blockSeven != '7' && blockEight != '8' && blockNine != '9')
    {
        cout << "It's a tie!" << endl;
        gameWin = 0;
    }

}
void board(char square[])
{
//system("cls");
cout << "\n\n\tTic Tac Toe\n\n";

cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
cout << endl;

cout << "     |     |     " << endl;
cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

cout << "_____|_____|_____" << endl;
cout << "     |     |     " << endl;

cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

cout << "_____|_____|_____" << endl;
cout << "     |     |     " << endl;

cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

cout << "     |     |     " << endl << endl;
}

int checkwin(char square[])
{
if (square[1] == square[2] && square[2] == square[3])

return 1;
else if (square[4] == square[5] && square[5] == square[6])

return 1;
else if (square[7] == square[8] && square[8] == square[9])

return 1;
else if (square[1] == square[4] && square[4] == square[7])

return 1;
else if (square[2] == square[5] && square[5] == square[8])

return 1;
else if (square[3] == square[6] && square[6] == square[9])

return 1;
else if (square[1] == square[5] && square[5] == square[9])

return 1;
else if (square[3] == square[5] && square[5] == square[7])

return 1;
else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
&& square[4] != '4' && square[5] != '5' && square[6] != '6'
&& square[7] != '7' && square[8] != '8' && square[9] != '9')

return 0;
else
return -1;
}



void double_()
{
    //RNGs
    srand(time(0));
    int playAgain;

    int playerScore = 0;
    int computerScore = 0;
    int ties = 0;

    do
    {
        system("CLS");
        turnFirst = rand()% (2 - 1 + 1)+1;//generates starting person.
        computerRandomPick = rand()% (9 - 1 + 1)+1;//computer first pick - random
        gameWin = 3;
        blockOne = '1';
        blockTwo = '2';
        blockThree = '3';
        blockFour = '4';
        blockFive = '5';
        blockSix = '6';
        blockSeven = '7';
        blockEight = '8';
        blockNine = '9';

        //BEGIN OF PROGRAM
        cout << "Welcome to Tic Tac Toe!" <<endl<< endl;
        cout << "Player: " << playerScore << " Computer: "<< computerScore << " Ties: " << ties << endl;

        if(turnFirst == 1)//player first
        {
            cout << "Please choose a grid to place (X): "<<endl<<endl;
            gameBoard();//Gameboard for tic tac toe
            while (!(cin >> playerChoice)) //error traps letters and words
            {
                cout << endl;
                cout << "Numbers only." << endl;
                cin.clear();
                cin.ignore(10000,'\n');
            }
            checkPlayerInput();
            system("CLS");
            gameBoard();
            playerTurn = false; //switches to computer
        }

        if(turnFirst == 2)//Computer first
        {
            computerRandomPick;
            computerPick = computerRandomPick;
            checkComputerInput();
            cout << "The computer is choosing...\n" << endl;
            playerTurn = true;
            gameBoard();
        }


        do
        {
            if(playerTurn == true)
            {
                cout << "Please choose a grid to place (X): "<<endl<<endl;
                while (!(cin >> playerChoice))
                {
                    cout << endl;
                    cout << "Numbers only." << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                checkPlayerInput();
                checkWinPlayer();
                checkTie();
                playerTurn = false;
            }

            if(playerTurn == false) //computer loop
            {
                computerAI();
                system("CLS");
                gameBoard();
                checkWinComputer();
                checkTie();
                playerTurn = true;
            }

        }
        while(gameWin > 2);

        if(gameWin == 0)
        {
            cout << "The game is a Tie!" << endl;
            ++ties;
        }


        if(gameWin == 1)
        {
            cout << "The player wins!" << endl;
            ++playerScore;
        }

        if(gameWin == 2)
        {
            cout << "The computer wins!" << endl;
            ++computerScore;
        }


        cout << "Player: " << playerScore << " "<< "Computer: " << computerScore << " Ties: "<< ties << endl;


        cout << "Play again?\n1. Yes\n2. No\n" << endl;

        while (!(cin >> playAgain))
        {
            cout << endl;
            cout << "Play again?\n1. Yes\n2. No\n" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }


    }
    while(playAgain == 1);

}
void single()
{
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int player = 1,i,choice;

char mark;
do
{
board(square);

if(player%2==1)
player=1;
else
player=2;


// player 2
if(player==2)
{
cout << "Players  " << player<<endl;
cout<<"Press Enter for CPU"<<endl;
choice=rand()%9;
mark='O';
int turn=1;
int placed=0;
while(placed==0)
{

if (choice == 1 && square[1] == '1'){
square[1] = mark;
placed=1;
}
else if (choice == 2 && square[2] == '2'){

square[2] = mark;
placed=1;
}
else if (choice == 3 && square[3] == '3'){

square[3] = mark;
placed=1;
}
else if (choice == 4 && square[4] == '4'){

placed=1;
square[4] = mark;
}
else if (choice == 5 && square[5] == '5'){

square[5] = mark;
placed=1;
}
else if (choice == 6 && square[6] == '6'){

square[6] = mark;
placed=1;
}
else if (choice == 7 && square[7] == '7'){

square[7] = mark;
placed=1;
}
else if (choice == 8 && square[8] == '8'){

square[8] = mark;
placed=1;
}
else if (choice == 9 && square[9] == '9'){

square[9] = mark;
placed=1;
}

else
{
choice=rand()%9;
}
}
i=checkwin(square);
player++;
_getche();
board(square);
}

// player 1
else if(player==1)
{
cout << "Players  " << player << ", enter a number:  ";
cin >> choice;
mark='X';

if (choice == 1 && square[1] == '1')

square[1] = mark;
else if (choice == 2 && square[2] == '2')

square[2] = mark;
else if (choice == 3 && square[3] == '3')

square[3] = mark;
else if (choice == 4 && square[4] == '4')

square[4] = mark;
else if (choice == 5 && square[5] == '5')

square[5] = mark;
else if (choice == 6 && square[6] == '6')

square[6] = mark;
else if (choice == 7 && square[7] == '7')

square[7] = mark;
else if (choice == 8 && square[8] == '8')

square[8] = mark;
else if (choice == 9 && square[9] == '9')

square[9] = mark;
else
{
cout<<"Invalid move ";

player--;
_getche();
}
i=checkwin(square);

player++;
}
}while(i==-1);
board(square);
if(i==1)

cout<<"Congratulation! \nPlayer "<<--player<<" win ";
else
cout<<"  OOps!\nGame draw";

_getche();
}
int main()
{
    int mode;
    cout<<"Enter 1 for player vs player :"<<endl;
    cout<<"Enter 2 player vs computer :"<<endl;
    cin>>mode;
    if(mode==2)
    double_();
    else
    single();
}
