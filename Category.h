#ifndef CATEGORY_H_INCLUDED
#define CATEGORY_H_INCLUDED

#include <fstream>
#include <cstring>

// This function displays the Main Categories from the file "Category.txt"

void FileCleanup(string fileName); // Function in the file FileCleanup.h
void SubCategories(int choice); // Function in the file SubCategory.h

void MainCategories()
{
    FileCleanup("Category.txt"); // Cleans up the file "Category.txt"

    ifstream MyReadFile("Category.txt"); // Opens the file "Category.txt" which contains all main categories
    string myText = "";

    int counter = 1, choice = 0;

    system ("CLS"); // Clears the console screen

    // Displays the Main Categories title
    cout << "\t\t\t\t\t       MAIN CATEGORIES" << endl;
    cout << "\t\t\t\t\t ----------------------------" << endl;

    // This loop outputs the text from the file
    while (getline(MyReadFile, myText))
    {
        // This if statement checks if there is an asterix(*) in the file. This asterix is used as an exit value for the function FileCleanup
        if (myText[0] == '*')
        {
            break; // If the asterix(*) is found, it is not output to the screen
        }

        cout << "\t\t\t\t\t         ---> " << myText[0] << " <---" << endl; // Displays the alphabets as the subtitle

        cout << "\t\t\t\t\t" << counter << ". "; // Numbers the different categories starting from 1

        // Outputs the text to the console
        for(int i = 2; i < myText.length(); i++)
        {
            // Checks if there is a tab character which indicates the next category
            if(myText[i] == '\t')
            {
                counter++;
                cout << "\n";
                cout << "\t\t\t\t\t" << counter << ". "; // Numbers the different categories
                continue; // If there is a tab character, continue the for loop with the next value of i
            }
            cout << myText[i]; // Outputs the character in the file
        }

        // Outputs the following separator once all categories for each alphabet has been output
        cout << "\n";
        cout << "\t\t\t\t\t ----------------------------\n" << endl;
        counter++;
    }

    MyReadFile.close();

    // This function determine the color of the text. 14 represents bright yellow
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);

    // The user has to choose a category or choose to go back to the main menu
    cout << "\t\tChoose a main category (1-" << counter - 1 << ") or type << 0 >> to go back to the main menu: ";
    cin >> choice;

    SetConsoleTextAttribute(hConsole, 11);

    // Checks which option the user chose
    if (choice < 0 || choice >= counter || cin.fail()) // Checks if the user has entered an option in the correct range or not
    {
        // If the user has entered an invalid option, the Main Categories menu resets
        cin.clear(); // Clears the incorrect input
        cin.ignore(100000, '\n'); // Ignores the incorrect input
        cout << "\t\tWrong Command. Please try again." << endl;
        system ("PAUSE"); // Waits for the user to press << ENTER >> to continue
        system ("CLS"); // Clear the text from the console screen
        MainCategories(); // Resets the Main Categories Menu
    }
    else if (choice == 0)
    {
        MainMenu(); // Resets the main menu
    }
    else if (choice > 0)
    {
        SubCategories(choice); // Displays the subcategories the user chose
    }
}

#endif // CATEGORY_H_INCLUDED
