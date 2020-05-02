#ifndef SUBCATEGORY_H_INCLUDED
#define SUBCATEGORY_H_INCLUDED

// This function displays the Subcategories from the file "SubCategory.txt"

void MainCategories(); // Function in the file Category.h
void ListGames(string fileName); // Function in the file ListGames.h
void MenuButton(); // Function in the file MenuButton.h
void Export(string path, string fileName, string fileToExport);

void SubCategories(int choice)
{
    FileCleanup("SubCategory.txt");

    ifstream MyReadFile("SubCategory.txt"); // Opens the file "SubCategory.txt" which contains all subcategories
    string myText = "";
    string subHead = "";
    string fileName = "";
    string path = "";
    bool tabFail = false;
    char ans = '\0';
    string fileToExport = "";

    int counter = 1, subChoice = 0;

    system ("CLS"); // Clears the text on the console screen


    // Displays the SubCategories Title
    cout << "\t\t\t\t\t       SUBCATEGORIES" << endl;
    cout << "\t\t\t\t\t ----------------------------" << endl;

    // This loop skips the lines in the file until the correct line is reached
    for (int i = 1 ; i < choice ; i++)
        {
            MyReadFile.ignore(100000, '\n'); // Ignores 100000 characters or ignores until the return character('\n') is reached which signals the end of line
        }

    getline(MyReadFile, subHead, '\t'); // Stores the subtitle of the Subcategory in the variable subHead

    // These two lines formats the way to display the subtitle of the Subcategory
    cout << "\t\t\t\t\t    --> " << subHead << " <--" << endl;
    cout << "\t\t\t\t\t ----------------------------" << endl;

    // This loop outputs the text from the file to the console
    while(getline(MyReadFile, myText))
    {
        cout << "\t\t\t\t\t" << counter << ". "; // Numbers the different categories starting from 1
        // This loop outputs the text from each line
        for(int i = 0; i < myText.length(); i++)
        {
            cout << myText[i]; // Outputs each character to the console

            // Checks if there is a tab character which indicates the next subcategory
            if(myText[i] == '\t')
            {
                counter++;
                cout << '\n';
                cout << "\t\t\t\t\t" << counter << ". "; // Numbers the different categories
                continue; // If there is a tab character, continue the for loop with the next value of i
            }
        }
        break; // Once the appropriate line is output on the screen, the loop is exited to prevent other lines to output on the console screen
    }

    MyReadFile.close(); // Close the file

    cout << "\n";
    // Outputs the following separator once all subcategories in the line is output to the screen
    cout << "\t\t\t\t\t ----------------------------" << endl;

    cout << "\n";

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    // The user has to choose a subcategory which is stored in the variable subChoice to continue
    cout << "\t\t\t\t\t  Choose a sub category: ";
    cin >> subChoice;

    SetConsoleTextAttribute(hConsole, 11);

    // Checks if the option the user chose is in the correct range
    if (subChoice < 1 || subChoice > counter || cin.fail())
    {
        cin.clear(); // Clears the incorrect input
        cin.ignore(100000, '\n'); // Ignores the incorrect input
        cout << "\t\tWrong Command. Please try again." << endl;
        system ("PAUSE"); // Waits for the user to press << ENTER >> to continue
        system ("CLS"); // Clear the text from the console screen
        SubCategories(choice); // Resets the Subcategories Menu
    }

    // This section is used to determine which option the user chose
    MyReadFile.open("SubCategory.txt"); // Reopen the file to read from the start

    // This loop skips the lines in the file until the correct line is reached
    for (int i = 1 ; i < choice ; i++)
        {
            MyReadFile.ignore(100000, '\n');
        }
    // This loop finds the start of the subcategory the user selected
    for (int i = 0 ; i < subChoice ; i++)
        {
            MyReadFile.ignore(100000, '\t');
        }

        /*  This section checks if the subcategory selected is the last item on that line. If it is then the filename will be
            incorrect so it breaks out of the loop */

        /*  This getline function reads the characters until the tab character is reached and stores them in the variable fileName.
            These characters determine the name of the file to read next. */
        getline(MyReadFile, fileName, '\t');

        /* This for loop is used to determine if the subcategory is the last in that line.
        If is is then the fileName is invalid and is not stored. */
        for(int i = 0; i < fileName.length();i++)
        {
            if(fileName[i] == '\n') // Checks if the fileName contains the return character which will indicate that it is the last element on the line.
            {
                tabFail = true; // This variable is set to true to indicate that the fileName is the last element on the line
                break; // Breaks out of the loop
            }
        }

    MyReadFile.close(); // Closes the file

    if(tabFail == true) // If the fileName is the last element on the line then this piece of code will capture the fileName correctly
    {
        MyReadFile.open("SubCategory.txt"); // Reopen the file to read from the start

        // This loop finds the subcategory the user selected
        for (int i = 1 ; i < choice ; i++)
        {
            MyReadFile.ignore(100000, '\n');
        }

        // This loop finds the start of the subcategory the user selected
        for (int i = 0 ; i < subChoice ; i++)
        {
            MyReadFile.ignore(100000, '\t');
        }

        /*  This getline function reads the characters until the return character is reached and stores them in the variable fileName.
            These characters determine the name of the file to read next. */
        getline(MyReadFile, fileName, '\n');
        tabFail = false;
    }

    MyReadFile.close(); // Close the file

    cout << "\n";

    ListGames(fileName + ".txt"); // List the elements found in the file

    SetConsoleTextAttribute(hConsole, 10);

    cout << "\t\t\tDo you want to export the list? (Y/N) " ;
    cin >> ans; // This variable stores the choice of the user

    switch (ans)
    {
    case 'Y':
    case 'y': // If the user choose Yes, then the following function is executed
        cout << "\t\t\tEnter the path to save the file to: ";
        SetConsoleTextAttribute(hConsole, 14);
        cin >> path; // This variable stores the name of the file to create on the Desktop
        SetConsoleTextAttribute(hConsole, 10);
        cout << "\t\t\tEnter the name of the file: ";
        SetConsoleTextAttribute(hConsole, 14);
        cin >> fileToExport; // This variable stores the name of the file to create on the Desktop
        SetConsoleTextAttribute(hConsole, 10);
        Export(path, fileToExport, fileName); // The function Export is executed with the name of the exported file and the name of the file to be exported
        cout << "\t\t\tExport Complete\n" << endl;
        break;
    case 'N':
    case 'n':
        break; // If user's choice is No, then it exits out of the switch statement
    default : // For any other choices, the following statement will resets the Subcategory Menu
        cin.clear(); // Clears the incorrect input
        cin.ignore(100000, '\n'); // Ignores the incorrect input
        cout << "\t\tWrong Command. Please try again." << endl;
        system ("PAUSE"); // Waits for the user to press << ENTER >> to continue
        SubCategories(choice); // Resets the Subcategory menu
    }

    cout << "\n";

    MenuButton(); // Gives the user the option to reset the main menu or reset the main categories menu
}

#endif // SUBCATEGORY_H_INCLUDED
