// Functions
int headLineStart();
int getRoundType(int);
int diceRoll();
int randPointFunc();
int randPlayerfunc();
void printRoundPoints();
int printPlayerPoints(int, int, int);
int printPlayerPoints2(int, int, int);
void printTheWinner(int, int);


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "stack.h"
#include "booleanEvaluation.h"
#include "booleanWithError.h"


/* TODO
 * printName
 * input: none
 * output: none
 *
 * Prints name of the student who worked on this solution
 */
void printName( )
{
    /* TODO : Fill in your name */
    printf("This solution was completed by:\n");
    printf("Rodrigo Nunez\n");
}

/* TODO
 * evaluatePostfix
 * input: a postfix expression (calls tokenizeString to get the tokens from the string)
 * output: T, F, or E
 *
 * Uses a stack to evaluates the postfix expression and returns the result as a string where "T" denotes true and "F" denotes false.
 * If the postfix expression is invalid it returns "E" to denote an error has occurred.  Be sure to use the helpful functions in booleanEvaluation.
 *
 * Hints:
 * - DO NOT free the parameter str.  It is freed by the calling function.
 * - Be sure to use the helpful functions in booleanEvaluation.
 * - Test your code often!  Get it working correctly for the first couple test cases instead of trying to solve all of them at once.
 */
char *evaluatePostfix( char *str )
{
    /* Your variable Declarations: */
    int tokenCount, i;
    char** arrTokens = tokenizeString( str, &tokenCount ); /* Currently commented out to prevent a memory leak.  Uncomment to get the tokens from str. */
    char *op1, *op2, *result;

    // Create Stack s
    Stack *s = createStack();
    // For each token, x, in the postfix expression:
    for (i = 0; i < tokenCount; i++){
        // if x is True or False push it to the stack
        if (strequals(arrTokens[i], 'T') || strequals(arrTokens[i], 'F')){
                push(s, arrTokens[i]);
        }
        // Else if x is a unary operator
        else if(strequals(arrTokens[i], 'NOT')){

            // if you do not have at least one operand in s, return an error in boolean (and free ur data)
            if(op1 == NULL){
                op1 = booleanToString(ERROR);
                return op1; // Boolean Error
                freeStackElements(s);
                freeStack(s); // DO I NEED THIS?
            }else{
                continue;
            }
             // pop an operand op1 from s (ON PDF THIS STEP GOES AFTER the next but op1 is undefined)
            op1 = pop(s);

            // Compute x op1 (see table)
            *result = !op1;
            // Push the result into s
            push(s,result);
            // free op1 and x
            free(op1);
            free(arrTokens[i]);

        // if x is a binary operator
        }else if (!strequals(arrTokens[i], 'NOT')){
            // If you do not have at least two operands in s, you should return an error in the boolean (remember to free your data).
            if (op1 == NULL && op2 == NULL){
                op1 = booleanToString(ERROR);
                return op1; // Boolean Error
                freeStackElements(s);
                freeStack(s); // DO I NEED THIS?
            }else{
                continue;
            }

            // pop and operand op2 from s
            op2 = pop(s);
            // pop and operand op1 from s
            op1 = pop(s);
            // Compute op1, op2 x(see binary table)       NEED TO FINISH THIS
            int var = 0;
            switch (var){
                case 1
            }
            // push the result to s

            //free op1 op2 and x
        }
    }





    return booleanToString( ERROR ); /* Replace this with your actual solution to return */
}

/* TODO
 * postfixToInfix
 * input: a postfix expression (calls tokenizeString to get the tokens from the string)
 * output: the equivalent infix expression
 *
 * Uses a stack to convert str to its equivalent expression in infix.
 * You can assume that the postfix expression is valid
 *
 * Hints:
 * - DO NOT free the parameter str.  It is freed by the calling function.
 * - Be sure to use the helpful functions in booleanEvaluation.
 * - Test your code often!  Get it working correctly for the first couple test cases instead of trying to solve all of them at once.
 */
char *postfixToInfix( char *str )
{
    /* Your variable Declarations: */
    int tokenCount;
    char** arrTokens;/* = tokenizeString( str, &tokenCount ); */  /* Currently commented out to prevent a memory leak.  Uncomment to get the tokens from str. */




    /* Your code: */




    return booleanToString( ERROR ); /* Replace this with your actual solution to return */
}


/* You may want to create some helper functions down here! */

void superFree(){

}