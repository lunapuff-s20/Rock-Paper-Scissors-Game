#include <iostream>
using namespace std;

void gameRules();
int showRounds(int rounds);
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
int chooseWinner(char player, char computer);
void scoreCount(int win, int playerPoint, int computerPoint);

int main(){
    char player, computer;
    cout << "\n ******* ROCK-PAPER-SCISSORS ******* \n";
    cout << "------------------------------------- \n";
    char choice;
    int rounds = 1, win, playerPoint = 0, computerPoint = 0; 

    do {
        showRounds(rounds);
        player = getUserChoice();
        cout << "Your choice: ";
        showChoice(player);

        computer = getComputerChoice();
        cout << "Computer: ";
        showChoice(computer);

        win = chooseWinner(player, computer);
        
        if(win == 1){
            playerPoint ++;
        }
        else if(win == 0){
            computerPoint++;
        }
        cout << "\n> Your point: " << playerPoint << '\n';
        cout << "> Computer's point: " << computerPoint << "\n\n";

        cout << "Enter any key to keep playing or enter 'n' to exit: ";
        cin >> choice;
        cout << "-------------------------------------\n";
        rounds++;

    } while(choice != 'n' && choice != 'N');
    return 0;
}

void gameRules(){
    cout << "Enter as per follows: \n";
    cout << "'r' for Rock \n";
    cout << "'p' for Paper \n";
    cout << "'s' for Scissors \n";
    cout << ">> ";

}

int showRounds(int rounds){
    cout << "Round-" << rounds << " starts \n";
    return rounds;
}

char getUserChoice(){
    char player;
    do{ 
        gameRules();
        cin >> player;
    } while(player != 'r' && player != 'p' && player!= 's');
    
    return player;
}

char getComputerChoice(){
    srand(time(0));
    int num = rand() % 3 + 1;

    switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
    return 0;
}

void showChoice(char choice){
    switch(choice){
        case 'r': cout << "Rock\n";
            break;
        case 'p': cout << "Paper\n";
            break;
        case 's': cout << "Scissors\n";
            break;
        default: cout << "Invalid input!\n";

    }
}

int chooseWinner(char player, char computer){
    int win;
    if(player == computer){
        cout << "It's a draw! \n";
        win = 9;    // any random value
    }
    else if(player == 'r' && computer == 's' ||
            player == 'p' && computer == 'r' ||
            player == 's' && computer == 'p')
            {   
                cout << "You win! \n";
                win = 1;
            }
    else{
        cout << "You lose! \n";
        win = 0;
    }
    
    return win;
}

void scoreCount(int win, int playerPoint, int computerPoint){
    if(win == 1){
        playerPoint ++;
        cout << "Your point: " << playerPoint << '\n';
        cout << "Computer's point: " << computerPoint << '\n';
    }
    else{
        computerPoint++;
        cout << "Your point: " << playerPoint << '\n';
        cout << "Computer's point: " << computerPoint << '\n';
    }
}
