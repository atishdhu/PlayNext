#ifndef LISTGAMES_H_INCLUDED
#define LISTGAMES_H_INCLUDED

#include <fstream>

// This function displays the games information from the chosen file

void ListGames(string fileName)
{
    string myText = "";

    int n = 0, fields = 1, counter = 1;

    int colorCode[4] = {15,14,13,10}, colorCount = 0;

    ifstream MyReadFile(fileName); // Open the file provided by the SubCategory function

    cout << "\n";

    getline(MyReadFile, myText); // Reads the first line which contains the labels for each game information

    // This for loops finds the number of labels to determine the size of the array fieldName[fields]
    for(int i = 0; i < myText.length(); i++)
    {
        if(myText[i] == '\t') // For each tab character, there is a label, so the variable field is incremented by 1
        {
            fields++;
        }
    }

    string fieldName[fields] = {}; // Declared the array fieldName with the size of the variable fields

    //This for loop captures and stores the different labels in the array fieldName
    for(int j = 0; j < myText.length(); j++)
    {
        if(myText[j] == '\t') // For each tab character, there is a label, so the value is stored in the array at location n
        {
            n++;
            continue;
        }
        fieldName[n] += myText[j]; // Stores the label at location n which is incremented for each tab character read
    }

    n = 0; // Resets the value n to 0

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Initialize the variable hConsole to set the color attribute.

    // This loop outputs the text from the file
    while (getline(MyReadFile, myText))
    {
        SetConsoleTextAttribute(hConsole, 11); // This function determine the color of the text. 11 represents bright cyan
        cout << "\t\t\t[ " << counter << " ]" << endl; // Numbers the different game information starting from 1
        cout << "\t\t\t" << fieldName[n] << ": "; // Outputs the different labels stored in the array

        // This for loop outputs the text to the console
        for(int i = 0; i < myText.length(); i++)
        {
            SetConsoleTextAttribute(hConsole, 11);
            if(myText[i] == '\t') // Checks if there is a tab character which indicates the next set of information
            {
                cout << "\n";
                n++;
                SetConsoleTextAttribute(hConsole, 11);
                cout << "\t\t\t" << fieldName[n] << ": "; // Outputs the next label stored in the array
                colorCount++; // Increments the variable by 1 to change the color stored in the array colorCode[colorCount]
                if(colorCount > 3) // Makes sure the colorCount variable does not exceed the size of the array colorCode[colorCount]
                {
                    colorCount = 0;
                }
                continue;
            }
            SetConsoleTextAttribute(hConsole, colorCode[colorCount]);
            cout << myText[i]; // Outputs the character in the file
        }

        n = 0;

        // Outputs the following separator once all information for one game has been output
        cout << "\n";
        cout << "\t\t\t-----------------------------------------------------------\n" << endl;
        counter++;
        colorCount = 0; // Resets the color counter to start from the beginning
    }

    MyReadFile.close(); // Close the file
}

#endif // LISTGAMES_H_INCLUDED
