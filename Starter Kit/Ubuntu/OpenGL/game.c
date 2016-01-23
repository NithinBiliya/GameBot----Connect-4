//	Connect 4 ( or four in a row ) game
/*	
	This file contains the OpenGL code for the conenct 4 game... the definitions for the bot1() and bot2() function are missing which has to be filled by the programmers... All they have to do is write one function to complete the program... 
*/

#include <GL/glut.h>		//	openGL header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define font2 GLUT_BITMAP_TIMES_ROMAN_24	//	Not important
#define font3 GLUT_BITMAP_HELVETICA_18		//	Not important

//	Detailed description of these function is given at lines after 50th line
int bot1(int[][7],int);		//	This is the function which is written by you
int bot2(int[][7],int);		//	This is the function which is written by your opponent (or vice-versa)

//	The following function are not important for the participants... They can skip these functions if they want to
void drawGrid(int[][7]);
void checkForErrors(int,int,int[][7]);
int updateGrid(int,int[][7],int);
int checkWinOrLose(int [][7],int,int);
int checkDraw(int [][7]);
void copyGrid(int [][7],int [][7]);
int equalGrid(int [][7],int [][7]);
void text(char [],GLfloat,GLfloat,void*);
void drawPiece(int,float,int);
int stopAnimate(int[][7],int,float);
void displayStatus(int[][7]);
void reshape(int,int);
void display();

int grid[6][7],move=1;
/*	Variables important for the participants : 
		grid[6][7] : this stores the current state of the game. 
			grid[i][j]==0 means that particular place is not occupied by any piece
			grid[i][j]==1 means that particular place is occupied by player 1 (or bot 1) piece
			grid[i][j]==-1 means that particular place is occupied by player 2 (or bot 2) piece
		move : this variables content decides which player's turn it is to play
			move==1 means it is player 1 (or bot1) to play
			move==-1 means it is player 2 (or bot2) to play
*/

/*	rest of the variables used is not important for the participants... They can skip going through it...	*/
int result,endGameFlag=0,win,errorFlag=0,animate=0;
float size=0.35,displacement;
char displayStr[50];
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

}


int bot2(int grid[6][7],int move) {
/*
	This is where your opponent's code will be placed. You can paste any of the sampleBot codes that are given for development and testing purposes
*/

}



/*	Rest of the program is not important for the participants... They can skip going through it...	*/

int main(int argc,char *argv[]) {
/*
	This function is not important to the participant... He can skip it
*/
	int i,j;
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("GameBot");
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
	srand(time(NULL));			//	If any bot uses rand() function
	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			grid[i][j]=0;
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

void display() {
/*
	This function is used to display the content on to the screen... 
	This is not important for the participant... He can skip it
*/
	int gridDup[6][7],moveDup=move,endGameFlagDup,rowNum;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	drawGrid(grid);
	if(animate) {
		drawPiece(result,displacement,move);
		if(stopAnimate(grid,result,displacement)) {
			animate=0;
			if(!errorFlag) {
				rowNum=updateGrid(move,grid,result);			//	update the grid implying the move has been made
				drawGrid(grid);
				if(checkWinOrLose(grid,result,rowNum)) {		//	check for win condition
					win=move;					//	win will contain which bot has won
					endGameFlag=1;
				}
				else if(checkDraw(grid)) {				//	check for draw condition
					win=0;						//	win=0 implies draw
					endGameFlag=1;
				}
				move*=-1;						//	toggle between plaper 1 and player 2
			}
		}
	}
	if(errorFlag)									//	If error occurs
		text(displayStr,-1.5,-1.8,font3);
	if(endGameFlag) {								//	If game ends
		if(win>0)				//	player 1 wins
			strcpy(displayStr,"Bot 1 wins!!!");
		else if(win<0)				//	player 2 wins
			strcpy(displayStr,"Bot 2 wins!!!");
		else					//	draw 
			strcpy(displayStr,"Game drawn!!!");
		text(displayStr,-1.5,-1.8,font3);
		printf("\n\n\t%s\n\n\t\tgrid content : \n\n",displayStr);
		displayStatus(grid);
	}
	glutSwapBuffers();
	if(animate)
		displacement+=0.005;
	if(!endGameFlag && !errorFlag && !animate) {
		copyGrid(grid,gridDup);
		moveDup=move;
		endGameFlagDup=endGameFlag;
		if(move>0)
			result=bot1(grid,move);
		else
			result=bot2(grid,move);
		if(!(equalGrid(grid,gridDup) && move==moveDup && endGameFlagDup==endGameFlag)) {	//	grid() and move variables should not be changed
			sprintf(displayStr,"Bot %d error : Grid or move is modified!!!",move);
			errorFlag=1;
		}
		checkForErrors(result,move,grid);			//	errors like result should be within the 0 to 6 range, etc...
		animate=1;
		displacement=0;
	}
}

void reshape(int w,int h) {
/*
	OpenGL function to make adjustments if the screen size if changed
	This is not important for the participant... He can skip it
*/
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(h>=w)
		glOrtho(-2,2,-2*(GLfloat)h/(GLfloat)w,2*(GLfloat)h/(GLfloat)w,-10,10);
	else
		glOrtho(-2*(GLfloat)w/(GLfloat)h,2*(GLfloat)w/(GLfloat)h,-2,2,-10,10);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void displayStatus(int grid[6][7]) {
/*
	For displaying game status at the end of the game...
	This is not important for the participant... He can skip it
*/
	int i,j;
	for(i=0;i<6;i++) {
		for(j=0;j<7;j++)
			printf("\t%d",grid[i][j]);
		printf("\n\n");
	}
	printf("\n\n");
}

int stopAnimate(int grid[6][7],int result,float displacement) {
/*
	Checks condition when to stop moving the piece
	This is not important for the participant... He can skip it
*/
	int i;
	for(i=0;i<6;i++)
		if(grid[i][result]!=0)
			break;
	if(displacement>size*i)
		return 1;
	return 0;
}

void drawPiece(int result,float displacement,int move) {
/*
	Draws the animated piece
	This is not important for the participant... He can skip it
*/
	glPushMatrix();
	glTranslatef(-1.5,1,0);
	glTranslatef(size*result,size-displacement,0);
	if(move==1) {
		glColor3f(1,0,0);
		glutSolidSphere(size/2-0.03,25,25);
	}
	else if(move==-1) {
		glColor3f(0,0,1);
		glutSolidSphere(size/2-0.03,25,25);
	}	
	glPopMatrix();
}

void drawGrid(int grid[6][7]) {
/*
	Function to draw the grid and all the pieces in it 
	This is not important for the participant... He can skip it
*/
	int i,j;
	text("CONNECT 4",-1,1.5,font3);
	text("Bot 1 : ",-1.5,-1.2,font3);
	text(bot1Name,-0.8,-1.2,font3);
	text("Bot 2 : ",-1.5,-1.4,font3);
	text(bot2Name,-0.8,-1.4,font3);
	glPushMatrix();
	glTranslatef(-1.5,1,0);
	for(i=0;i<6;i++) {
		glPushMatrix();
		for(j=0;j<7;j++) {
			glColor3f(1,1,1);
			glutWireCube(size);
			if(grid[i][j]==1) {
				glColor3f(1,0,0);
				glutSolidSphere(size/2-0.03,25,25);
			}
			else if(grid[i][j]==-1) {
				glColor3f(0,0,1);
				glutSolidSphere(size/2-0.03,25,25);
			}
			glTranslatef(size,0,0);
		}
		glPopMatrix();
		glTranslatef(0,-size,0);
	}
	glPopMatrix();
}

int checkWinOrLose(int grid[][7],int result,int rowNum) {
/*
	For checking whether any win or lose condition is reached. Returns 1 if win or lose is reached. else returns 0
	This is not important for the participant... He can skip it
*/
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
//	This is not important for the participant... He can skip it
	int i;
	for(i=0;i<7;i++)
		if(grid[0][i]==0)
			return 0;
	return 1;
}

void copyGrid(int grid[6][7],int gridDup[6][7]) {
//	does dridDup=grid
//	This is not important for the participant... He can skip it
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			gridDup[i][j]=grid[i][j];
}

int equalGrid(int grid[][7],int gridDup[][7]) {
//	return 1 if grid==gridDup... else returns 0
//	This is not important for the participant... He can skip it
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			if(gridDup[i][j]!=grid[i][j])
				return 0;
	return 1;
}

int updateGrid(int move,int grid[6][7],int result) {
//	Updates the grid with the next move
//	This is not important for the participant... He can skip it
	int i;
	for(i=0;i<6;i++)
		if(grid[i][result]!=0)
			break;
	grid[i-1][result]=move;
	return i-1;
}

void checkForErrors(int result,int move,int grid[6][7]) {
//	error checks
//	This is not important for the participant... He can skip it
	int err=0;
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
		switch(err) {
			case 1 : strcpy(displayStr,"Bot 1 error : Result is out of bounds!!!"); break;
			case 2 : strcpy(displayStr,"Bot 1 error : Column is full!!!"); break;
			case -1 : strcpy(displayStr,"Bot 2 error : Result is out of bounds"); break;
			case -2 : strcpy(displayStr,"Bot 2 error : Column is full!!!"); break;
		}
		printf("\n\n\t%s\n\n",displayStr);
		errorFlag=1;
	}
}

void text(char tex[],GLfloat xtext,GLfloat ytext,void *font) {
//	For displlaying string on the screen
//	This is not important for the participant... He can skip it
	char *p;
	glColor3f(1,1,1);
	p = tex;
	glRasterPos2f(xtext, ytext);
	while(*p) glutBitmapCharacter(font, *p++);
}

