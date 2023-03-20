#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"





// Main Function 
int main(int argc, char *argv[]) 
{	
	// Seed the random number generator
	srand(time(NULL));

	// Define Variables
	int numOfRounds = headLineStart(); 
	int i;
	int ranTypeNum = 0;
	int player1, player2;

	
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
		int pointsToPlayers = getRoundType(randPoint);		
		
		printf("\nDice     : ");

	// Choose Dice Number	
		int randDiceNum = diceRoll();
		printf("%d\n", randDiceNum);		
	
	// Display Points	
		printf("Points   : ");
		printf("%d\n", pointsToPlayers);
		
	// Display Score
		player1 = printPlayerPoints(randPlayer, randDiceNum, pointsToPlayers);
		player2 = printPlayerPoints2(randPlayer, randDiceNum, pointsToPlayers);
		
	}

// This prints the winner of the Game 
	printTheWinner(player1, player2);
	
	return 0;
}
