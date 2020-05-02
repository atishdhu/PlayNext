#ifndef FILECLEANUP_H_INCLUDED
#define FILECLEANUP_H_INCLUDED

#include <cstdio>
#include <fstream>
#include <cstring>

// This function cleans up extra tab characters from a file

void FileCleanup(string fileName)
{
    string myText = "", starText = "";
    char charFile[] = {};
    string newFile(fileName);

    ifstream MyReadFile;
    ofstream MyEditFile("temp.txt"); // Creats and open a file named "temp.txt"

    MyReadFile.open(fileName);

    /*  Checks if there is an asterix(*) at the end of the file. This indicates that the file has already been cleanup
        so exits out of the function and does not cleanup the file a second time */
    while(getline(MyReadFile, starText))
    {
        if(starText[0] == '*') // Checks if the first character in the line is an asterix(*) as it will always be the first character in the line
        {
            return; // If there is an asterix then the function FileCleanup is not executed
        }
    }

    MyReadFile.close(); // Close the file

    MyReadFile.open(fileName); // Reopen the file to start reading from the beginning

    // This section determines what to execute if an extra tab is encountered
    while(getline(MyReadFile, myText))
    {
        for(int i = 0; i < myText.length(); i++) // Loops through the characters of the file
        {
            if(i == myText.length() - 1) // Checks if we have reached the end of a line
            {
                if(myText[i] != '\t') // Checks if myText[i] is an alphabet/symbol or not
                {
                    MyEditFile << myText[i] << '\n'; // If it is an alphabet/symbol, it is written to the file followed by a return character
                    continue; // Jump back to the loop with the next value of i
                }
                else // If the current variable is not a character
                {
                    MyEditFile << '\n'; // Replace the current value with a return character
                    continue; // Jump back to the loop with the next value of i
                }
            }

            if(myText[i] == '\t') // If the current character is a tab
            {
                if(myText[i+1] == '\t' || i == myText.length() - 1) // If the tab is followed by another tab or the tab is the last character in the line
                {
                    MyReadFile.ignore(0,'\n'); // Ignore text until a return character is found which signifies the end of the line
                    continue; // Jump back to the loop with the next value of i
                }
            }

            MyEditFile << myText[i]; // Writes any other character to the file
        }
    }

    MyEditFile.close(); // Close the file "temp.txt"
    MyReadFile.close(); // Close the file read

    MyEditFile.open("temp.txt", ios::app); // Reopens the file "temp.txt" to append the asterix(*) value to it
    MyEditFile << '*'; // This indicates that the file has already been cleanup
    MyEditFile.close(); // Close the file "temp.txt"

    strcpy(charFile, fileName.c_str()); // Converts the variable fileName into a char array and store it in charFile[] char array

    // The remove function is used to delete the current file from the directory.
    remove(charFile); // The remove function only accepts char array.
    rename("temp.txt", charFile); // The rename function renames the file "temp.txt" to the deleted file's name. This is done to replace the deleted file.
}

#endif // FILECLEANUP_H_INCLUDED
