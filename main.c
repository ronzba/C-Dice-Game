#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Functions
int headLineStart();
int chooseType(int);
int diceRoll();
int randPointFunc();
int randPlayerfunc();

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
	
	// Choose Randome Points
	int lengthPoint = sizeof(pointNum) / sizeof(pointNum[0]);
	int randIndex = rand() % lengthPoint;
	int randPoint = pointNum[randIndex];
	
	return randPoint;
}

//This Func Chooses a random Player
int randPlayerFunc()
{
	int pointNum[2] = {1, 2};
	
	// Choose Randome Points
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
		int chooseType1 = chooseType(randPoint);		
		
		printf("\nDice     : ");

	// Choose Dice Number	
		int randDiceNum = diceRoll();
		printf("%d\n", randDiceNum);		
		
		printf("Points   : ");
		printf("%d\n", chooseType1);
		printf("P1       : \n");
		printf("P2       : \n\n");
		

		

		
	}
	
	
	return 0;
}
