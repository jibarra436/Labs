/*
    Name: Jose Ibarra
    Date: 1-28-2020
    Lab Link: https://edabit.com/challenge/yHeTBuJ6LDw3nhA7k
*/

#include <iostream>
#include <vector>

using namespace std;

vector<string> makeBox(int size)
{
    if (size == 1) { return { "#" }; }
    else if (size == 2) { return { "##", "##" }; }
    else
    {
        vector<string> box;
        string endstr;
        string midstr;

        for (int i = 0; i < size; i++)
        {
            endstr += "#";
        }
        box.push_back(endstr);

        midstr += "#";
        for (int i = 1; i < size - 1; i++)
        {
            midstr += " ";
        }
        midstr += "#";

        for (int i = 0; i < size - 2; i++)
        {
            box.push_back(midstr);
        }
        box.push_back(endstr);

        return box;
    }
}

void printBox(vector<string> box)
{
    for (int i = 0; i < box.size(); i++)
    {
        cout << box.at(i) << endl;
    }
    cout << endl;
}

void getInput()
{
    int size;

    cout << "Enter a positive integer: ";
    cin >> size;

    if (size) {
        printBox(makeBox(size));
        getInput();
    }
    else {
        cout << endl << "Invalid input!" << endl;
        return;
    }
}

int main()
{
    getInput();
}