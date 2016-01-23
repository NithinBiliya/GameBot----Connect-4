/*
	This is a random bot... It randomly decides in which column to put the next piece...
	You get intersting game play when you pitch together 2 random bots against each other...
	Very poor intelligence and loses almost always...
	
	You have to paste the code which is inside this function into the function named bot1() or bot2() in game.c file to see how it works.
*/

int bot(int grid[6][7],int move) {
	int r;
	do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
