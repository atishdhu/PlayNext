#ifndef MENUBUTTON_H_INCLUDED
#define MENUBUTTON_H_INCLUDED

#include <windows.h>

// This function enables the user to go back to main categories or back to the main menu
void SubCategories(int choice);

void MenuButton()
{
    int button = 0;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);

    cout << "\t\t\tChoose an option from the following commands: " << endl;
    cout << "\t\t\tType << 1 >> to go back to main categories." << endl;
    cout << "\t\t\tType << 0 >> to go back to the main menu." << endl;
    cout << "\t\t\t";
    cin >> button;

    // This statement determines which function to initialize when the user press a particular button
    switch(button)
    {
    case 0:
        SetConsoleTextAttribute(hConsole, 11);
        MainMenu(); // Resets the main menu
        break;
    case 1:
        SetConsoleTextAttribute(hConsole, 11);
        MainCategories(); // Resets the Main Categories Menu
        break;
    default:
        cout << "\t\t\tWrong Command. Please try again." << endl;
        SetConsoleTextAttribute(hConsole, 11);
        MenuButton(); // Resets this function until the user input the correct option
    }
}

#endif // MENUBUTTON_H_INCLUDED
