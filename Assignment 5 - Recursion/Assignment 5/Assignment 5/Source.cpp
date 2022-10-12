//Name: Zachary Williams
//Class: 2019 Fall - COSC 2336.S70
//Project #: Assignment 5 - Recursion
//Revision: 1.0.0
//Date: 10/26/19
//Description: Write a program that demonstrates a recursive function that exhaustively searches through all possible combinations of coin values
//to find the best way to make change for a specified amount.
//********************************************************************************
// Function makeChange. This function uses the following parameters:           
// coinsLeft - The number of coins left to choose from.                                                
// amount - The amount to make change for.                                                                      
// coinsUsed - An array that contains the coin values used so far.                         
// numCoinsUsed - The number of values in the coinsUsed array.                        
//                                                                                                                                                                    
// This recursive function finds all the possible ways to make change                 
// for the value in amount. The best combination of coins is stored in                
// the array bestCoins.                                                                                                                      
//********************************************************************************

#include <iostream>
#include <array>
using namespace std;

// Function prototypes
void makeChange(int, int *coinsUsed, int coinsLeft = 6, int numCoinsUsed = 0);

// default arguments are provided for the last 2 parameters
// Global vars
	int coins = 6;
	int numOfBestCoins = 10000;
	int numOfSolutions = 0;
	int bestCoins[100] = {};
	int coinValues[6] = { 100,50,25,10,5,1 };


int main()
{
	int coinsUsed[10000]; // array for the coins used, is accessed using pointers in makeChange
	int input; // variable for user's input
	bool validater = false; // variable used to force user to enter valid input

	do
	{
		cout << "Please enter the amount of money in cents that you would like to have converted to coins" << endl;
		cin >> input;

		if (input < 1 || input >100)
		{
			validater = false;
		}
		else
		{
			validater = true;
		}

	} while (validater = false);

	makeChange(input, coinsUsed);

	cout << "Total number of possible combinations is: " << numOfSolutions << endl;
	cout << "The most efficient combination of coins: " << endl;
	for (int i = 0; i < numOfBestCoins; i++)
	{
		cout << bestCoins[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}


void makeChange(int amount, int *coinsUsed, int coinsLeft, int numCoinsUsed)
{
	int coinIndex;

	if (coinsLeft == 0)
		return;
	else if (amount < 0)
		return;
	else if (amount == 0) 
	{
		if (numCoinsUsed < numOfBestCoins)
		{
			for (int i = 0; i < numCoinsUsed; i++)
			{
				bestCoins[i] = coinsUsed[i]; // fills the best coins array with the most efficient solution
			}
			numOfBestCoins = numCoinsUsed; // edits the size var for the array
		}
		numOfSolutions++; // adds 1 to the number of possible solutions
		return;

	}
	coinIndex = coins - coinsLeft;
	coinsUsed[numCoinsUsed] = coinValues[coinIndex];
	numCoinsUsed++;
	makeChange(amount - coinValues[coinIndex], coinsUsed, coinsLeft, numCoinsUsed);

	numCoinsUsed--;
	makeChange(amount, coinsUsed, coinsLeft - 1, numCoinsUsed);
	




}

