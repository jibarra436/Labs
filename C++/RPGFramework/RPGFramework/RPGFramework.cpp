/*
    Name: Jose Ibarra
    Date: 1-28-2020

    Lab Link: https://edabit.com/challenge/8Fn2BKqrQXA5YoyS8
    (adapted from this lab, but did not follow to the letter)
*/

#include <iostream>
#include "RPGFramework.h"

#define GODMODE 0

// prototype functions
void getInput(Character&, Character&);
void fightAgain(Character&);
int getDifficulty();

// types of enemies that could spawn
std::string enemyTypes[4] = {
    "Goblin", "Troll", "Kobold", "Giant Rat"
};

// get user difficulty choice
int difficulty = getDifficulty();

int main()
{
    // let the user pick a name
    std::string charname;
    std::cout << "Please enter a name for your character: ";
    std::cin >> charname;

    // create player and enemy characters
    Character player(charname);

    // picks a random element from the enemyTypes array
    std::string enemyName = enemyTypes[rand() % 4];

    Character enemy(enemyName);

    // load player stats based on difficulty
    // easy, medium, and hard use different stats

    // godmode check
    if (GODMODE)
    {
        player.Load(5000, 5000, 5000, 1);
    }
    else if (difficulty == 1) // EASY
    {
        player.Load(100, 5, 5, 1);
    }
    else if (difficulty == 2) // MEDIUM
    {
        player.Load(50, 4, 3, 1);
    }
    else if (difficulty == 3) // HARD
    {
        player.Load(45, 3, 3, 1);
    }
    else // just in case this somehow happens
    {
        std::cout << "ERROR!  Assuming Medium Difficulty!";
        player.Load(50, 4, 3, 1);
    }

    // load enemy stats
    enemy.Load(difficulty, player.GetLevel());

    // start the battle
    getInput(player, enemy);
}

// recursively gets players choice for the turn
void getInput(Character& player, Character& enemy)
{
    // get user selection (only attack in this example)
    char selection;
    std::cout << "\nPress A to attack: ";
    std::cin >> selection;

    std::cout << std::endl;

    // to ensure the character is 'a' or 'A'
    if (tolower(selection) == 'a')
    {
        // give each character a turn
        player.Attack(enemy);
        enemy.Attack(player);

        // check if either character died in the last attack, and handle properly
        if (player.GetHP() <= 0)
        {
            // terminate if player died
            std::cout << "Player is dead!  Game Over!" << std::endl;
            return;
        }
        else if (enemy.GetHP() > 0)
        {
            // if both are still alive, continue battle
            getInput(player, enemy);
        }
        else if (enemy.GetHP() <= 0)
        {
            // if player is victorious, ask them to fight again
            fightAgain(player);
        }
    }
    else
    {
        std::cout << "\nInvalid Input!" << std::endl;
        getInput(player, enemy);
        return;
    }
}

// ask user if they want to fight again
void fightAgain(Character& player)
{
    char selection;
    std::cout << "\nFight another enemy?  Y/N: ";
    std::cin >> selection;

    // ensure 'y', 'Y', 'n', or 'N'
    if (tolower(selection) == 'y')
    {
        player.SetHP(player.GetMaxHP());

        // picks a random element from the enemyTypes array
        std::string enemyName = enemyTypes[rand() % 4];
        Character enemy(enemyName);
        enemy.Load(difficulty, player.GetLevel());

        std::cout << "A(n) " << enemyName << " has appeared!  Player character has been fully healed. (" << player.GetMaxHP() << " HP) - Good luck!\n" << std::endl;
        getInput(player, enemy);
    }
    else if (tolower(selection) == 'n')
    {
        std::cout << "Thank you for playing!" << std::endl;
        return;
    }
    else
    {
        std::cout << "\tInvalid Input!\t\t";
        fightAgain(player);
        return;
    }
}

// let player pick a difficulty
int getDifficulty()
{
    // prompt user with choices
    std::cout << "\n\n\nWelcome!  Please select a difficulty:" << std::endl;
    std::cout << "(E)ASY - You have much more health and higher stats than your enemy.\n";
    std::cout << "(M)EDIUM - You have slightly more health and stats than your enemy.\n";
    std::cout << "(H)ARD - You and your enemy are evenly matched.\n\n";

    char selection;

    std::cout << "Please select a difficulty (first letter): ";
    std::cin >> selection;

    // handle selection
    if (tolower(selection) == 'e')
    {
        return 1;
    }
    else if (tolower(selection) == 'm')
    {
        return 2;
    }
    else if (tolower(selection) == 'h')
    {
        return 3;
    }
    else
    {
        std::cout << "Invalid Input!\n";
        getDifficulty();
    }
}