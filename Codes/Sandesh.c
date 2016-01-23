//	No error... But only for bot1()

char botName[50]="Sandesh";
int bot(int grid[6][7],int move) {

  int i,j;
  for(j=0;j<7;j++)
  {
    for(i=0;i<6;i++)
    {
      if(grid[0][j]!=0)
	break;
      else
      {
	
	if((grid[i+1][j]==-1&&grid[i+1][j]==-1&&grid[i+1][j]==-1)||(grid[i+1][j]==1&&grid[i+1][j]==1&&grid[i+1][j]==1)||grid[i][j+1]==-1&&grid[i][j+2]==-1&&grid[i][j+3]==-1||grid[i][j+1]==1&&grid[i][j+2]==1&&grid[i][j+3]==1&&i!=0)
	  return j;
//	else
//	  return rand()%7;
      }
    }
  }
  
}
