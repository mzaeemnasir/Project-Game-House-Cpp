// Project

// Name:
// Roll No:
// Date:
// Game: Game House

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

// This Function will Get the Inputs from the User
void getUserDate(string &name, long int &nic, string &address, double &initial_balance)
{
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter NIC: ";
    cin >> nic;
    cout << "Enter Address: ";
    cin >> address;
    cout << "Enter Initial Balance: ";
    cin >> initial_balance;
}

// This Function will Generate the Random Number
// The Random Number will be between 0 and 10
int getRandomNumber()
{
    return rand() % 11;
}

// This Function will Generate the Random Players
int generateRandomMultiPlayers()
{
    // Gerating Random Number (3 to 6)
    int numberOfPlayers = (rand() % 4) + 3;
    return numberOfPlayers;
}
// Generating Random Betting Amount (100 - 999)
int getRandomBettingAmount()
{
    return rand() % 1001 + 100;
}

// Golden Table Game
void goldenTable(int playerBalance)
{
    cout << "\n\n ----- Golden Table ------ \n\n";
    int winPlayersArray[10] = {0}; // This Array will contain the Winner's List
    // --------About winPlayersArray---------
    // This array is initalized with 0
    // This array will contain the Winner's List
    // if the value of the array is 0, the player is not winner
    // if the value of the array is 1, the player is winner
    // ---------------------------------------

    int input, bettingAmount;
    int totalPlayers = generateRandomMultiPlayers(); // Getting Total Random Number of Players
    int playerNumber = rand() % totalPlayers + 1;    // Setting Player Number
    int userTable = rand() % totalPlayers + 1;       // Setting User Table
    totalPlayers += 1;                               // Includin 1 to Total Players to get the Total Players

    char choice = 'Y';
    // Here the Round Begain ....
    for (int j = 0; j < 3; j++)
    {
        int WinningNumber = getRandomNumber(); // Setting Winning Number

        cout << "Round Begins... \n\n";
        cout << "You will be playing on Table No " << userTable << " with Player " << playerNumber << endl;
        cout << totalPlayers << endl;
        for (int i = 1; i <= totalPlayers; i++)
        {
            if (i == playerNumber)
            {
                cout << "Number for Player " << i << ": ";
                cin >> input;
                do
                {
                    cout << "Betting Amount for Player " << i << ": ";
                    cin >> bettingAmount;
                    if (bettingAmount > playerBalance)
                    {
                        cout << "You don't have enough Balance to Bet. Please Try Again.\n";
                    }

                } while (bettingAmount > playerBalance);

                if (input == WinningNumber)
                {
                    winPlayersArray[i] = 1;
                    playerBalance = playerBalance + (4 * bettingAmount);
                }
                else
                {
                    // if the player lost the bet
                    playerBalance -= bettingAmount;
                }
                continue;
            }
            cout << "Number for Player " << i << ": ";
            sleep(1);
            int temp_number = getRandomNumber();
            cout << temp_number << endl;
            cout << "Betting Amount for Player " << i << ": ";
            sleep(1);
            cout << getRandomNumber() << endl;

            if (WinningNumber == temp_number)
            {
                winPlayersArray[i] = 1;
            }
        }
        // Here are Winners
        bool anyWinner = false;
        for (int i = 1; i < 10; i++)
        {
            if (winPlayersArray[i] == 1)
            {
                cout << "Player " << i << " Wins...\n";
                anyWinner = true;
            }
        }
        // I used this to check if any player is Winner
        // if there is no Winner, then No body wins will be displayed..
        if (!anyWinner)
        {
            cout << "Nobody Wins... \n";
        }

        // Here the Round Ends ....
        cout << "Round Ends... \n\n\n";
        if (winPlayersArray[playerNumber] == 1)
        {
            cout << "Congratulations… You have won…\n";
        }
        cout << "Your Remaining Balance is: " << playerBalance << "... \n\n\n";
        if (j == 2)
        {
            cout << "Do you want to play again? (Y/N)";
            cin >> choice;
            if (choice == 'Y')
            {
                j = 0;
            }
            else
            {
                cout << "Good Bye See you Again\n";
                exit;
            }
        }
    }
}

void Game(int playerBalance)
{

    int winPlayersArray[10] = {0}; // This Array will contain the Winner's List
    // --------About winPlayersArray---------
    // This array is initalized with 0
    // This array will contain the Winner's List
    // if the value of the array is 0, the player is not winner
    // if the value of the array is 1, the player is winner
    // ---------------------------------------

    int input, bettingAmount;
    int totalPlayers = generateRandomMultiPlayers(); // Getting Total Random Number of Players
    int playerNumber = rand() % totalPlayers + 1;    // Setting Player Number
    int userTable = rand() % totalPlayers + 1;       // Setting User Table
    totalPlayers += 1;                               // Includin 1 to Total Players to get the Total Players

    char choice = 'Y';
    // Here the Round Begain ....
    do
    {
        int WinningNumber = getRandomNumber(); // Setting Winning Number
        winPlayersArray[10] = {0};

        cout << "Round Begins... \n\n\n";
        cout << "You will be playing on Table No " << userTable << " with Player " << playerNumber << endl;
        for (int i = 1; i <= totalPlayers; i++)
        {
            if (i == playerNumber)
            {
                cout << "Number for Player " << i << ": ";
                cin >> input;
                do
                {
                    cout << "Betting Amount for Player " << i << ": ";
                    cin >> bettingAmount;
                    if (bettingAmount > playerBalance)
                    {
                        cout << "You don't have enough Balance to Bet. Please Try Again.\n";
                    }

                } while (bettingAmount > playerBalance);

                if (input == WinningNumber)
                {
                    winPlayersArray[i] = 1;
                    playerBalance += bettingAmount;
                }
                else
                {
                    // if the player lost the bet
                    playerBalance -= bettingAmount;
                }
                continue;
            }
            cout << "Number for Player " << i << ": ";
            sleep(1);
            int temp_number = getRandomNumber();
            cout << temp_number << endl;
            cout << "Betting Amount for Player " << i << ": ";
            sleep(1);
            cout << getRandomNumber() << endl;

            if (WinningNumber == temp_number)
            {
                winPlayersArray[i] = 1;
            }
        }
        // Here are Winners
        bool anyWinner = false;
        for (int i = 1; i < 10; i++)
        {
            if (winPlayersArray[i] == 1)
            {
                cout << "Player " << i << " is Winner\n";
                anyWinner = true;
            }
        }
        // I used this to check if any player is Winner
        // if there is no Winner, then No body wins will be displayed..
        if (!anyWinner)
        {
            cout << "Nobody Wins... \n";
        }

        // Here the Round Ends ....
        cout << "Round Ends... \n\n\n";
        if (winPlayersArray[playerNumber] == 1)
        {
            cout << "Congratulations… You have won…\n\n\n ";
        }
        cout << "Your Remaining Balance is: " << playerBalance << "... \n\n";
        if (winPlayersArray[playerNumber] == 1)
        {
            cout << "Do You want to play at Golden Table[Y/N]? ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                goldenTable(playerBalance);
                choice = 'N';
            }
            else
            {
                cout << "Do you want to Proceed on Simple Table [Y/N]? ";
                cin >> choice;
            }
        }
        else
        {
            cout << "Do you want to Proceed[Y/N]? ";
            cin >> choice;
        }

    } while (choice == 'Y' || choice == 'y');
}

// main function
int main()
{
    // Seeding the Random Numbers
    srand(time(0)); // Initialize the Random Number Generator
    string name;
    long int nic;
    string address;
    double initial_balance;
    char choice;
    cout << "--------Welcome to The Game House--------\n";
    cout << "New to the House?[Y/N] = ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        // Get the Inputs from the User
        getUserDate(name, nic, address, initial_balance);
        cout << "Sign up successfully... \n\n";
    }
    else
    {
        // Getting user data
        getUserDate(name, nic, address, initial_balance);
        cout << "Welcome back " << name << "\n\n";
    }
    Game(initial_balance);
    return 0;
}