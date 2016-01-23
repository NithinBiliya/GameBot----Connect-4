//	No errors... 

char botName[50]="Anirudh_Gururaj";


int bot(int grid[6][7],int move) {
    int i,j,t;
	
    if(move==1)
    {


	for(i=0;i<6;i++)
	{
        for(j=0;j<7;j++)
        {
          if(grid[i][j]==1 && grid[i+1][j]==1 && grid[i+2][j]==1 && grid[i+3][j]==0 && i<3)
          {
            return j;
          }
          else if(grid[i][j]==1 && grid[i][j+1]==1 && grid[i][j+2]==1 && grid[i][j+3]==0 && j<4)
          {

                return j+3;
          }
          else if(grid[i][j]==1 && grid[i+1][j+1]==1 && grid[i+2][j+2]==1 && grid[i+3][j+3]==0 && i<3 && j<4)
          {
                    return j+3;
                  }
        else if(grid[i][j]==1 && grid[i-1][j-1]==1 && grid[i-2][j-2]==1 && grid[i-3][j-3]==0 && i>2 && j>2)
                {
                   return j-3;
                }
                else if(grid[i][j]==1 && grid[i-1][j+1]==1 && grid[i-2][j+2]==1 && grid[i-3][j+3]==0 && i>2 && j<4)
                {
                    return j+3;
                }
                else if(grid[i][j]==1 && grid[i+1][j-1]==1 && grid[i+2][j-2]==1 && grid[i+3][j-3]==0 && i<3 && j>2)
                {
                    return j-3;
                }
                else if(grid[i][j]==-1 && grid[i+1][j]==-1 && grid[i+2][j]==-1 && grid[i+3][j]==0 && i<3)
          {
            return j;
          }
          else if(grid[i][j]==-1 && grid[i][j+1]==-1 && grid[i][j+2]==-1 && grid[i][j+3]==0 && j<4)
          {
                return j+3;
          }
          else if(grid[i][j]==-1 && grid[i+1][j+1]==-1 && grid[i+2][j+2]==-1 && grid[i+3][j+3]==0 && i<3 && j<4)
          {
                    return j+3;
                  }
        else if(grid[i][j]==-1 && grid[i-1][j-1]==-1 && grid[i-2][j-2]==-1 && grid[i-3][j-3]==0 && i>2 && j>2)
                {
                   return j-3;
                }
                 else if(grid[i][j]==-1 && grid[i-1][j+1]==-1 && grid[i-2][j+2]==-1 && grid[i-3][j+3]==0 && i>2 && j<4)
                {
                    return j+3;
                }
                else if(grid[i][j]==-1 && grid[i+1][j-1]==-1 && grid[i+2][j-2]==-1 && grid[i+3][j-3]==0 && i<3 && j>2)
                {
                    return j-3;
                }
               else if(grid[i][j]==1 && grid[i+1][j]==1 && grid[i+2][j]==0  && i<4)
                {
                    return j;
                }
                 else if(grid[i][j]==1 && grid[i][j+1]==1 && grid[i][j+2]==0  && j<5) //||
                {
                    return j+2;
                }
                else if(grid[i][j]==1 && grid[i+1][j+1]==1 && grid[i+2][j+2]==0 && i<4  && j<5) //||
                {
                    return j+2;
                }
                else if(grid[i][j]==1 && grid[i-1][j-1]==1 && grid[i-2][j-2]==0  && j>1 && i>1)// ||
                {
                    return j-2;
                }
                else if(grid[i][j]==1 && grid[i-1][j+1]==1 && grid[i-2][j+2]==0 && i>1 && j<5)
                {
                    return j+2;
                }
                else if(grid[i][j]==1 && grid[i+1][j-1]==1 && grid[i+2][j-2]==0 && i<4 && j>1)
                {
                    return j-2;
                }

  }
	}
for(t=0;t<6;t++)
		if(grid[0][t]==0)
			return t;
	return 0;
    }
else    if(move==-1)
{





		for(i=0;i<6;i++)
	{
        for(j=0;j<7;j++)
        {

	                 if(grid[i][j]==-1 && grid[i+1][j]==-1 && grid[i+2][j]==-1 && grid[i+3][j]==0 && i<3)
          {
            return j;
          }
          else if(grid[i][j]==-1 && grid[i][j+1]==-1 && grid[i][j+2]==-1 && grid[i][j+3]==0 && j<4)
          {
                return j+3;
          }
          else if(grid[i][j]==-1 && grid[i+1][j+1]==-1 && grid[i+2][j+2]==-1 && grid[i+3][j+3]==0 && i<3 && j<4)
          {
                    return j+3;
                  }
        else if(grid[i][j]==-1 && grid[i-1][j-1]==-1 && grid[i-2][j-2]==-1 && grid[i-3][j-3]==0 && i>2 && j>2)
                {
                   return j-3;
                }
                 else if(grid[i][j]==-1 && grid[i-1][j+1]==-1 && grid[i-2][j+2]==-1 && grid[i-3][j+3]==0 && i>2 && j<4)
                {
                    return j+3;
                }
                else if(grid[i][j]==-1 && grid[i+1][j-1]==-1 && grid[i+2][j-2]==-1 && grid[i+3][j-3]==0 && i<3 && j>2)
                {
                    return j-3;
                }

       else   if(grid[i][j]==1 && grid[i+1][j]==1 && grid[i+2][j]==1 && grid[i+3][j]==0 && i<3)
          {
            return j;
          }
          else if(grid[i][j]==1 && grid[i][j+1]==1 && grid[i][j+2]==1 && grid[i][j+3]==0 && j<4)
          {

                return j+3;
          }
          else if(grid[i][j]==1 && grid[i+1][j+1]==1 && grid[i+2][j+2]==1 && grid[i+3][j+3]==0 && i<3 && j<4)
          {
                    return j+3;
                  }
        else if(grid[i][j]==1 && grid[i-1][j-1]==1 && grid[i-2][j-2]==1 && grid[i-3][j-3]==0 && i>2 && j>2)
                {
                   return j-3;
                }
                else if(grid[i][j]==1 && grid[i-1][j+1]==1 && grid[i-2][j+2]==1 && grid[i-3][j+3]==0 && i>2 && j<4)
                {
                    return j+3;
                }
                else if(grid[i][j]==1 && grid[i+1][j-1]==1 && grid[i+2][j-2]==1 && grid[i+3][j-3]==0 && i<3 && j>2)
                {
                    return j-3;
                }

	                else if(grid[i][j]==-1 && grid[i+1][j]==-1 && grid[i+2][j]==0  && i<4)
                {
                    return j;
                }
                else if(grid[i][j]==-1 && grid[i][j+1]==-1 && grid[i][j+2]==0  && j<5)
                {
                    return j+2;
                }
                else if(grid[i][j]==-1 && grid[i+1][j+1]==-1 && grid[i=2][j+2]==0 && i<4  && j<5)
                {
                    return j+2;
                }
                else if(grid[i][j]==-1 && grid[i-1][j-1]==-1 && grid[i-2][j-2]==0  && i>1 && j>1)
                {
                    return j-2;
                }
                  else if(grid[i][j]==-1 && grid[i-1][j+1]==-1 && grid[i-2][j+2]==0 && i>1 && j<5)
                {
                    return j+2;
                }
                else if(grid[i][j]==-1 && grid[i+1][j-1]==-1 && grid[i+2][j-2]==0 && i<4 && j>1)
                {
                    return j-2;
                }


        }
	}

	for(t=0;t<6;t++)
		if(grid[0][t]==0)	// condition to check whether the particular column is full
			return t;
	return 0;

	
    }




}
