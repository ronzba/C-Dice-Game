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
int getRoundType(ranTypeNum)
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

// This Func Displays the points as well as returning the points
int printPlayerPoints(randPlayer, randDiceNum, pointsToPlayers)
{
	static int player1;
	static int player2;
	
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

		printf("P1       : %d\n", player1);
		printf("P2       : %d\n\n", player2);
		
		return player1;
		
		
}


// This funtions does the same as the one above but return the value of the second player
int printPlayerPoints2(randPlayer, randDiceNum, pointsToPlayers)
{
	static int player1;
	static int player2;
	
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

		return player2;
		
}

void printTheWinner(player1, player2)
{

	printf("    GAME OVER\n");
	printf("##################\n");
	if (player1 > player2)
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

#include "paintRoom.h"

typedef struct Coordinates
{    
    int xCoo;           
    int yCoo;           
} Coordinates;

void recPaintRoom( RoomData room, int row, int col, int distanceFromA, char letter);
Coordinates findA(RoomData room);
/* declare any other helper functions here*/

/* printName
 * input: none
 * output: none
 *
 * Prints name the student who worked on this solution
 */
void printName( )
{
    /* TODO : Fill in your name*/
    printf("\nThis solution was completed by:\n");
    printf("Rodrigo Nunez\n");
}

/* TODO
 * paintRoom
 * input: the room to process
 * output: N/A
 *
 * This non-recursive function is called by the driver and it makes the initial call to recursive function recPaintRoom.
 */
void paintRoom( RoomData room ){

	int row, col;
	int distanceFromA = 0;
	char letter = 65;
	Coordinates coordinates;
	
    /* Call any other helper functions (a helper function to find the location of 'A' in room may be handy) */
	coordinates = findA(room);
	
	row = coordinates.yCoo;
 	col = coordinates.xCoo; 
 	
    /* Call your recursive function here */
    recPaintRoom( room, row, col, distanceFromA, letter);
}

/* TODO
 * recPaintRoom
 * input: the room to process, the row and column of the current location being explored, the distance traveled from 'A'
 * output: N/A
 */
void recPaintRoom( RoomData room, int row, int col, int distanceFromA, char letter)
{
    /* Base cases: */
    if((room.roomArray[row][col] == '*')) {
		return;
	}
    /* Recursive cases: */
    if (distanceFromA < 25) {
	    room.roomArray[row][col] = (distanceFromA + letter);
	} else {
	    room.roomArray[row][col] = 'Z';
	}
    
    /*Move to the left*/
    if(room.roomArray[row][col - 1] == ' ' || room.roomArray[row][col] < room.roomArray[row][col - 1])
	{
		recPaintRoom(room,row,(col - 1),(distanceFromA + 1), letter);
	}
	
    /*Move to the right*/	
    if(room.roomArray[row][col + 1] == ' ' || room.roomArray[row][col] < room.roomArray[row][col + 1])
	{
		recPaintRoom(room,row,(col + 1),(distanceFromA + 1), letter);
	}
	
    /*Move down*/	
    if(room.roomArray[row - 1][col] == ' ' || room.roomArray[row][col] < room.roomArray[row - 1][col])
	{
		recPaintRoom(room,(row - 1),col,(distanceFromA + 1), letter);
	}
	
    /*Move up*/	
    if(room.roomArray[row + 1][col] == ' ' || room.roomArray[row][col] < room.roomArray[row + 1][col])
	{
		recPaintRoom(room,(row + 1),col,(distanceFromA + 1), letter);
	}
    return;
}

Coordinates findA(RoomData room){
	
	 int i, j;
	 Coordinates coordinates;

    for( i=0; i<room.numrows; i++ )
	{
        for( j=0; j<room.numcols; j++ )
		{
        	if ( room.roomArray[i][j] == 'A')
			{
        		coordinates.yCoo = i;
        		coordinates.xCoo = j;
        		return coordinates;
			}
		}
    }
    printf("Did not find 'A'\n");
    return coordinates;
}



