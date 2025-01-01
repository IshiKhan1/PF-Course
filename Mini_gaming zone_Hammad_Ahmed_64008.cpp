#include <iostream>
using namespace std;

struct Player {
    string name;
    int score;
    int id;  
};

void cricket();
void football();
void addPlayer(Player pl_list[], int &pl_count);
void showPlayers(Player pl_list[], int pl_count); 
Player pl_list[10];  
int pl_count = 0;       

int main() {
    int choice;

    do {
        cout << "\n==== Gaming Zone Menu ====" << endl;
        cout << "1. Add Player" << endl;
        cout << "2. Show Players" << endl;
        cout << "3. Play Cricket" << endl;
        cout << "4. Play Football" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPlayer(pl_list, pl_count);
                break;
            case 2:
                showPlayers(pl_list, pl_count); 
                break;
            case 3:
                cricket();
                break;
            case 4:
                football();
                break;
            case 5:
                cout << "Exiting the Gaming Zone. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

void addPlayer(Player pl_list[], int &pl_count) {
    if (pl_count >= 10) {
        cout << "Player limit reached.\n";
    } else {
        cout << "Enter player's name: ";
        cin >> pl_list[pl_count].name;
        cout << "Enter player's ID: ";
        cin >> pl_list[pl_count].id;
        pl_list[pl_count].score = 0; 
        pl_count++;  
        cout << "Player added successfully.\n";
    }
}

void showPlayers(Player pl_list[], int pl_count) {
    if (pl_count == 0) {
        cout << "No players added yet.\n";
    } else {
        cout << "\nPlayers List:" << endl;
        for (int i = 0; i < pl_count; i++) {
            cout << "Name: " << pl_list[i].name << ", ID: " << pl_list[i].id << endl;
        }
    }
}

void cricket() {
    if (pl_count < 2) {
        cout << "Not enough players to play cricket! Please add at least 2 players.\n";
    } else {
        int n, g, x = 1;

        cout << "\n" << pl_list[0].name << "'s turn to bat:\n";
        do {
            do {
                cout << pl_list[0].name << ", enter your n (1 to 6): ";
                cin >> n;
            } while (n < 1 || n > 6);

            do {
                cout << pl_list[1].name << ", guess the n (1 to 6): ";
                cin >> g;
            } while (g < 1 || g > 6);

            if (n == g) {
                cout << pl_list[1].name << " guessed correctly! " << pl_list[0].name << " is out!\n";
                x = 0;
            } else {
                pl_list[0].score += n;
                cout << pl_list[0].name << " scores " << n << " n! Total: " << pl_list[0].score << endl;
            }

        } while (x != 0);

        x = 1;
        cout << "\n" << pl_list[1].name << "'s turn to bat:\n";
        do {
            do {
                cout << pl_list[1].name << ", enter your n (1 to 6): ";
                cin >> n;
            } while (n < 1 || n > 6);

            do {
                cout << pl_list[0].name << ", guess the n (1 to 6): ";
                cin >> g;
            } while (g < 1 || g > 6);

            if (n == g) {
                cout << pl_list[0].name << " guessed correctly! " << pl_list[1].name << " is out!\n";
                x = 0;
            } else {
                pl_list[1].score += n;
                cout << pl_list[1].name << " scores " << n << " n! Total: " << pl_list[1].score << endl;
            }

        } while (x != 0);

        cout << "\nGame Over!\n";
        cout << pl_list[0].name << ": " << pl_list[0].score << " runs\n";
        cout << pl_list[1].name << ": " << pl_list[1].score << " runs\n";

        if (pl_list[0].score > pl_list[1].score)
            cout << pl_list[0].name << " wins!\n";
        else if (pl_list[1].score > pl_list[0].score)
            cout << pl_list[1].name << " wins!\n";
        else
            cout << "It's a draw!\n";
    }
}

void football() {
    if (pl_count < 1) {
        cout << "Not enough players to play football! Please add at least 1 player.\n";
    } else {
        int c, n;

        cout << "Football Game! Let's Play!\n";
        do {
            cout << "\nDefender's Turn:\n1. Dribble to Midfield\n2. Pass to Midfield\n3. Keep the Ball\n4. Clear the Ball\nChoose: ";
            cin >> c;
        } while (c < 1 || c > 4);

        cout << "Now, enter a positive integer: ";
        cin >> n;

        int comp = (((n * (n + 7)) % 4) + 1);

        if (c == comp) {
            cout << "Ball lost! Game Over!\n";
        } else {
            cout << "Move successful!\n";

            do {
                cout << "\nMidfielder's Turn:\n1. Dribble to Forward\n2. Pass to Forward\n3. Keep the Ball\n4. Through Ball\nChoose: ";
                cin >> c;
            } while (c < 1 || c > 4);

            cout << "Now, enter a positive integer: ";
            cin >> n;

            comp = (((n * (n + 7)) % 4) + 1);

            if (c == comp) {
                cout << "Ball lost! Game Over!\n";
            } else {
                cout << "Move successful!\n";

                do {
                    cout << "\nForward's Turn:\n1. Long Shot\n2. Knuckle Shot\n3. Curve Shot\n4. Chip Shot\nChoose: ";
                    cin >> c;
                } while (c < 1 || c > 4);

                cout << "Now, enter a positive integer: ";
                cin >> n;

                comp = (((n * (n + 7)) % 4) + 1);

                if (c == comp) {
                    cout << "Missed the shot!\n";
                } else {
                    cout << "Goal scored!\n";
                }
            }
        }
        cout << "Game Over!\n";
    }
}
