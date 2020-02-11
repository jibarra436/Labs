/*
	Name: Jose Ibarra
	Date: 2/11/2020

	The problem for this lab is taken from a programming assignment offered at UT: Arlington
*/

#include <iostream>
#include "SnackMachine.h"

// prototype functions
void snackMachinePrompt();
void exitPrompt();
void checkChoice(int choice);

// create snack machine - MySnackMachine(name, cost, change, inventory)
SnackMachine MySnackMachine("Snack Machine", 50, 500, 100);

// main function
int main()
{
	snackMachinePrompt();
}

// prompt the user with options (snack machine menu)
void snackMachinePrompt()
{
	// display menu
	std::cout << MySnackMachine.getMachineName() << "\n\nCurrent Stock: " << MySnackMachine.getInventoryLevel() << "/" << MySnackMachine.getMaxInventoryCapacity() << "\n\n";
	std::cout << "0. Walk away\n";
	std::cout << "1. Buy a snack\n";
	std::cout << "2. Restock Machine\n";
	std::cout << "3. Add change\n";
	std::cout << "4. Display Machine Info\n\n";
	
	// get user choice
	int choice;
	std::cin >> choice;

	// check if choice is an int
	if (!std::cin)
	{
		std::cout << "Invalid Input!\n";
		return;
	}
	else
		checkChoice(choice);
}

// check the user's choice
void checkChoice(int choice)
{
	if (choice == 0) // walk away
	{
		exitPrompt(); // call exit prompt
	}
	else if (choice == 1) // buy a snack
	{
		// get payment input
		int payment;

		std::cout << "\nPlease enter your payment (cents): ";
		std::cin >> payment;

		// check if payment is an int
		if (!std::cin)
		{
			std::cout << "Invalid Input!\n";
			return;
		}

		int status;
		std::string change;

		// call buyASnack (tries to buy, status is updated with outcome)
		MySnackMachine.buyASnack(payment, &change, &status);

		if (status == 0) // status 0 - payment < snackprice
		{
			std::cout << "You do not have enough money to afford a snack!\n\n";
			return snackMachinePrompt();
		}
		else if (status == 1) // status 1 - payment > changelevel
		{
			std::cout << "The machine does not have enough change!\n\n";
			return snackMachinePrompt();
		}
		else if (status == 2) // status 2 - inventory < 1
		{
			std::cout << "The machine does not have enough inventory!\n\n";
			return snackMachinePrompt();
		}
		else // otherwise, status 3 - successful
		{
			// let user know that purchase was successful, and display the change they got back if any
			if (change.length())
			{
				std::cout << "\nThank you for your purchase!\nYour change is " + change << "\n\n";
			}
			else
			{
				std::cout << "\nThank you for your purchase!\n\n";
			}
			return snackMachinePrompt();
		}
	}
	else if (choice == 2) // restock machine
	{
		// calculate difference to add in order to hit max capacity
		int invToAdd = MySnackMachine.getMaxInventoryCapacity() - MySnackMachine.getInventoryLevel();

		// add to inventory if possible
		bool added = MySnackMachine.incrementInventory(invToAdd);

		// if operation was successful and added more than 0
		if (added && invToAdd != 0)
		{
			std::cout << "\nInventory restocked!\n\n";
		}
		else // otherwise let the user know that the inventory is already at max capacity
		{
			std::cout << "\nInventory already full!\n\n";
		}
		snackMachinePrompt();
	}
	else if (choice == 3) // add change
	{
		// get input
		int changeToAdd;

		std::cout << "\nPlease enter the amount of change to add (cents): ";
		std::cin >> changeToAdd;

		// check if changeToAdd is an int
		if (!std::cin)
		{
			std::cout << "Invalid Input!\n";
			return;
		}

		// add if it can be added (defined in the MySnackMachine.incrementChangeLevel() method)
		bool added = MySnackMachine.incrementChangeLevel(changeToAdd);

		// if it was successfully added
		if (added)
		{
			std::cout << "\nChange added: " + MySnackMachine.displayMoney(changeToAdd) + "\n";
		}
		else // otherwise let the user know that the operation failed
		{
			std::cout << "\nCould not add that much change!\n";
		}
		std::cout << "Current change in machine: " << MySnackMachine.getChangeLevel() << "\n\n";
		snackMachinePrompt();
	}
	else if (choice == 4) // display machine info
	{
		std::cout << "\nCurrent Inventory Level: " << MySnackMachine.getInventoryLevel() << "\n";
		std::cout << "Max Inventory Level: " << MySnackMachine.getMaxInventoryCapacity() << "\n\n";

		std::cout << "Current Change Level: " << MySnackMachine.getChangeLevel() << "\n";
		std::cout << "Max Change Level: " << MySnackMachine.getMaxChangeCapacity() << "\n\n";

		std::cout << "Snack Price: " << MySnackMachine.getSnackPrice() << "\n\n";

		snackMachinePrompt();
	}
	else snackMachinePrompt(); // if user inputs an int that is not 1-4
}

// exitPrompt definition, asks user if they are sure about quitting
void exitPrompt()
{
	// get input (y/n)
	std::cout << "\nAre you sure? (Y/N): ";
	char confirm;
	std::cin >> confirm;

	// if y or Y, close program
	if (tolower(confirm) == 'y')
		return;
	else if (tolower(confirm) == 'n')  // if n or N, prompt the menu
		snackMachinePrompt();
	else // else, input is invalid
	{
		std::cout << "Invalid input!\n";
		exitPrompt();
	}
}