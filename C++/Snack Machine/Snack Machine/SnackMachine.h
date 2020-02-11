#pragma once
#include <string>

// SnackMachine class
class SnackMachine
{
private: // private variable
	std::string machineName;
	int changeLevel;
	const int maxChangeCapacity = 5000;
	int snackPrice;
	int inventoryLevel;
	const int maxInventoryCapacity = 100;
public: // public variables / methods
	// SnackMachine constructor
	SnackMachine(std::string name, int cost, int change, int inventory) {
		machineName = name;
		snackPrice = cost;
		changeLevel = change;
		inventoryLevel = inventory;
	}

	// get machine name
	std::string getMachineName() { return machineName; }

	// buys a snack, takes payment, change string, and status
	bool buyASnack(int payment, std::string *change, int *status)
	{
		if (payment < snackPrice) // if payment is not enough
		{
			*status = 0;
			return 0;
		}
		else if ((payment - snackPrice) > changeLevel) // if the machine does not have enough change
		{
			*status = 1;
			return 0;
		}
		else if (inventoryLevel < 1) // if there is not enough inventory
		{
			*status = 2;
			return 0;
		}
		else // otherwise everything went well, make purchase
		{
			if (payment > snackPrice) // if paid excess $, calculate change
			{
				changeLevel += snackPrice;
				*change = displayMoney(payment - snackPrice);
			}
			inventoryLevel--;
			*status = 3;
			return 1;
		}
	}

	// get inventory level
	int getInventoryLevel() { return inventoryLevel; }
	
	// get max inventory
	int getMaxInventoryCapacity() { return maxInventoryCapacity;  }

	// add to current inventory level
	bool incrementInventory(int amountToAdd)
	{
		int temp = inventoryLevel + amountToAdd;
		if (temp > maxInventoryCapacity) // if we cannot add more
			return 0;
		else // else add more
		{
			inventoryLevel += amountToAdd;
			return 1;
		}
	}

	// get change level
	std::string getChangeLevel() { return displayMoney(changeLevel); }

	// increment change level
	bool incrementChangeLevel(int amountToAdd)
	{
		int temp = changeLevel + amountToAdd;
		if (temp > maxChangeCapacity) // if we cannot add more
			return 0;
		else // else add more
		{
			changeLevel += amountToAdd;
			return 1;
		}
	}

	// return max change capacity in string form
	std::string getMaxChangeCapacity() { return displayMoney(maxChangeCapacity); }

	// return snack price in string form
	std::string getSnackPrice() { return displayMoney(snackPrice); }

	// convert int to string form
	std::string displayMoney(int amount) { return("$ " + std::to_string(amount / 100) + "." + std::to_string(amount % 100)); }

};