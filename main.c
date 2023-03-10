#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Functions
int headLineStart();
int chooseType(int);
int diceRoll();
int randPointFunc();
int randPlayerfunc();
void printRoundPoints();

// This Function Starts the Game by Welcoming and Storing the Number of Rounds
int headLineStart()
{
	printf("\n########### LET'S PLAY ###########\n\n");
	
	int numOfRounds;
	
	printf("Enter the number of rounds: ");
	scanf("%d", &numOfRounds);
	
	printf("\nPlayer 1          : 0\n");
	printf("Player 2          : 0\n\n");
	
	return numOfRounds;
}

// This Func Chooses TYPE (Bonus, Double, Regular)
int chooseType(ranTypeNum)
{
	int randomType = rand() % 10 + 1;
	
	if (randomType <= 5)
	{
		printf("REGULAR ");
	}
	else if (randomType <= 8)
	{
		printf("DOUBLE ");
		ranTypeNum = ranTypeNum * 2;  
	}
	else
	{
		printf("BONUS ");
		ranTypeNum = 200;
	}
	
	return ranTypeNum;
}

// This Func Rolles the Dice and Chooses a random number
int diceRoll()
{
	int diceNum[6] = {1,2,3,4,5,6};
	
	int lengthDice = sizeof(diceNum) / sizeof(diceNum[0]);
	int randIndex = rand() % lengthDice;
	int randDice = diceNum[randIndex];
	
	return randDice;
	
}

//This Func Chooses a random Point
int randPointFunc()
{
	int pointNum[10] = {10,20,30,40,50,60,70,80,90,100};
	
	int lengthPoint = sizeof(pointNum) / sizeof(pointNum[0]);
	int randIndex = rand() % lengthPoint;
	int randPoint = pointNum[randIndex];
	
	return randPoint;
}

//This Func Chooses a random Player
int randPlayerFunc()
{
	int pointNum[2] = {1, 2};
	
	int lengthPoint = sizeof(pointNum) / sizeof(pointNum[0]);
	int randIndex = rand() % lengthPoint;
	int randPlayer = pointNum[randIndex];
	
	return randPlayer;
}

// Main Function 
int main(int argc, char *argv[]) 
{	
	// Seed the random number generator
	srand(time(NULL));

	// Define Variables
	int numOfRounds = headLineStart(); 
	int i;
	int ranTypeNum = 0;
	int player1;
	int player2;
	
	for (i = 1; i < numOfRounds + 1; i++)
	{
			
		printf("ROUND %d\n", i);
		printf("-------\n\n");
		
	// Display Player
		printf("Player   : ");
		int randPlayer = randPlayerFunc();
		printf("%d\n", randPlayer);
		printf("Type     : ");
		
	// Choose TYPE (Bonus, Double, Regular)	
		int randPoint = randPointFunc();
		int pointsToPlayers = chooseType(randPoint);		
		
		printf("\nDice     : ");

	// Choose Dice Number	
		int randDiceNum = diceRoll();
		printf("%d\n", randDiceNum);		
	
	// Display Points	
		printf("Points   : ");
		printf("%d\n", pointsToPlayers);
		
	// Display Score

		if (randPlayer % 2 == 0 && randDiceNum % 2 == 0)
		{
			player2 = player2 + pointsToPlayers;
		}
		else if (randPlayer %2 != 0 && randDiceNum %2 !=0)
		{
			player1 = player1 + pointsToPlayers;
		}
		else if (randPlayer %2 != 0 && randDiceNum % 2 == 0)
		{
			player1 = player1 - pointsToPlayers;	
		}
		else 
		{
			player2 = player2 - pointsToPlayers;
		}

		printf("P1       : %d\n", player1 - 1);
		printf("P2       : %d\n\n", player2);
		
	}

	printf("    GAME OVER\n");
	printf("##################\n");
	if (player1 -1 > player2)
	{
		printf(" Player 1 Wins!!!\n");
	}
	else
	{
		printf(" Player 2 Wins!!!\n");
	}
	printf("##################\n");
	return 0;
}
