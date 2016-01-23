//	2 different codes

char botName[50]="Shruthi";
int bot(int grid[6][7],int move) {
    int i,j;
int pos[100],flag[100];//change
for(j=0;j<7;j++)
{
if(grid[0][j]==0&&j<6)
{
continue;
}
return 4;
}
for(i=0;i<6;i++)
for(j=0;j<5;j++)
{
if(grid[i][j]==1)
{
flag[1]=1;
pos[flag[1]]=j;
if(grid[i][j+1]==1)
{
flag[2]=1;
pos[flag[2]]=j+1;
if(grid[i][j+2]==1)
{
    if(j==5)
    {
        if(j>0&&grid[i][j-1]==0)//change
        {
            flag[13]=1;
            pos[flag[13]]=j-1;
        }
        else{
        continue;
        }
    }
    else{
flag[3]=1;
pos[flag[3]]=j+2;
    }
}
}
}
}
for(i=0;i<6;i++)
for(j=0;j<5;j++)
{
if(grid[i][j]==-1)
{
flag[4]=1;
pos[flag[4]]=j;
if(grid[i][j+1]==-1)
{
flag[5]=1;
pos[flag[5]]=j+1;
if(grid[i][j+2]==-1)
{

    if(i==5)
    {
        if(j>0&&grid[i][j-1]==0)//change
        {
            flag[14]=1;
            pos[flag[14]]=j-1;
        }
        else{
        continue;
        }

    }
flag[6]=1;
pos[flag[6]]=j+2;
}
}
}
}
for(i=0;i<4;i++)
for(j=0;j<7;j++)
{
if(grid[i][j]==1)
{
flag[7]=1;
pos[flag[7]]=j;
if(grid[i+1][j]==1)
{
flag[8]=1;
pos[flag[8]]=j;
if(grid[i+2][j]==1)
{
    if(i==4)
    {

        continue;
    }
    else{
flag[9]=1;
pos[flag[9]]=j;
    }
}
}
}
}
for(i=0;i<4;i++)
for(j=0;j<7;j++)
{
if(grid[i][j]==-1)
{
flag[10]=1;
pos[flag[10]]=j;
if(grid[i+1][j]==-1)
{
flag[11]=1;
pos[flag[11]]=j;
if(grid[i+2][j]==-1)
{

    if(i==4)
    {
        continue;
    }
    else{
flag[12]=1;
pos[flag[12]]=j;
    }
}
}
}
}
for(i=0;i<4;i++)
for(j=0;j<5;j++)
{
if(grid[i][j]==1)
{
flag[4]=1;
pos[flag[4]]=j;
if(grid[i+1][j+1]==1)
{
flag[5]=1;
pos[flag[5]]=j+1;
if(grid[i+2][j+2]==1)
{
flag[6]=1;
pos[flag[6]]=j+2;
}
}
}
}
for(i=0;i<4;i++)
for(j=0;j<5;j++)
{
if(grid[i][j]==-1)
{
flag[4]=1;
pos[flag[4]]=j;
if(grid[i+1][j+1]==-1)
{
flag[5]=1;
pos[flag[5]]=j+1;
if(grid[i+2][j+2]==-1)
{
flag[6]=1;
pos[flag[6]]=j+2;
}
}
}
}
printf("k");
if(flag[6]==1)
{
    if(pos[flag[6]]==7)
   return pos[flag[6]]-2;

else{
return pos[flag[6]]+1;
}
}

if(flag[12]==1)
return pos[flag[12]];
if(flag[13]==1)
return pos[flag[13]];
if(flag[5]==1)
return pos[flag[5]]+1;
if(flag[14]==1)
return pos[flag[14]];
if(flag[11]==1)
return pos[flag[11]];
if(flag[4]==1)
return pos[flag[4]]+1;
if(flag[10]==1)
return pos[flag[10]];
if(flag[3]==1)
return pos[flag[3]]+1;
if(flag[9]==1)
return pos[flag[9]];
if(flag[2]==1)
return pos[flag[2]]+1;
if(flag[8]==1)
return pos[flag[8]];
if(flag[1]==1)
return pos[flag[1]]+1;
if(flag[7]==1)
return pos[flag[7]];

}

int bot1(int grid[6][7],int move) {
    int count,i,j,r;
    printf("l");
    for(j=0;j<7;j++)
{
if(grid[0][j]==0&&j<6)
{
continue;
}
r=rand()%7;
return r;
}
  for(i=0;i<6;i++)     //horizontal check
  {
  for(j=0;j<7;j++)
  {
      if(grid[i][j]==1)
      {
          count++;
      if((j+1)<7&&grid[i][j+1]==1)
      {
        count++;
      if((j+2)<7&&grid[i][j+2]==1)
      {
          count++;
          if((j+3)<7&&grid[i][j+3]==0)
          return j+3;
          if((j-1)>0&&grid[i][j-1]==0)
          return j-1;
      }
  }
      }
  }
  }

for(i=0;i<6;i++)     //horizontal check for -1
  {
  for(j=0;j<7;j++)
  {
      if(grid[i][j]==-1)
      {
          count++;
      if((j+1)<7&&grid[i][j+1]==-1)
      {
        count++;
      if((j+2)<7&&grid[i][j+2]==-1)
      {
          count++;
          if((j+3)<7&&grid[i][j+3]==0)
          return j+3;
          if((j-1)>0&&grid[i][j-1]==0)
          return j-1;
      }
  }
      }
  }
  }
  for(i=0;i<6;i++)     //vertical check
  {
  for(j=0;j<7;j++)
  {
      if(grid[i][j]==1)
      {
          count++;
      if((i+1)<4&&grid[i+1][j]==1)
      {
        count++;
      if((i+2)<4&&grid[i+2][j]==1)
      {
          count++;
          if((i+3)<4&&grid[i+3][j]==0)
          return j;
         // if((i-1)>0&&grid[i-1][j]==0)
         // return j;
      }
  }
      }
  }
  }
   for(i=0;i<6;i++)     //vertical check for -1
  {
  for(j=0;j<7;j++)
  {
      if(grid[i][j]==-1)
      {
          count++;
      if((i+1)<4&&grid[i+1][j]==-1)
      {
        count++;
      if((i+2)<4&&grid[i+2][j]==-1)
      {
          count++;
          if((i+3)<4&&grid[i+3][j]==0)
          return j;
         // if((i-1)>0&&grid[i-1][j]==0)
         // return j;
      }
  }
      }
  }
  }
 for(i=0;i<6;i++)     //diagonal check
  {
  for(j=0;j<7;j++)
  {
      if(grid[i][j]==1)
      {
          count++;
      if((i+1)<4&&(j+1)<7&&grid[i+1][j+1]==1)
      {
        count++;
      if((i+2)<4&&(j+2)<7&&grid[i+2][j+2]==1)
      {
          count++;
          if((i+3)<4&&(j+3)<7&&grid[i+3][j+3]==0)
          return j;
         // if((i-1)>0&&grid[i-1][j]==0)
         // return j;
      }
  }
      }
  }
  }
   for(i=0;i<6;i++)     //diagonal check
  {
  for(j=0;j<7;j++)
  {
      if(grid[i][j]==-1)
      {
          count++;
      if((i+1)<4&&(j+1)<7&&grid[i+1][j+1]==-1)
      {
        count++;
      if((i+2)<4&&(j+2)<7&&grid[i+2][j+2]==-1)
      {
          count++;
          if((i+3)<4&&(j+3)<7&&grid[i+3][j+3]==0)
          return j;
         // if((i-1)>0&&grid[i-1][j]==0)
         // return j;
      }
  }
      }
  }
  }



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

