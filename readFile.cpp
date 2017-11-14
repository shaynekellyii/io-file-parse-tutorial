// Example program for reading a text file
// Shayne Kelly II
// November 13, 2017

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#define STRINGS_ARE_EQUAL 0

// Function prototypes
int parseLineForWord(string stringToParse, string wordToFind);
void saveResultsToFile(string inputFileName, string wordToFind, int numTimesWordFound);

int main(void) {
    
    // Declare input file stream and local vars
    ifstream fileInStream;
    string currentLine;
    string inputFileName;
    string wordToFind;
    string yesOrNo;
    int numTimesWordFound = 0;
    
    // Open file stream
    cout << "Type the file name that you would like to open: ";
    cin >> inputFileName;
    fileInStream.open(inputFileName);
    
    // Check if file was opened properly
    if (!fileInStream) {
        cerr << "Unable to open file. Exiting...\n\n";
        exit(1);
    }
    
    // Get the word to find in the file
    cout << "Type the word you would like to find in the file: ";
    cin >> wordToFind;
    
    // Read the file and parse each line
    while (fileInStream.good()) {
        getline(fileInStream, currentLine);
        numTimesWordFound += parseLineForWord(currentLine, wordToFind);
    }
    
    cout << "\nThe word " << wordToFind << " was found " << numTimesWordFound << " times.\n";
    
    // Save results to file if user desires
    cout << "Would you like to save the results to a file? (y for yes, n for no): ";
    cin >> yesOrNo;
    if (yesOrNo.compare("y") == STRINGS_ARE_EQUAL) {
        saveResultsToFile(inputFileName, wordToFind, numTimesWordFound);
    }
    
    // Cleanup the input stream
    fileInStream.close();
    exit(0);
}

// Parses a string with words separated by a space
// Returns the number of times the wordToFind is in the stringToParse
int parseLineForWord(string stringToParse, string wordToFind) {
    
    int numTimesWordFound = 0;
    string currentWord;
    
    // Create a stream for the line to parse
    stringstream stringStream(stringToParse);
    
    // Iterate through all the words in the stream
    while (stringStream >> currentWord) {
        if (currentWord.compare(wordToFind) == STRINGS_ARE_EQUAL) {
            numTimesWordFound++;
        }
    }
    
    return numTimesWordFound;
}

// Saves the results of the file parsing to a new output file
void saveResultsToFile(string inputFileName, string wordToFind, int numTimesWordFound) {
    string outputFileName;
    ofstream outputFileStream;
    
    // Get the output file name from the user
    cout << "Type the name of the output file: ";
    cin >> outputFileName;
    
    // Open/create the output file
    outputFileStream.open(outputFileName);
    if (!outputFileStream) {
        cerr << "Failed to open the output file. Exiting...\n\n";
    }
    
    // Write the results to the file
    outputFileStream << "The file was successfully parsed.\n";
    outputFileStream << "You searched for the word " << wordToFind << " in file " << inputFileName << ".\n";
    outputFileStream << wordToFind << " was found " << numTimesWordFound << " times.\n";
    
    // Let the user know that it worked
    cout << "The results were saved successfully to the file. Exiting...\n\n";
    
    // Cleanup the output stream
    outputFileStream.close();
}
