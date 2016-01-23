//	Works for both bot1 and bot2... but has column full error... 

int pot_moves[7];                                                   //1
int results[7];                                                     //2
int isValidMove(int grid[6][7],int column);                         //3
int isBoardFull(int grid[6][7]);                                    //4
void makeMove(int dupe[6][7],int move,int i);                       //5
int getLowestEmptySpace(int grid[6][7],int column);                 //6
int isWinner(int dupe[6][7],int move);                              //7
void compute_pot_moves(int grid[6][7],int move,int lookahead);      //8
void compute_results(int grid[6][7],int move,int lookahead);        //9

char botName[50]="Ajith_Ashwin";
int bot(int grid[6][7],int move)
{
        int b_m_fittness=-1;
        int bestmoves[7];
        int j=0;
        int r;
	int i;

        compute_pot_moves(grid,move,2);

        for(i=0;i<7;i++)
            if(pot_moves[i]>b_m_fittness&&isValidMove(grid,i))
                b_m_fittness=pot_moves[i];

        for(i=0;i<7;i++)
            if(pot_moves[i]==b_m_fittness&&isValidMove(grid,i))
                bestmoves[j++]=i;

        r=rand()%j;

        return bestmoves[r];
}





void compute_results(int grid[6][7],int move,int lookahead)
{
    int results[7]={0};                //global
    int dupe[6][7],dupe1[6][7];
    int enemy;
	int i,j,k,l;

    if(move==1)
        enemy=-1;
    else
        enemy=1;

    if(lookahead==0||!(isBoardFull(grid)))
    {
        for(i=0;i<7;i++)        //i=1st move
        {

            for(l=0;l<6;l++)
                for(k=0;k<7;k++)
                    dupe[l][k]=grid[l][k];

            if(!(isValidMove(dupe,i)))
                continue;

            makeMove(dupe,move,i);

            if(isWinner(dupe,move))
            {
                results[i]=1;
                break;
            }

            else
            {
                if(isBoardFull(dupe))
                    results[i]=0;

                else
                {
                    for(j=0;j<7;j++)    //j=counter move by enemy
                    {
                        for(l=0;l<6;l++)
                            for(k=0;k<7;k++)
                                dupe1[l][k]=dupe[l][k];

                        if(!(isValidMove(dupe1,j)))
                            continue;

                         makeMove(dupe1,enemy,j);

                        if(isWinner(dupe1,enemy))
                        {
                            results[i]=-1;
                            break;
                        }
                        else
                        {
                            results[i]=0;
                        }

                    }
                }
            }
        }
    }

}









void compute_pot_moves(int grid[6][7],int move,int lookahead)
{
    int pot_moves[7]={0};                //global
    int res=0;
    int dupe[6][7],dupe1[6][7];
    int enemy;
	int i,j,k,l;

    if(move==1)
        enemy=-1;
    else
        enemy=1;

    if(lookahead==0||!(isBoardFull(grid)))
    {
        for(i=0;i<7;i++)        //i=1st move
        {

            for(l=0;l<6;l++)
                for(k=0;k<7;k++)
                    dupe[l][k]=grid[l][k];

            if(!(isValidMove(dupe,i)))
                continue;

            makeMove(dupe,move,i);
            if(isWinner(dupe,move))
            {
                pot_moves[i]=1;
                break;
            }

            else
            {
                if(isBoardFull(dupe))
                    pot_moves[i]=0;

                else
                {
                    for(j=0;j<7;j++)    //j=counter move by enemy
                    {
                        for(l=0;l<6;l++)
                            for(k=0;k<7;k++)
                                dupe1[l][k]=dupe[l][k];

                        if(!(isValidMove(dupe1,j)))
                            continue;

                         makeMove(dupe1,enemy,j);

                        if(isWinner(dupe1,enemy))
                        {
                            pot_moves[i]=-1;
                            break;
                        }
                        else
                        {
                            compute_results(dupe1,move,1);
                            for(l=0;l<7;l++)
                                res+=results[l];
                            pot_moves[i]+=(res/7)/7;
                        }

                    }
                }
            }
        }
    }

}


int isValidMove(int grid[6][7],int column)
{
    if(column<0||column>=7||grid[0][column]!='\0')
        return -1;

    return 1;
}


int isBoardFull(int grid[6][7])
{
	int i,j;
    for(i=0;i<6;i++)
        for(j=0;j<7;j++)
            if(grid[i][j]==0)
                return -1;

    return 1;
}


void makeMove(int grid[6][7],int move,int column)
{
    int lowest;
    lowest=getLowestEmptySpace(grid,column);
    if(lowest!=-1)
        grid[lowest][column]=move;
}


int getLowestEmptySpace(int grid[6][7],int column)
{
	int i;
    for(i=0;i<6;i++)
        if(grid[i][column]==0)
            return i;
    return -1;
}


int isWinner(int grid[6][7],int move)
{
	int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<7-3;j++)
        {
            if(grid[i][j]==move&&grid[i][j+1]==move&&grid[i][j+2]==move&&grid[i][j+3]==move)
                return 1;
        }
    }

    for(i=0;i<6-3;i++)
    {
        for(j=0;j<7;j++)
        {
            if(grid[i][j]==move&&grid[i+1][j]==move&&grid[i+2][j]==move&&grid[i+3][j]==move)
                return 1;
        }
    }

    for(i=3;i<6;i++)
    {
        for(j=0;j<7-3;j++)
        {
            if(grid[i][j]==move&&grid[i-1][j+1]==move&&grid[i-2][j+2]==move&&grid[i-3][j+3]==move)
                return 1;
        }
    }

    for(i=0;i<6-3;i++)
    {
        for(j=0;j<7-3;j++)
        {
            if(grid[i][j]==move&&grid[i+1][j+1]==move&&grid[i+2][j+2]==move&&grid[i+3][j+3]==move)
                return 1;
        }
    }
    return -1;
}

