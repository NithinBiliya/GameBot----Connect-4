//	... no error

char botName[50]="Sumanth";
int bot(int grid[6][7],int move) {
    int i=5,j,count=0;
    int colcount[7];
    int col,colj;
    int rowcount[6];

if(move==1)
{

    for(j=0;j<7;j++)//column checking
     {
         for(i=0;i<6;i++)
          {
              if(grid[i][j]==1&&grid[i-1][j]==0)
               {
                   while(grid[i][j]==1)
                    {
                        count++;
                        i++;
                        if(count==3&&grid[0][j]==0)
                         {
                             return j;
                         }
                    }
                   count=0;
               }
          }
         count=0;
         i=0;
     }


   for(i=0;i<6;i++)//row checking
     {
         for(j=0;j<7;j++)
          {
              if(grid[i][j]==1)
               {
                   while(grid[i][j]==1)
                    {
                        count++;
                        j++;
                        if(count==3&&grid[i][j]==0&&grid[0][j]==0)
                         {
                             return j;
                         }
                    }
                   count=0;
               }
          }
         count=0;
         j=0;
     }

//checking ends here
    i=0;
    j=0;
    for(i=0;i<6;i++)
     {
         for(j=0;j<7;j++)
          {
              if(grid[i][j]==-1&&grid[i-1][j]==0)
               return j;
              if(grid[i][j]==-1&&grid[i][j+1]==0&&grid[i+1][j+1]!=0&&j!=6)
               return j+1;
              if(grid[i][j]==-1&&grid[i][j-1]==0&&grid[i+1][j-1]!=0&&j!=0)
               return j-1;
          }
     }
 return rand()%7;

    /* for(i=5;i>=0;i--)
      {
          for(j=6;j>=0;j--)

           {
               while(grid[i][j]!=-1);
               if(j<=3&&grid[i][j+1]!=1)
                return j+1;

           }
      }

     return rand()%7;



   /*(for(i=5;i>=0;i--)
    {

        for(j=0;j<7;j++)
         {
             if(grid[i][j]==1)
              {

                  while(grid[i][j]==1)
                   {
                       count++;
                       j++;

                       if(count==3&&grid[j][0]==0)
                         return j;
                   }
                  count=0;

              }
         }
    }*/

/*

	This is where your opponent's code will be placed. You can paste any of the sampleBot codes that are given for development and testing purposes
*/
}
else
{
    for(j=0;j<7;j++)//column checking
     {
         for(i=0;i<6;i++)
          {
              if(grid[i][j]==-1&&grid[i-1][j]==0)
               {
                   while(grid[i][j]==-1)
                    {
                        count++;
                        i++;
                        if(count==3&&grid[0][j]==0)
                         {
                             return j;
                         }
                    }
                   count=0;
               }
          }
         count=0;
         i=0;
     }


   for(i=0;i<6;i++)//row checking
     {
         for(j=0;j<7;j++)
          {
              if(grid[i][j]==-1)
               {
                   while(grid[i][j]==-1)
                    {
                        count++;
                        j++;
                        if(count==3&&grid[i][j]==0&&grid[0][j]==0)
                         {
                             return j;
                         }
                    }
                   count=0;
               }
          }
         count=0;
         j=0;
     }

//checking ends here
    i=0;
    j=0;
    for(i=0;i<6;i++)
     {
         for(j=0;j<7;j++)
          {
              if(grid[i][j]==1&&grid[i-1][j]==0)
               return j;
              if(grid[i][j]==1&&grid[i][j+1]==0&&grid[i+1][j+1]!=0&&j!=6)
               return j+1;
              if(grid[i][j]==1&&grid[i][j-1]==0&&grid[i+1][j-1]!=0&&j!=0)
               return j-1;
          }
     }
 return rand()%7;

    /* for(i=5;i>=0;i--)
      {
          for(j=6;j>=0;j--)


           {
               while(grid[i][j]!=-1);
               if(j<=3&&grid[i][j+1]!=1)
                return j+1;


           }
      }


     return rand()%7;




   /*(for(i=5;i>=0;i--)
    {

        for(j=0;j<7;j++)

         {
             if(grid[i][j]==1)
              {


                  while(grid[i][j]==1)
                   {
                       count++;
                       j++;


                       if(count==3&&grid[j][0]==0)
                         return j;
                   }

                  count=0;

              }
         }

    }*/

/*


	This is where your opponent's code will be placed. You can paste any of the sampleBot codes that are given for development and testing purposes
*/
}
}
