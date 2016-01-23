//	Connect 4 ( or four in a row ) game
/*	
	This file contains the C code for the conenct 4 game... the definitions for the bot1() and bot2() function are missing which has to be filled by the programmers... All they have to do is write one function to complete the program... 
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>		//	graphics header file

//	Detailed description of these function is given at lines after 27rd line
int bot1(int[][7],int);		//	This is the function which is written by you
int bot2(int[][7],int);		//	This is the function which is written by your opponent (or vice-versa)


//	The following function are not important for the participants... They can skip these functions if they want to
void drawGrid(int[][7]);
void checkForErrors(int,int,int[][7]);
int updateGrid(int,int[][7],int);
void animateGrid(int,int[][7],int);
int checkWinOrLose(int [][7],int,int);
int checkDraw(int [][7]);
void copyGrid(int [][7],int [][7]);
int equalGrid(int [][7],int [][7]);
char bot1Name[50]="Player 1";
char bot2Name[50]="Player 2";

int bot1(int grid[6][7],int move) {
/*
	This is where you write your code...
	Inputs : 
		grid[6][7] : this stores the current state of the game based on which the function has to decide the next move
			grid[i][j]==0 means that particular place is not occupied by any piece
			grid[i][j]==1 means that particular place is occupied by player 1 (or bot 1) piece
			grid[i][j]==-1 means that particular place is occupied by player 2 (or bot 2) piece
		move : this variables content decides which player's turn it is to play
			move==1 means the bot is the player 1
			move==-1 means the bot is the player 2
	Output :
		returns the column where next move the bot will make... returns the column where the next piece has to be placed
	
	Note : 
		make sure that the returned value is within 0 and 6. The next move has to be within the grid
		make sure that the returned column is not full

*/
	int i;
	scanf("%d",&i);		//	waits for user to enter an input and press enter key
	return i;
}


int bot2(int grid[6][7],int move) {
/*
	This is where your opponent's code will be placed. You can paste any of the sampleBot codes that are given for development and testing purposes
*/
	int i;
	scanf("%d",&i);		//	waits for user to enter an input and press enter key
	return i;
}

int main(int argc,char *argv[]) {
/*	Variables important for the participants : 
		grid[6][7] : this stores the current state of the game. 
			grid[i][j]==0 means that particular place is not occupied by any piece
			grid[i][j]==1 means that particular place is occupied by player 1 (or bot 1) piece
			grid[i][j]==-1 means that particular place is occupied by player 2 (or bot 2) piece
		move : this variables content decides which player's turn it is to play
			move==1 means it is player 1 (or bot1) to play
			move==-1 means it is player 2 (or bot2) to play
*/

/*	rest of the variables used and rest of the main() function code is not important for the participants... They can skip going through it...	*/

/*	result : contains which column the player has made the move in
	win : contains which player has won the game (possible values 1, -1 or 0 for draw)
*/

	int grid[6][7],move=1,result,win=0,i,j,gridDup[6][7],moveDup,rowNum;
	char displayStr[50];

	int gd,gm=VGAMAX; gd=DETECT;
	initgraph(&gd,&gm,NULL);		//	Initialize the graph

	srand(time(NULL));			//	If any bot uses rand() function

	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			grid[i][j]=0;		//	Initialize grid to 0 implying it is empty

	outtextxy(500,150,"Bot 1 : ");
	outtextxy(500,180,bot1Name);
	outtextxy(500,300,"Bot 2 : ");
	outtextxy(500,330,bot2Name);
	drawGrid(grid);
	while(1) {
		copyGrid(grid,gridDup);		//	gridDup=grid
		moveDup=move;
		if(move>0)			//	player 1 chance to play... so call bot1()
			result=bot1(grid,move);
		else				//	player 2 chance to play... so call bot2()
			result=bot2(grid,move);
		if(!(equalGrid(grid,gridDup) && move==moveDup)) {	//	grid() and move variables should not be changed
			printf("Bot %d error : Grid or move is modified!!!",move);
			delay(3000);
			exit(1);
		}
		checkForErrors(result,move,grid);			//	errors like result should be within the 0 to 6 range, etc...
		animateGrid(move,grid,result);				//	make the piece to move
		rowNum=updateGrid(move,grid,result);			//	update the grid implying the move has been made
		drawGrid(grid);
		if(checkWinOrLose(grid,result,rowNum)) {		//	check for win condition
			win=move;					//	win will contain which bot has won
			break;
		}
		else if(checkDraw(grid)) {				//	check for draw condition
			win=0;						//	win=0 implies draw
			break;
		}
		move*=-1;						//	toggle between plaper 1 and player 2
	}

	if(win>0)				//	player 1 wins
		strcpy(displayStr,"Bot 1 wins!!!");
	else if(win<0)				//	player 2 wins
		strcpy(displayStr,"Bot 2 wins!!!");
	else					//	draw 
		strcpy(displayStr,"Game drawn!!!");

	outtextxy(100,430,displayStr);
	delay(15000);
	closegraph();

	// following code displays the game status after the game is played
	printf("\n\n\t%s\n\n\t\tgrid content : \n\n",displayStr);
	for(i=0;i<6;i++) {
		for(j=0;j<7;j++)
			printf("\t%d",grid[i][j]);
		printf("\n\n");
	}
	printf("\n\n");
	return 0;
}

/*	The rest of the program is not important for the participants... They can skip going through the rest of the code...	*/



int checkWinOrLose(int grid[][7],int result,int rowNum) {
//	For checking whether any win or lose condition is reached. Returns 1 if win or lose is reached. else returns 0
	int move=grid[rowNum][result];
	if(rowNum<=2 && grid[rowNum+1][result]==move && grid[rowNum+2][result]==move && grid[rowNum+3][result]==move)
		return 1;
	else {
		int count=1,i,j;
		for(i=result+1;i<7;i++) {
			if(grid[rowNum][i]!=move)
				break;
			count++;
		}
		for(i=result-1;i>=0;i--) {
			if(grid[rowNum][i]!=move)
				break;
			count++;
		}
		if(count>=4)
			return 1;
		count=1;
		for(i=result+1,j=rowNum+1;i<7 && j<6;i++,j++) {
			if(grid[j][i]!=move)
				break;
			count++;
		}
		for(i=result-1,j=rowNum-1;i>=0 && j>=0;i--,j--) {
			if(grid[j][i]!=move)
				break;
			count++;
		}
		if(count>=4)
			return 1;
		count=1;
		for(i=result+1,j=rowNum-1;i<7 && j>=0;i++,j--) {
			if(grid[j][i]!=move)
				break;
			count++;
		}
		for(i=result-1,j=rowNum+1;i>=0 && j<6;i--,j++) {
			if(grid[j][i]!=move)
				break;
			count++;
		}
		if(count>=4)
			return 1;
	}
	return 0;
}

int checkDraw(int grid[][7]) {
//	Checking for draw condition. Returns 1 if draw is reached. else returns 0
	int i;
	for(i=0;i<7;i++)
		if(grid[0][i]==0)
			return 0;
	return 1;
}

void copyGrid(int grid[6][7],int gridDup[6][7]) {
//	does dridDup=grid
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			gridDup[i][j]=grid[i][j];
}

int equalGrid(int grid[][7],int gridDup[][7]) {
//	return 1 if grid==gridDup... else returns 0
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			if(gridDup[i][j]!=grid[i][j])
				return 0;
	return 1;
}

void animateGrid(int move,int grid[6][7],int result) {
//	Function to make the pieces fall from the top
	int startX=100,startY=100,len=50,i,j,r=len/2,p=startX+r+len*result,n;
	for(i=0;i<6;i++)
		if(grid[i][result]!=0)
			break;
	i--;
	n=startY+r+len*i;
	r-=10;
	if(move>0) {	//	player 1
		for(j=startY-len;j<n;j+=4) {
//			drawGrid(grid);
			setcolor(RED);
			circle(p,j,r);
			floodfill(p,j,RED);
			setcolor(BLACK);
			circle(p,j,r);
			floodfill(p,j,BLACK);
		}
	}
	else if(move<0) {	//	player 2
		for(j=startY-len;j<n;j+=4) {
//			drawGrid(grid);
			setcolor(BLUE);
			circle(p,j,r);
			floodfill(p,j,BLUE);
			setcolor(BLACK);
			circle(p,j,r);
			floodfill(p,j,BLACK);
		}
	}
}

int updateGrid(int move,int grid[6][7],int result) {
//	Updates the grid with the next move
	int i;
	for(i=0;i<6;i++)
		if(grid[i][result]!=0)
			break;
	grid[i-1][result]=move;
	return i-1;
}

void checkForErrors(int result,int move,int grid[6][7]) {
//	error checks
	int err=0;
	char displayStr[50];
	if(move>0) {
		if(result<0 || result>6)	//	result should be within 0 to 6 range
			err=1;
		if(grid[0][result]!=0)		//	the result column should not be full
			err=2;
	}
	else {
		if(result<0 || result>6)
			err=-1;
		if(grid[0][result]!=0)
			err=-2;
	}
	if(err) {
//		closegraph();
		switch(err) {
			case 1 : strcpy(displayStr,"Bot 1 error : Result is out of bounds!!!"); break;
			case 2 : strcpy(displayStr,"Bot 1 error : Column is full!!!"); break;
			case -1 : strcpy(displayStr,"Bot 2 error : Result is out of bounds"); break;
			case -2 : strcpy(displayStr,"Bot 2 error : Column is full!!!"); break;
		}
		outtextxy(100,430,displayStr);
		delay(15000);
		printf("\n\n\t%s\n\n",displayStr);
		exit(1);
	}
}

void drawGrid(int grid[6][7]) {
//	Function to draw the grid and the pieces
//	Player 1 is red piece and player 2 is blue piece

	int startX=100,startY=100,len=50,i,j,r=len/2;

	outtextxy(200,50,"CONNECT 4");
//	cleardevice();
	setcolor(WHITE);
	for(i=0;i<7;i++)
		line(startX,startY+len*i,startX+len*7,startY+len*i);
	for(i=0;i<8;i++)
		line(startX+len*i,startY,startX+len*i,startY+len*6);
	for(i=0;i<6;i++)
		for(j=0;j<7;j++) {
			if(grid[i][j]>0) {	//	player 1
				setcolor(RED);
				circle(startY+r+len*j,startX+r+len*i,r-10);
				floodfill(startY+r+len*j,startX+r+len*i,RED);
			}
			else if(grid[i][j]<0) {	//	player 2
				setcolor(BLUE);
				circle(startY+r+len*j,startX+r+len*i,r-10);
				floodfill(startY+r+len*j,startX+r+len*i,BLUE);
			}
		}
}

