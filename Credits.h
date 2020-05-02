#ifndef CREDITS_H_INCLUDED
#define CREDITS_H_INCLUDED

// This function displays the Credits

void Credits()
{
    system ("CLS");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\n\n\n\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\t\t\t\t\t\t\tABOUT" << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\t\t\t\t\tPlayNext helps you discover new Games." << endl;
    cout << "\n";
    cout << "\t\t     As a user, you can get instant suggestions using this recommendation engine." << endl;
    cout << "\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\t\t\t\t\t\t\tTEAM" << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\t\t\t\t\tDesigned and Developed by Atish Dhunnoo." << endl;
    cout << "\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\t\t\t\t\t\t     TECHNOLOGY" << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\t\t\t\t\t\tCoded entirely in C++." << endl;

    cout << "\n\n\n";

    SetConsoleTextAttribute(hConsole, 11);
    system ("PAUSE");

    MainMenu(); // Resets the main menu
}

#endif // CREDITS_H_INCLUDED
