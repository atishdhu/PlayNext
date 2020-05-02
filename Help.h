#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED

void Help()
{
    system ("CLS");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    cout << "\t\t\t\t\t|            --> HELP MENU <--           |\n";

    cout << "\n";

    SetConsoleTextAttribute(hConsole, 10);
    cout << " How to use PlayNext?" << endl;
    cout << "\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "   1. Select < 1 > on the main menu to start the program." << endl;
    cout << "   2. In the main categories menu, select a main category of game you are interested in." << endl;
    cout << "   3. In the subcategories menu, select a subcategory of game you are interested in." << endl;
    cout << "   4. The program will output a list of games of that subcategory which you can export as a text file." << endl;

    cout << "\n";

    SetConsoleTextAttribute(hConsole, 10);
    cout << " How to export the list of games?" << endl;
    cout << "\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "   1. Once you select the subcategory you prefer, the program will ask if you want to export the list." << endl;
    cout << "   2. Select 'y' for yes and you will be asked to input a file path of where to export the file to." << endl;
    cout << "   3. The file path should be in the following format C:\\Users\\user\\" << endl;
    cout << "   4. Then you will be asked to input a file name." << endl;
    cout << "   5. The text file will be exported to the path specified with the file name entered." << endl;

    cout << "\n";

    SetConsoleTextAttribute(hConsole, 10);
    cout << " What game informations are provided?" << endl;
    cout << "\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "   The default information are \n";
    cout << "\n";
    SetConsoleTextAttribute(hConsole, 13);
    cout << "   - Game Title\n   - Steam Rating\n   - YouTube link to the trailer video\n   - Price of the game on steam" << endl;

    cout << "\n";

    SetConsoleTextAttribute(hConsole, 14);
    cout << "   The steam rating levels from best to worst is as follows: " << endl;
    SetConsoleTextAttribute(hConsole, 13);
    cout << "   \n   - Overwhelmingly Positive \n   - Very Positive \n   - Positive \n   - Mostly Positive \n   - Mixed \n   - Mostly Negative \n   - Negative" << endl;

    cout << "\n";

    SetConsoleTextAttribute(hConsole, 11);

    system ("PAUSE");

    MainMenu(); // Resets the main menu
}

#endif // HELP_H_INCLUDED
