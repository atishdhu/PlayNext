#ifndef EXPORT_H_INCLUDED
#define EXPORT_H_INCLUDED

// This function exports the selected file to the Desktop and renames it according to the user input

void Export(string path, string fileToExport, string fileName)
{
    string exportPath = path + "\\" + fileToExport + ".txt"; // Saves the file to the Desktop
    string importPath = fileName + ".txt";
    ofstream MyEditFile(exportPath); // Creates a file on the Desktop
    ifstream MyReadFile(importPath); // Open the file to be read

    string myText = "";
    int n = 0, fields = 1, counter = 1;

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

    MyEditFile << "\t\t\tSubCategory: " << fileName << "\n" << endl; // Writes the subcategory at the top of the file

    // This loop outputs the text from the file
    while (getline(MyReadFile, myText))
    {
        MyEditFile << "\t\t\t[ " << counter << " ]\n"; // Numbers the different game information starting from 1
        MyEditFile << "\t\t\t" << fieldName[n] << ": "; // Outputs the different labels stored in the array

        // This for loop outputs the text to the console
        for(int i = 0; i < myText.length(); i++)
        {
            if(myText[i] == '\t') // Checks if there is a tab character which indicates the next set of information
            {
                MyEditFile << "\n";
                n++;
                MyEditFile << "\t\t\t" << fieldName[n] << ": "; // Outputs the next label stored in the array}
                continue;
            }
            MyEditFile << myText[i]; // Outputs the character in the file
        }

        n = 0;

        // Outputs the following separator once all information for a particular game has been output
        MyEditFile << "\n";
        MyEditFile << "\t\t\t-----------------------------------------------------------\n\n";
        counter++;
    }

    MyReadFile.close(); // Close the file
    MyEditFile.close(); // Close the file
}


#endif // EXPORT_H_INCLUDED
