/*
    Name: Jose Ibarra
    Date: 1-28-2020
    Lab Link: https://edabit.com/challenge/yHeTBuJ6LDw3nhA7k
*/

#include <iostream>
#include <vector>

using namespace std;

// function prototypes
vector<string> makeBox(int);
void printBox(vector<string>);
void getInput();

// main function
int main()
{
    getInput();
}

// makeBox function definition
vector<string> makeBox(int size)
{
    // if 1 or 2, no need to go through the rest of the pattern.
    if (size == 1) { return { "#" }; }
    else if (size == 2) { return { "##", "##" }; }
    else // if size >2, we will need the 'middle' section of the box which is hollow
    {
        vector<string> box;
        string endstr;
        string midstr;

        // create the string of characters that will be on either end of the box
        for (int i = 0; i < size; i++)
        {
            endstr += "#";
        }
        // push one end of the box
        box.push_back(endstr);

        // for the 'middle' strings, add a # at the beginning
        midstr += "#";
        
        // concatenate spaces up until just before the last spot
        for (int i = 1; i < size - 1; i++)
        {
            midstr += " ";
        }

        // add the ending # for the 'middle' strings
        midstr += "#";

        // push the 'middle' strings to fill in the box (except for the last position)
        for (int i = 0; i < size - 2; i++)
        {
            box.push_back(midstr);
        }

        // finish the box with another ending string
        box.push_back(endstr);
        
        // return the box vector to main
        return box;
    }
}

// printBox functon definition
void printBox(vector<string> box)
{
    // print each element of the box on a seperate line
    for (int i = 0; i < box.size(); i++)
    {
        cout << box.at(i) << endl;
    }
    cout << endl;
}

// getInput function definition
void getInput()
{
    int size;

    // take input from user to determine box size
    cout << "Enter a positive integer: ";
    cin >> size;

    // if the input was valid, make and print the box.  also prompt user to make another box.
    if (size) {
        printBox(makeBox(size));
        getInput();
    }
    else { // if the input was invalid, tell the user and terminate.
        cout << endl << "Invalid input!" << endl;
        return;
    }
}