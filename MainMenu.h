#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#include <windows.h>

// This function displays the Main Menu

void Choice(int choice); // Function in the file Choice.h

void MainMenu()
{
    int choice = 0;

    system ("CLS"); // Clears the console screen

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11); // This function determine the color of the text. 11 represents bright cyan

    // This is the main menu
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t _______________________________________\n";
    cout << "\t\t\t\t\t|            --> PLAYNEXT <--           |\n";
    cout << "\t\t\t\t\t|        Game Recommendation Engine     |\n";
    cout << "\t\t\t\t\t|---------------------------------------|\n";
    cout << "\t\t\t\t\t| 1. | Start Program                    |\n";
    cout << "\t\t\t\t\t| 2. | Help                             |\n";
    cout << "\t\t\t\t\t| 3. | Credits                          |\n";
    cout << "\t\t\t\t\t| 4. | Exit Program                     |\n";
    cout << "\t\t\t\t\t|_______________________________________|\n";

    cout << "\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\t\t\t\tEnter your choice (1 - 4): ";
    cin >> choice; // This variable stores the choice of the user
    SetConsoleTextAttribute(hConsole, 11);

    cout << "\n";

    Choice(choice); // Executes the function in the file Choice.h

    // Checks if the choice is within range. If not, the program resets the main menu
    if(choice < 1 || choice > 4)
    {
        system("PAUSE");

        MainMenu(); // Resets the main menu
    }
}

#endif // MAINMENU_H_INCLUDED
