/*
 * A simple rock, paper, scissors function.
 *
 * Rock beats scissors; scissors beats paper; paper beats rock; two identical 
 * moves are a draw.
 *
 * You will be given two valid Rock, Paper, Scissors moves and have to return 
 * which player won. "Player 1 won!" for Player 1, and "Player 2 won!" for 
 * player 2. In case of a draw, return "Draw!"
 *
 */

/* This was my first time using Enums. Enums are a special type that 
 * represents a group of constants.
 *
 * The general structure of an enum looks like this:
 *
 * enum Level {
 * 	ITEM1,
 * 	ITEM2,
 * 	ITEM3
 * };
 *
*/

enum tool {ROCK, PAPER, SCISSORS};
enum outcome {P1_WON, P2_WON, DRAW};

/*
 * To access an enum, you must create a variable out of it.
 *
 * Here I am specifying the enum keyword, followed by the name of the "outcome"
 * enum, and then the name of a new enum variable, "rps".
 *
 * Now that I have a new enum variable, I can assign values to it.
*/
enum outcome rps (enum tool p1, enum tool p2)
{
	return (enum outcome [3][3]) {
		[ROCK] = {[ROCK] = DRAW, [PAPER] = P2_WON, [SCISSORS] = P1_WON},
		[PAPER] = {[ROCK] = P1_WON, [PAPER] = DRAW, [SCISSORS] = P2_WON},
		[SCISSORS] = {[ROCK] = P2_WON, [PAPER] = P1_WON, [SCISSORS] = DRAW},
	}[p1][p2];
}


