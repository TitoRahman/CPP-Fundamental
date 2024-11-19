/*
This is a template for MCD4720_Assignment 1
Created by: Jane Nikeisha Layndra
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayText(string filename) {
    string temp;
    ifstream myfile(filename);
    if (myfile.is_open()) {
        while (getline(myfile, temp)) {
            cout << temp << endl;
        }
        myfile.close();

        system("pause");
        system("CLS");
    } else {
        cout << "Error: Could not open the file" << endl;
    }
}


void stringAnalyser() {
    string String1, String2;
    cin.ignore();
    cout << "Hi there! Please enter the first string: ";
    getline(cin, String1);
    cout << "Hi there! Please enter the second string: ";
    getline(cin, String2);

    cout << "       a)Display the length of each strings.\n"
         << "               The length of (" << String1 << ") is: " << String1.length() << endl
         << "               The length of (" << String2 << ") is: " << String2.length() << endl << endl;

    cout << "       b)Create a new string by alternating characters from both strings.\n";

    string alternated;
    for (int i = 0; i < max(String1.length(), String2.length()); i++) {
        if (i < String1.length()) {
            alternated += String1[i];
        }
        if (i < String2.length()) {
            alternated += String2[i];
        }
    }
    cout <<"                 The alternating characters of " << String1 << " & " << String2 << " is: " << alternated << endl << endl;

    string lowerStr = String1;
    for (int i = 0; i < lowerStr.length(); i++) {
        if (lowerStr[i] >= 65 && lowerStr[i] <= 90) {
            lowerStr[i] = lowerStr[i] + 32;
        }
    }
    cout << "       c)Replacing all uppercase letters in first string with their corresponding lowercase letters " << String1 << " to lower is: " << lowerStr << endl;

    system("pause");
    system("CLS");
}


void generateArray() {
    const int rows = 5;
    const int cols = 5;
    int array[rows][cols];
    srand(time(0));

    cout << "The array values are: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % (50 + 1 - 10) + 10;
            cout << array[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "The max values are: \n";
    for (int j = 0; j < cols; j++) {
        int max = array[0][j];
        for (int i = 0; i < rows; i++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
        cout << max << "    ";
    }

    cout << endl << endl;

    for (int j =0; j < cols; j++) {
        array[0][j] = -1 ;
        array[rows - 1][j] = -1 ;
    }
    for (int i = 0; i < rows; i++) {
        array[i][0] = -1 ;
        array[i][cols - 1] = -1 ;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
    system("pause");
    system("CLS");
}


void spinRoulette() {
    srand(time(0));
    int rolledNumber = rand() % 37;

    cout << "A Roulette Wheel will be rolled --\n";
    int guessNum;
    cout << "Guess the number between 0 and 36: ";
    cin >> guessNum;

    while (guessNum < 0 || guessNum > 36) {
        cout << "The number between 0 and 36 is out of range. Try again!\n";
        cout << "Guess the number between 0 and 36: ";
        cin >> guessNum;
    }

    string guessRange;
    if (guessNum <= 18) {
        guessRange = "0-18";
    } else {
        guessRange = "19-36";
    }

    string rolledRange;
    if (rolledNumber <= 18) {
        rolledRange = "0-18";
    } else {
        rolledRange = "19-36";
    }

    if ((guessNum <= 18 && rolledNumber <= 18) || (guessNum > 18 && rolledNumber > 18)) {
        cout << "Well Done! That is correct, you guessed " << guessRange << " and it is " << rolledNumber << endl;
    } else {
        cout << "Wrong! You guessed " << guessRange << " and it is " << rolledNumber << endl;
    }

    system("pause");
    system("CLS");
}


void saveData(string message) {
    string title, name, workplace;
    int year;

    cin.ignore();
    cout << "Preferred Title: ";
    getline (cin, title);
    cout << "Enter your Name: ";
    getline (cin, name);
    cout << "Where do you work: ";
    getline (cin, workplace);
    cout << "How many years have you been working in: " << workplace << "?: ";
    cin >> year;

    string finalMessage = "Hi " + title + ". " + name + " you work in " + workplace + " since " + to_string(2024 - year) + ", it seems that you love working in this place.";
    cout << "This is the message:\n" << finalMessage << endl;

    cin.ignore();
    char yesNo;
    cout << "Do you want to save this message? (y/n) ";
    cin >> yesNo;

    if (yesNo == 'y' || yesNo == 'Y') {
        ofstream myFile("savedMessages.txt", ios::app);
        if (myFile.is_open()) {
            myFile << finalMessage << "\n";
            myFile.close();
            cout << "This message is saved in the text file (savedMessages.txt).\n";
            cout.flush();
        } else {
            cout << "Error opening the file.";
        }
    } else if (yesNo =='n' || yesNo =='N') {
        cout << "You opted not to save the message.";
    } else {
        cout << "Invalid option\n";
    }
    system("pause");
    system("CLS");

}


void runMenu() {
        int option;
        do {
            cout << "----------------------------------------------------" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "        Programing Fundamental Concepts         " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "[1] Display \"About\" Information" << endl;
            cout << "[2] String Analyser" << endl;
            cout << "[3] Generate a Random Array, Display Maximum Values, and Modify the Border" << endl;
            cout << "[4] Roulette Wheel Game" << endl;
            cout << "[5] Save a message to file." << endl;
            cout << "[6] End Testing the Program" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Which option would you like (1-6): ";
            cin >> option;

            if (option == 1) {
                displayText("About.txt");
            } else if (option == 2) {
                stringAnalyser();
            } else if (option == 3) {
                generateArray();
            } else if (option == 4) {
                spinRoulette();
            } else if (option == 5) {
                saveData("savedMessages.txt");
            } else if (option == 6) {
                cout << "Thank you for testing this application.";
            } else {
                cout << "Invalid Option" << endl;
            }
        } while (option != 6);

}

int main() {
    runMenu();
    return 0;
}