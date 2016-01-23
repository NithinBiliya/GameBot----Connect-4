//	No error... but works only for bot1

char botName[50]="Himani_Rosita";
int bot(int grid[6][7],int move) {
    int i,j,count=1,k;

if(move==1) {

			for(i=5;i>=0;i--) //to check horizantally from left towards right
			{

			    for(j=6;j>=3;j--)

			    {

			        if(grid[i][6-j]==-1)//count=1 starts from here
			        {
			            k=6-j+1;//over here is this k variable  appropriate?
			            while(grid[i][k]==-1)
			        {

			            count++;
			            if(count==2 && grid[i][k+1]==0)
			            {     count=1;
if(grid[0][k+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return k+1;//this will return increamented value of k in if condition right?
			               // break;
			            }
			           else if(count==3)
			            {
			                 count=1;
if(grid[0][k+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return k+1;  //is return value (k+1) is correct for this code??

			                //break;
			            }
			            k++;
			        }}
			        //code for mypawn
                //else if(grid[0][j]==0)//is grid[0][j]==0 correct?
			       {

			       if(grid[i][6-j]==1)
			        {
			            k=6-j+1;

			            while(grid[i][k]==1)
			            {
			                count++;
			                if((count==3 || count==2 || count==1) && grid[i][k+1]==0)
			                {
			                    count=1;
if(grid[0][k+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                    return k+1;
			                  //  break;
			                }

			                k++;
			            }
			        }

			        }}}
			        //code to check horizantally from right towards left

			        for(i=5;i>=0;i--)
			        {
			            for(j=0;j<=3;j++)
			            {
			                if(grid[i][6-j]==-1)
			                {
			                    k=6-j-1;
			                    while(grid[i][k]==-1)
			                    {
			                       // k=6-j+1;
			                        count++;
			                        if(count==2 && grid[i][k-1]==0)
			                        {count=1;
if(grid[0][k-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                            return k-1; //is this k-1 will be correct
			                                        // or k...i mean i want the current valur of k
			                                        //so in if loop condition  will be decreamented
			                                        //or not??

			                            //break;
			                        }
			                       if(count==3)
			                        {

			                             count=1;
if(grid[0][k-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                               return k-1;

			                           // break;
			                        }
			                        k--;
			                    }
			                }
			                //code for my pawn
			       else if(grid[0][j]==0)
			           {
			               if(grid[i][6-j]==1)
			             {
			                 k=6-j-1;
			               while(grid[i][k]==1)
			               {
			                   count++;
			                   if((count==2 || count==1) && grid[i][k-1]==0)
			                        { count=1;
if(grid[0][k]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                            return k;

			                          //  break;
			                        }
			                       if(count==3)
			                        {  count=1;
if(grid[0][k-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                            return k-1;

			                            //break;
			                        }
			                        k--;
			               }
			           }
			            }
			        }}

   //code to check whether there is an empty place between any two oponent's pawns

     for(i=5;i>=0;i--)
     {
         for(j=0;j<=4;j++)
         {
             if(grid[i][j]==-1 && grid[i][j+1]==0 && grid[i][j+2]==-1)
             {
if(grid[0][j+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                 return j+1;
             }    //this code work sometimes but sometimes it doesn't work
             else if(grid[i][j]==1 && grid[i][j+1]==0 && grid[i][j+2]==1)
             {
if(grid[0][j+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                   return j+1;
             }

         }
     }

//to check vertically
			    for(j=0;j<7;j++)
			    {
                                       //is this code correct?
			        for(i=0;i<=5;i++)
			        {
			            if(grid[5-i][j]==-1)
			            {
			                k=5-i-1;
			                while(grid[k][j]==-1)
			                {

			                    count++;
			                    if(count==3)
			                    {
			                        count=1;
if(grid[0][k-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                        return k-1;

			                        //break;
			                    }
			                    k--;
			                }
			            }
			            else if(grid[5-i][j]==1)
			            {
			                k=5-i-1;
			                while(grid[k][j]==1)
			                {
			                    count++;
			                    if(count==3)
			                    {
			                        count=1;
if(grid[0][k-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                        return k-1;
			                    }
			                    k--;
			                }
			            }
			        }
			    }

			    //to check diagonally
			    //case 1:
			    for(i=0;i<=3;i++)
			    {
			        for(j=6;j>=3;j--)
			        {
			            if(grid[i][j]==-1 && grid[i+1][j-1]==-1 && grid[i+2][j-2]==-1 && grid[i+3][j-3]==0)
			            {
if(grid[0][j-3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return j-3;
			                //break;
			            }
			            //code for my pawn
			         /*   else if(grid[i][j]==0)
			            {
			                return j;   //is this part needed over here?
			            }*/
			           else if(grid[i][j]==1 && grid[i+1][j-1]==0)
			           {
if(grid[0][j-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			               return j-1;
			           }
			           else if(grid[i][j]==1 && grid[i+1][j-1]==1 && grid[i+2][j-2]==0
                                 && (grid[i+3][j-3]==0 || grid[i+3][j-3]==1))
                                 {
if(grid[0][j-2]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                                     return j-2;
                                 }
                        else if(grid[i][j]==1 && grid[i+1][j-1]==1 && grid[i+2][j-2]==1
                                && grid[i+3][j-3]==0)
                                {
if(grid[0][j-3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                                    return j-3;
                                }


			        }
			    }
			    //case 2:
			    for(i=0;i<=2;i++)
			    {
			        for(j=0;j<=3;j++)
			        {
			            if(grid[i][j]==-1 && grid[i+1][j+1]==-1 && grid[i+2][j+2]==-1 && grid[i+3][j+3]==0)
			            {
if(grid[0][j+3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return j+3;
			               // break;
			            }
			            else if(grid[i][j]==1 && grid[i+1][j+1]==0)
			            {
if(grid[0][j+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return j+1;
                        }
                        else if(grid[i][j]==1 && grid[i+1][j+1]==1 && grid[i+2][j+2]==0 && (grid[i+3][j+3]==1 || grid[i+3][j+3]==0))
                        {
if(grid[0][j+2]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j+2;
                        }
                        else if(grid[i][j]==1 && grid[i+1][j+1]==1 && grid[i+2][j+2]==1 && grid[i+3][j+3]==0)
                        {
if(grid[0][j+3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j+3;
                        }
			        }
			    }
			    //case 3:
			    for(i=5;i>=3;i--)
			    {
			        for(j=0;j<7;j++)
			        {
			            if(grid[i][j]==-1 && grid[i-1][j+1]==-1 && grid[i-2][j+2]==-1 && grid[i-3][j+3]==0)
			            {
if(grid[0][j+3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return j+3;
			               //break;
			            }
                else if(grid[i][j]==1 && grid[i-1][j+1]==0)
                {
if(grid[0][j+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                    return j+1;
                }
                else if(grid[i][j]==1 && grid[i-1][j+1]==1 && grid[i-2][j+2]==0 && (grid[i-3][j+3]==0 || grid[i-3][j+3]==1))
               {
if(grid[0][j+2]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                   return j+2;
               }
               else if(grid[i][j]==1 && grid[i-1][j+1]==1 && grid[i-2][j+2]==1 && grid[i-3][j+3]==0)
               {
if(grid[0][j+3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                   return j+3;
               }

                }
			    }
                //case 4:
                for(i=5;i>=3;i--)
                {
                    for(j=6;j>=0;j--)
                    {
                        if(grid[i][j]==-1 && grid[i-1][j-1]==-1 && grid[i-2][j-2]==-1 && grid[i-3][j-3]==0)
                        {
if(grid[0][j-3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j-3;
                            //break;
                        }
                        else if(grid[i][j]==1 && grid[i-1][j-1]==0)
                        {
if(grid[0][j-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j-1;
                        }
                        else if(grid[i][j]==1 && grid[i-1][j-1]==1 && grid[i-2][j-2]==0 && (grid[i-3][j-3]==0 || grid[i-3][j-3]==1))
                        {
if(grid[0][j-2]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j-2;
                        }
                        else if(grid[i][j]==1 && grid[i-1][j-1]==1 && grid[i-2][j-2]==1 && grid[i-3][j-3]==0)
                        {
if(grid[0][j-3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j-3;
                        }
                    }
                }

                for(i=0;i<6;i++)
		if(grid[0][i]==0)	// condition to check whether the particular column is full
		{
if(grid[0][i]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
return i;

		}
			else
			{
			  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
			}
	return 0;
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
else
{


			for(i=5;i>=0;i--) //to check horizantally from left towards right
			{

			    for(j=6;j>=3;j--)

			    {

			        if(grid[i][6-j]==1)//count=1 starts from here
			        {
			            k=6-j+1;//over here is this k variable  appropriate?
			            while(grid[i][k]==1)
			        {

			            count++;
			            if(count==2 && grid[i][k+1]==0)
			            {     count=1;
if(grid[0][k+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return k+1;//this will return increamented value of k in if condition right?
			               // break;
			            }
			           else if(count==3)
			            {
			                 count=1;
if(grid[0][k+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return k+1;  //is return value (k+1) is correct for this code??

			                //break;
			            }
			            k++;
			        }}
			        //code for mypawn
                //else if(grid[0][j]==0)//is grid[0][j]==0 correct?
			       {

			       if(grid[i][6-j]==-1)
			        {
			            k=6-j+1;

			            while(grid[i][k]==-1)
			            {
			                count++;
			                if((count==3 || count==2 || count==1) && grid[i][k+1]==0)
			                {
			                    count=1;
if(grid[0][k+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                    return k+1;
			                  //  break;
			                }

			                k++;
			            }
			        }

			        }}}
			        //code to check horizantally from right towards left

			        for(i=5;i>=0;i--)
			        {
			            for(j=0;j<=3;j++)
			            {
			                if(grid[i][6-j]==1)
			                {
			                    k=6-j-1;
			                    while(grid[i][k]==1)
			                    {
			                       // k=6-j+1;
			                        count++;
			                        if(count==2 && grid[i][k-1]==0)
			                        {count=1;
if(grid[0][k-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                            return k-1; //is this k-1 will be correct
			                                        // or k...i mean i want the current valur of k
			                                        //so in if loop condition  will be decreamented
			                                        //or not??

			                            //break;
			                        }
			                       if(count==3)
			                        {

			                             count=1;
if(grid[0][k-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                               return k-1;

			                           // break;
			                        }
			                        k--;
			                    }
			                }
			                //code for my pawn
			       else if(grid[0][j]==0)
			           {
			               if(grid[i][6-j]==-1)
			             {
			                 k=6-j-1;
			               while(grid[i][k]==-1)
			               {
			                   count++;
			                   if((count==2 || count==1) && grid[i][k-1]==0)
			                        { count=1;
if(grid[0][k]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                            return k;

			                          //  break;
			                        }
			                       if(count==3)
			                        {  count=1;
if(grid[0][k-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                            return k-1;

			                            //break;
			                        }
			                        k--;
			               }
			           }
			            }
			        }}

   //code to check whether there is an empty place between any two oponent's pawns

     for(i=5;i>=0;i--)
     {
         for(j=0;j<=4;j++)
         {
             if(grid[i][j]==1 && grid[i][j+1]==0 && grid[i][j+2]==1)
             {
if(grid[0][j+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                 return j+1;
             }    //this code work sometimes but sometimes it doesn't work
             else if(grid[i][j]==-1 && grid[i][j+1]==0 && grid[i][j+2]==-1)
             {
if(grid[0][j+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                   return j+1;
             }

         }
     }

//to check vertically
			    for(j=0;j<7;j++)
			    {
                                       //is this code correct?
			        for(i=0;i<=5;i++)
			        {
			            if(grid[5-i][j]==1)
			            {
			                k=5-i-1;
			                while(grid[k][j]==1)
			                {

			                    count++;
			                    if(count==3)
			                    {
			                        count=1;
if(grid[0][k-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                        return k-1;

			                        //break;
			                    }
			                    k--;
			                }
			            }
			            else if(grid[5-i][j]==-1 )
			            {
			                k=5-i-1;
			                while(grid[k][j]==-1)
			                {
			                    count++;
			                    if(count==3)
			                    {
			                        count=1;
if(grid[0][k-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                        return k-1;
			                    }
			                    k--;
			                }
			            }
			        }
			    }

			    //to check diagonally
			    //case 1:
			    for(i=0;i<=3;i++)
			    {
			        for(j=6;j>=3;j--)
			        {
			            if(grid[i][j]==1 && grid[i+1][j-1]==1 && grid[i+2][j-2]==1 && grid[i+3][j-3]==0)
			            {
if(grid[0][j-3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return j-3;
			                //break;
			            }
			            //code for my pawn
			         /*   else if(grid[i][j]==0)
			            {
			                return j;   //is this part needed over here?
			            }*/
			           else if(grid[i][j]==-1 )
			           {
if(grid[0][j-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			               return j-1;
			           }
			           else if(grid[i][j]==-1 && grid[i+1][j-1]==-1 && grid[i+2][j-2]==0
                                 && (grid[i+3][j-3]==0 || grid[i+3][j-3]==-1))
                                 {
if(grid[0][j-2]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                                     return j-2;
                                 }
                        else if(grid[i][j]==-1 && grid[i+1][j-1]==-1 && grid[i+2][j-2]==-1
                                && grid[i+3][j-3]==0)
                                {
if(grid[0][j-3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                                    return j-3;
                                }


			        }
			    }
			    //case 2:
			    for(i=0;i<=2;i++)
			    {
			        for(j=0;j<=3;j++)
			        {
			            if(grid[i][j]==1 && grid[i+1][j+1]==1 && grid[i+2][j+2]==1 && grid[i+3][j+3]==0)
			            {
if(grid[0][j+3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return j+3;
			               // break;
			            }
			            else if(grid[i][j]==-1 && grid[i+1][j+1]==0)
			            {
if(grid[0][j+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return j+1;
                        }
                        else if(grid[i][j]==-1 && grid[i+1][j+1]==-1 && grid[i+2][j+2]==0 && (grid[i+3][j+3]==-1 || grid[i+3][j+3]==0))
                        {
if(grid[0][j+2]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j+2;
                        }
                        else if(grid[i][j]==-1 && grid[i+1][j+1]==-1 && grid[i+2][j+2]==-1 && grid[i+3][j+3]==0)
                        {
if(grid[0][j+3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j+3;
                        }
			        }
			    }
			    //case 3:
			    for(i=5;i>=3;i--)
			    {
			        for(j=0;j<7;j++)
			        {
			            if(grid[i][j]==1 && grid[i-1][j+1]==1 && grid[i-2][j+2]==1 && grid[i-3][j+3]==0)
			            {
if(grid[0][j+3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
			                return j+3;
			               //break;
			            }
                else if(grid[i][j]==-1 && grid[i-1][j+1]==0)
                {
if(grid[0][j+1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                    return j+1;
                }
                else if(grid[i][j]==-1 && grid[i-1][j+1]==-1 && grid[i-2][j+2]==0 && (grid[i-3][j+3]==0 || grid[i-3][j+3]==-1))
               {
if(grid[0][j+2]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                   return j+2;
               }
               else if(grid[i][j]==-1 && grid[i-1][j+1]==-1 && grid[i-2][j+2]==-1 && grid[i-3][j+3]==0)
               {
if(grid[0][j+3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                   return j+3;
               }

                }
			    }
                //case 4:
                for(i=5;i>=3;i--)
                {
                    for(j=6;j>=0;j--)
                    {
                        if(grid[i][j]==1 && grid[i-1][j-1]==1 && grid[i-2][j-2]==1 && grid[i-3][j-3]==0)
                        {
if(grid[0][j-3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j-3;
                            //break;
                        }
                        else if(grid[i][j]==-1 && grid[i-1][j-1]==0)
                        {
if(grid[0][j-1]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j-1;
                        }
                        else if(grid[i][j]==-1 && grid[i-1][j-1]==-1 && grid[i-2][j-2]==0 && (grid[i-3][j-3]==0 || grid[i-3][j-3]==-1))
                        {
if(grid[0][j-2]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j-2;
                        }
                        else if(grid[i][j]==-1 && grid[i-1][j-1]==-1 && grid[i-2][j-2]==-1 && grid[i-3][j-3]==0)
                        {
if(grid[0][j-3]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
                            return j-3;
                        }
                    }
                }

                for(i=0;i<6;i++)
		if(grid[0][i]==0)	// condition to check whether the particular column is full
		{
if(grid[0][i]!=0)
{
  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
}
return i;

		}
			else
			{
			  int r;
  do {
		r=rand()%7;
	}while(grid[0][r]!=0);		//	Condition to check whether the randomly selected column is full
	return r;
			}
	return 0;
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

}
