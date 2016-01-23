//	No errors. Works as both bot1() and bot2()
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char botName[50]="Abhishek_Sandesh";
void moveAV(int mygrid[6][7],int x,int player,int *lastX,int *lastY)
{

	int height=6,y;
	for (y=0;y<height;++y)
	        if (mygrid[y][x] == 0)
	        {
	            mygrid[y][x] = player;
	            *lastX = x;
	            *lastY = y;
	            return;
	        }
}

void undoAV(int mygrid[6][7],int x, int player)
{

	int height=6;
    int y = height-1;
    while (y >= 0 && mygrid[y][x] == 0) --y;
    if (mygrid[y][x] == player)
        mygrid[y][x] = 0;
}

int getScoreAV(int mygrid[6][7])
{
	int width=7,height=6,score = 0,x,y,columnscore,rowscore;
    for (x=0;x<width;++x)
    {
        columnscore = (width/2) - x;
        if (columnscore < 0)
          columnscore = -columnscore;

        columnscore = (width/2) - columnscore;
        for (y=0;y<height;++y)
        {
            rowscore = (height/2) - y;
            if (rowscore < 0)
            	rowscore = -rowscore;

            rowscore = (height/2) - rowscore;

            if (mygrid[y][x]==1)
                score += columnscore+rowscore;
            else if (mygrid[y][x] ==-1)
                score -= columnscore+rowscore;
        }
    }

    return score;
}

char checkWinAV(int mygrid[6][7],int *lastX,int *lastY)
{
	int width=7,height=6,x1,y1,x2,y2;
    int player = mygrid[*lastY][*lastX];

    x1=x2=*lastX;
    while (x1<width && mygrid[*lastY][x1]==player) ++x1;
    while (x2>=0 && mygrid[*lastY][x2]==player) --x2;
    if (x1-x2 > 4)
        return player;

    y1=y2=*lastY;
    while (y1<height && mygrid[y1][*lastX]==player) ++y1;
    while (y2>=0 && mygrid[y2][*lastX]==player) --y2;
    if (y1-y2 > 4)
        return player;

    x1=x2=*lastX;
    y1=y2=*lastY;
    while (y1>=0 && x1<width && mygrid[y1][x1]==player) { ++x1; --y1; }
    while (y2<height && x2>=0 && mygrid[y2][x2]==player) {--x2; ++y2; }
    if (x1-x2 > 4)
        return player;

    x1=x2=*lastX;
    y1=y2=*lastY;
    while (y1>=0 && x1>=0 && mygrid[y1][x1]==player) { --x1; --y1; }
    while (y2<height && x2<width && mygrid[y2][x2]==player) {++x2; ++y2; }
    if (x2-x1 > 4)
        return player;

    return 2;
}


int alphabetaAV(int mygrid[6][7],int myMove,int *lastX,int *lastY,int alpha, int beta, int depth)
{
	int width=7,height=6,maxDepth = 5,maxScore=100,m;

    int winner =checkWinAV(mygrid,lastX,lastY);
    if (winner == 1)
        return maxScore;
    else if (winner == -1)
        return -maxScore;

    if (depth>= maxDepth)
    {

            return getScoreAV(mygrid);

    }

    if (myMove == 1)
    {

        for (m=0;m<width;++m)
            if (mygrid[height-1][m]==0)
            {
            	moveAV(mygrid,m,1,lastX,lastY);
                int score = alphabetaAV(mygrid,-1,lastX,lastY,alpha,beta,depth+1);
                undoAV(mygrid,m,1);
                if (score > alpha) alpha = score;
                if (alpha >= beta) return alpha;
            }
        return alpha;
    }

    else if (myMove == -1)
    {

        for (m=0;m<width;++m)
            if (mygrid[height-1][m]==0)
            {
            	moveAV(mygrid,m,-1,lastX,lastY);
                int score = alphabetaAV(mygrid,1,lastX,lastY,alpha, beta, depth+1);
                undoAV(mygrid,m,-1);
                if (score < beta) beta = score;
                if (alpha >= beta) return beta;
            }
        return beta;
    }
    else
        return 0;
}



int nxtMoveAV(int mygrid[6][7],int myMove,int *lastX,int *lastY)
{
	int moveScore[7],width=7,height=6,invalidScore=1000000,m;

	for(m=0;m<width;m++)
		moveScore[m]=0;
    if (myMove == 1)
    {
        int maxScore = -invalidScore;
        int maxMove  = 0;
        for (m=0;m<width;++m)
            if (mygrid[height-1][m]==0)
            {
            	moveAV(mygrid,m,1,lastX,lastY);
                int score = alphabetaAV(mygrid,-1,lastX,lastY,-1000000,1000000,0);

                moveScore[m] = score;

                if (score>=maxScore)
                {
                    maxScore = score;
                    maxMove  = m;
                }
                undoAV(mygrid,m,1);
            }
            else
                moveScore[m] = invalidScore;

        return maxMove;
    }

    else if (myMove == -1)
    {
        int minScore = invalidScore;
        int minMove  = 0;
        for (m=0;m<width;++m)
        {
            if (mygrid[height-1][m]==0)
            {
            	moveAV(mygrid,m,-1,lastX,lastY);
                int score = alphabetaAV(mygrid,1,lastX,lastY,-1000000,1000000,0);

                moveScore[m] = score;

                if (score<minScore)
                {
                    minScore = score;
                    minMove  = m;
                }
                undoAV(mygrid,m,-1);
            }
            else
                moveScore[m] = invalidScore;
        }
        return minMove;
    }
    else
        return 0;
}

int bot(int grid[6][7],int move) {   /*or int bot2(int grid[6][7],int move){} */
   int i,j,k;
   int mygrid[6][7];
   int lastX=0,lastY=0;
   int l=0;
	for(j=5;j>=0;j--,l++)
		for(k=0;k<7;k++)
			mygrid[l][k]=grid[j][k];
	i=nxtMoveAV(mygrid,move,&lastX,&lastY);
	if(grid[0][i]==0 && i<7)
	  return i;
	else
	{
		for(j=0;j<7;j++)
			if(grid[0][j]==0)
				return j;
	}
   return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

