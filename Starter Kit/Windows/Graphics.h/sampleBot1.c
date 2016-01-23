/*	
	This bot will put the pieces from left most column (if the column is not full) to the right most column... The grid is filled vertically...
	This is a very poor bot interms of intelligence. It is bound to lose most of the times... 

	You have to paste the code which is inside this function into the function named bot1() or bot2() in game.c file to see how it works.
*/

int bot(int grid[6][7],int move) {
	int i;
	for(i=0;i<7;i++)
		if(grid[0][i]==0)	// condition to check whether the particular column is full
			return i;
	return 0;
}
