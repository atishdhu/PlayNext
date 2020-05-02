#ifndef CHOICE_H_INCLUDED
#define CHOICE_H_INCLUDED

// This function displays the Credits

void MainCategories(); // Function in the file Category.h
void Help();

void Choice(int choice)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Initialise the variable hConsole to set the color attribute.

    // Determines which function to initialize based on the choice of the user in the main menu
    switch(choice)
    {
    case 1 :
        MainCategories(); // Displays the list of Main Categories
        break;
    case 2 :
        Help(); // Resets the Main Menu
        break;
    case 3 :
        Credits(); // Shows the Credits available in the file Credits.h
        break;
    case 4 :
        Exit(); // Exits the program
        break;
    default :
        cin.clear();
        cin.ignore(100000, '\n');
        SetConsoleTextAttribute(hConsole, 14);
        cout << "Please choose an option (1 - 4)." << endl;
        cout << "\n";
        SetConsoleTextAttribute(hConsole, 11);
    }
}

#endif // CHOICE_H_INCLUDED
