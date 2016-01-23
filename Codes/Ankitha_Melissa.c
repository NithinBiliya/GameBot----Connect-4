//	No errors... Works for both bots...

char botName[50]="Ankitha_Melissa";
int bot(int grid[6][7],int move) {
    int i,j;

	for(i=0;i<7;i++) //to check my bot in col
	for(j=0;j<3;j++)
	{
	   // printf("%d ",i);
	    if(grid[j][i]==0&&grid[j+1][i]==move&&grid[j+2][i]==move&&grid[j+3][i]==move)
	   return i;


	}


	for(i=5;i>=0;i--) //to check  bot1 in row
	for(j=0;j<7;j++)
	{

	    if(i==5){
	     if((j+3)<7&&grid[i][j]==0&&grid[i][j+1]==move&&grid[i][j+2]==move&&grid[i][j+3]==move)
	      return j;
	    if((j+2)<7&&(j-1)>=0&&grid[i][j]==0&&grid[i][j-1]==move&&grid[i][j+1]==move&&grid[i][j+2]==move)
	     return (j);
	    if((j+1)<7&&(j-2)>=0&&grid[i][j]==0&&grid[i][j-2]==move&&grid[i][j-1]==move&&grid[i][j+1]==move)
	     return (j);
	    if((j-3)>=0&&grid[i][j]==0&&grid[i][j-1]==move&&grid[i][j-2]==move&&grid[i][j-3]==move)
	      return (j);
	      if((j-2)>=0&&(j+2)<7&&grid[i][j]==0&&grid[i][j-1]==move&&grid[i][j-2]==move&&grid[i][j+1]==move&&grid[i][j+2]==move)
	        return j;
	    }
	    else
	    {
	        if((j+3)<7&&grid[i][j]==0&&grid[i][j+1]==move&&grid[i][j+2]==move&&grid[i][j+3]==move&&grid[i+1][j]!=0)
        return j;
	    if((j+2)<7&&(j-1)>=0&&grid[i][j]==0&&grid[i][j-1]==move&&grid[i][j+1]==move&&grid[i][j+2]==move&&grid[i+1][j]!=0)
	      return (j);
	    if((j+1)<7&&(j-2)>=0&&grid[i][j]==0&&grid[i][j-2]==move&&grid[i][j-1]==move&&grid[i][j+1]==move&&grid[i+1][j]!=0)
	    return (j);
	    if((j-3)>=0&&grid[i][j]==0&&grid[i][j-1]==move&&grid[i][j-2]==move&&grid[i][j-3]==move&&grid[i+1][j]!=0)
	     return (j);
	     if((j-2)>=0&&(j+2)<7&&grid[i][j]==0&&grid[i][j-1]==move&&grid[i][j-2]==move&&grid[i][j+1]==move&&grid[i][j+2]==move&&grid[i+1][j]!=0)
	        return j;
	    }
	}

for(i=0;i<6;i++)//  bot1 in diagonal
for(j=0;j<7;j++)
  {
      if((j-3)>=0&&(i+3)<6&&grid[i][j]==0&&grid[i+3][j-3]==move&&grid[i+2][j-2]==move&&grid[i+1][j-1]==move&&grid[i+1][j]!=0)
       return j;
        if((j+3)<7&&(i+3)<6&&grid[i][j]==0&&grid[i+1][j+1]==move&&grid[i+2][j+2]==move&&grid[i+3][j+3]==move&&grid[i+1][j]!=0)
       return j;
         if((j-2)>=0&&(j+1)<7&&(i-1)>=0&&(i+2)<6&&grid[i][j]==0&&grid[i-1][j+1]==move&&grid[i+2][j-2]==move&&grid[i+1][j-1]==move&&grid[i+1][j]!=0)
         return j;
        if((j+2)<7&&(j-1)>=0&&(i+2)<6&&(i-1)>=0&&grid[i][j]==0&&grid[i+1][j+1]==move&&grid[i+2][j+2]==move&&grid[i-1][j-1]==move&&grid[i+1][j]!=0)
        return j;
        if((j-1)>=0&&(j+2)<7&&(i-2)>=0&&(i+1)<6&&grid[i][j]==0&&grid[i-1][j+1]==move&&grid[i-2][j+2]==move&&grid[i+1][j-1]==move&&grid[i+1][j]!=0)
          return j;
        if((j+1)<7&&(j-2)>=0&&(i+1)<6&&(i-2)>=0&&grid[i][j]==0&&grid[i+1][j+1]==move&&grid[i-2][j-2]==move&&grid[i-1][j-1]==move&&grid[i+1][j]!=0)
       return j;
        if((j+3)<0&&(j-3)>=0&&grid[i][j]==0&&grid[i-1][j+1]==move&&grid[i-2][j+2]==move&&grid[i-3][j+3]==move&&grid[i+1][j]!=0)
       return j;
        if((j-3)>=0&&(i-3)>=0&&grid[i][j]==0&&grid[i-3][j-3]==move&&grid[i-2][j-2]==move&&grid[i-1][j-1]==move&&grid[i+1][j]!=0)
        return j;
        if((j-2)>=0&&(i-2)>=0&&(j+2)<7&&(i+2)<6&&grid[i][j]==0&&grid[i+1][j-1]==move&&grid[i+1][j-2]==move&&grid[i-1][j+1]==move&&grid[i-2][j+2]==move&&grid[i+1][j]!=0)
        return j;
        if((j-2)>=0&&(i-2)>=0&&(j+2)<7&&(i+2)<6&&grid[i][j]==0&&grid[i+1][j+1]==move&&grid[i+1][j+2]==move&&grid[i-1][j-1]==move&&grid[i-2][j-2]==move&&grid[i+1][j]!=0)
        return j;
  }

	for(i=5;i>=0;i--)//other bot in row
	for(j=0;j<7;j++)
	{

	    if(i==5){
	    if((j+3)<7&&grid[i][j]==0&&grid[i][j+1]==-(move)&&grid[i][j+2]==-(move)&&grid[i][j+3]==-(move))
	      return j;
	    if((j+2)<7&&(j-1)>=0&&grid[i][j]==0&&grid[i][j-1]==-(move)&&grid[i][j+1]==-(move)&&grid[i][j+2]==-(move))
	    return (j);
	    if((j+1)<7&&(j-2)>=0&&grid[i][j]==0&&grid[i][j-2]==-(move)&&grid[i][j-1]==-(move)&&grid[i][j+1]==-(move))
	      return (j);
	    if((j-3)>=0&&grid[i][j]==0&&grid[i][j-1]==-(move)&&grid[i][j-2]==-(move)&&grid[i][j-3]==-(move))
	     return (j);
	     if((j-2)>=0&&(j+2)<7&&grid[i][j]==0&&grid[i][j-1]==-(move)&&grid[i][j-2]==-(move)&&grid[i][j+1]==-(move)&&grid[i][j+2]==-(move))
	        return j;
	     }
	    else
	    {
	     if((j+3)<7&&grid[i][j]==0&&grid[i+1][j]!=0&&grid[i][j+1]==-(move)&&grid[i][j+2]==-(move)&&grid[i][j+3]==-(move)&&grid[i+1][j]!=0)
	      return j;
	    if((j+2)<7&&(j-1)>=0&&grid[i][j]==0&&grid[i+1][j]!=0&&grid[i][j-1]==-(move)&&grid[i][j+1]==-(move)&&grid[i][j+2]==-(move)&&grid[i+1][j]!=0)
	    return (j);
	    if((j+1)<7&&(j-2)>=0&&grid[i][j]==0&&grid[i+1][j]!=0&&grid[i][j-2]==-(move)&&grid[i][j-1]==-(move)&&grid[i][j+1]==-(move)&&grid[i+1][j]!=0)
	      return (j);
	    if((j-3)>=0&&grid[i][j]==0&&grid[i+1][j]!=0&&grid[i][j-1]==-(move)&&grid[i][j-2]==-(move)&&grid[i][j-3]==-(move)&&grid[i+1][j]!=0)
	     return (j);
	     if((j-2)>=0&&(j+2)<7&&grid[i][j]==0&&grid[i+1][j]!=0&&grid[i][j-1]==-(move)&&grid[i][j-2]==-(move)&&grid[i][j+1]==-(move)&&grid[i][j+2]==-(move)&&grid[i+1][j]!=0)
	        return j;
	    }
	}

for(i=0;i<7;i++) //to check other bot in col
	for(j=0;j<3;j++)
	{
	    if(grid[j][i]==0&&grid[j+1][i]==-(move)&&grid[j+2][i]==-(move)&&grid[j+3][i]==-(move))
	    return i;


	}

for(i=0;i<6;i++)// other bot in diagonal
for(j=0;j<7;j++)
  {
      if((j-3)>=0&&(i+3)<6&&grid[i][j]==0&&grid[i+3][j-3]==-(move)&&grid[i+2][j-2]==-(move)&&grid[i+1][j-1]==-(move)&&grid[i+1][j]!=0)
        return j;
        if((j+3)<7&&(i+3)<6&&grid[i][j]==0&&grid[i+1][j+1]==-(move)&&grid[i+2][j+2]==-(move)&&grid[i+3][j+3]==-(move)&&grid[i+1][j]!=0)
          return j;
         if((j-2)>=0&&(j+1)<7&&(i-1)>=0&&(i+2)<6&&grid[i][j]==0&&grid[i-1][j+1]==-(move)&&grid[i+2][j-2]==-(move)&&grid[i+1][j-1]==-(move)&&grid[i+1][j]!=0)
         return j;
        if((j+2)<7&&(j-1)>=0&&(i+2)<6&&(i-1)>=0&&grid[i][j]==0&&grid[i+1][j+1]==-(move)&&grid[i+2][j+2]==-(move)&&grid[i-1][j-1]==-(move)&&grid[i+1][j]!=0)
        return j;
        if((j-1)>=0&&(j+2)<7&&(i-2)>=0&&(i+1)<6&&grid[i][j]==0&&grid[i-1][j+1]==-(move)&&grid[i-2][j+2]==-(move)&&grid[i+1][j-1]==-(move)&&grid[i+1][j]!=0)
          return j;
        if((j+1)<7&&(j-2)>=0&&(i+1)<6&&(i-2)>=0&&grid[i][j]==0&&grid[i+1][j+1]==-(move)&&grid[i-2][j-2]==-(move)&&grid[i-1][j-1]==-(move)&&grid[i+1][j]!=0)
         return j;
        if((j+3)<0&&(j-3)>=0&&grid[i][j]==0&&grid[i-1][j+1]==-(move)&&grid[i-2][j+2]==-(move)&&grid[i-3][j+3]==-(move))
          return j;
        if((j-3)>=0&&(i-3)>=0&&grid[i][j]==0&&grid[i-3][j-3]==-(move)&&grid[i-2][j-2]==-(move)&&grid[i-1][j-1]==-(move))
        return j;
        if((j-2)>=0&&(i-2)>=0&&(j+2)<7&&(i+2)<6&&grid[i][j]==0&&grid[i+1][j-1]==-(move)&&grid[i+1][j-2]==-(move)&&grid[i-1][j+1]==-(move)&&grid[i-2][j+2]==-(move)&&grid[i+1][j]!=0)
        return j;
        if((j-2)>=0&&(i-2)>=0&&(j+2)<7&&(i+2)<6&&grid[i][j]==0&&grid[i+1][j+1]==-(move)&&grid[i+1][j+2]==-(move)&&grid[i-1][j-1]==-(move)&&grid[i-2][j-2]==-(move)&&grid[i+1][j]!=0)
        return j;
  }
for(i=0;i<6;i++)
for(j=0;j<7;j++)
{
    if((j+3)<7&&grid[i][j]==0&&grid[i][j+1]==move&&grid[i][j+2]==move&&grid[i][j+3]==move)
	      return j;
	    if((j+2)<7&&(j-1)>=0&&grid[i][j]==0&&grid[i][j-1]==move&&grid[i][j+1]==move&&grid[i][j+2]==move)
	     return (j);
	    if((j+1)<7&&(j-2)>=0&&grid[i][j]==0&&grid[i][j-2]==move&&grid[i][j-1]==move&&grid[i][j+1]==move)
	     return (j);
	    if((j-3)>=0&&grid[i][j]==0&&grid[i][j-1]==move&&grid[i][j-2]==move&&grid[i][j-3]==move)
	      return (j);
	      if((j-2)>=0&&(j+2)<7&&grid[i][j]==0&&grid[i][j-1]==move&&grid[i][j-2]==move&&grid[i][j+1]==move&&grid[i][j+2]==move)
	        return j;
	         if((j-3)>=0&&(i+3)<6&&grid[i][j]==0&&grid[i+3][j-3]==move&&grid[i+2][j-2]==move&&grid[i+1][j-1]==move)
       return j;
        if((j+3)<7&&(i+3)<6&&grid[i][j]==0&&grid[i+1][j+1]==move&&grid[i+2][j+2]==move&&grid[i+3][j+3]==move)
       return j;
         if((j-2)>=0&&(j+1)<7&&(i-1)>=0&&(i+2)<6&&grid[i][j]==0&&grid[i-1][j+1]==move&&grid[i+2][j-2]==move&&grid[i+1][j-1]==move)
         return j;
        if((j+2)<7&&(j-1)>=0&&(i+2)<6&&(i-1)>=0&&grid[i][j]==0&&grid[i+1][j+1]==move&&grid[i+2][j+2]==move&&grid[i-1][j-1]==move)
        return j;
        if((j-1)>=0&&(j+2)<7&&(i-2)>=0&&(i+1)<6&&grid[i][j]==0&&grid[i-1][j+1]==move&&grid[i-2][j+2]==move&&grid[i+1][j-1]==move)
          return j;
        if((j+1)<7&&(j-2)>=0&&(i+1)<6&&(i-2)>=0&&grid[i][j]==0&&grid[i+1][j+1]==move&&grid[i-2][j-2]==move&&grid[i-1][j-1]==move)
       return j;
        if((j+3)<0&&(j-3)>=0&&grid[i][j]==0&&grid[i-1][j+1]==move&&grid[i-2][j+2]==move&&grid[i-3][j+3]==move)
       return j;
        if((j-3)>=0&&(i-3)>=0&&grid[i][j]==0&&grid[i-3][j-3]==move&&grid[i-2][j-2]==move&&grid[i-1][j-1]==move)
        return j;
        if((j-2)>=0&&(i-2)>=0&&(j+2)<7&&(i+2)<6&&grid[i][j]==0&&grid[i+1][j-1]==move&&grid[i+1][j-2]==move&&grid[i-1][j+1]==move&&grid[i-2][j+2]==move&&grid[i+1][j]!=0)
        return j;
        if((j-2)>=0&&(i-2)>=0&&(j+2)<7&&(i+2)<6&&grid[i][j]==0&&grid[i+1][j+1]==move&&grid[i+1][j+2]==move&&grid[i-1][j-1]==move&&grid[i-2][j-2]==move&&grid[i+1][j]!=0)
        return j;
}


for(i=0;i<6;i++)
for(j=0;j<7;j++)
{
    if(grid[i][j]==0)
    {
        if(grid[i+1][j]!=0&&!(grid[i-1][j+1]==-(move)&&grid[i-1][j+2]==-(move)&&grid[i-1][j+3]==-(move)))
         if(grid[i+1][j]!=0&&!(grid[i-1][j-1]==-(move)&&grid[i-1][j+1]==-(move)&&grid[i-1][j+2]==-(move)))
          if(grid[i+1][j]!=0&&!(grid[i-1][j-2]==-(move)&&grid[i-1][j-1]==-(move)&&grid[i-1][j+1]==-(move)))
           if(grid[i+1][j]!=0&&!(grid[i-1][j-3]==-(move)&&grid[i-1][j-2]==-(move)&&grid[i-1][j-1]==-(move)))
            if(grid[i+1][j]!=0&&!(grid[i-2][j-1]==-(move)&&grid[i-3][j-2]==-(move)&&grid[i-4][j-3]==-(move)))
             if(grid[i+1][j]!=0&&!(grid[i][j+1]==-(move)&&grid[i-2][j-1]==-(move)&&grid[i-3][j-2]==-(move)))
              if(grid[i+1][j]!=0&&!(grid[i][j+1]==-(move)&&grid[i+1][j+2]==-(move)&&grid[i-2][j-1]==-(move)))
               if(grid[i+1][j]!=0&&!(grid[i][j+1]==-(move)&&grid[i+1][j+2]==-(move)&&grid[i+2][j+3]==-(move)))
                if(grid[i+1][j]!=0&&!(grid[i+2][j+1]==-(move)&&grid[i+3][j+2]==-(move)&&grid[i+4][j+3]==-(move)))
                 if(grid[i+1][j]!=0&&!(grid[i][j-1]==-(move)&&grid[i+2][j+1]==-(move)&&grid[i+3][j+2]==-(move)))
                  if(grid[i+1][j]!=0&&!(grid[i][j-1]==-(move)&&grid[i-1][j-2]==-(move)&&grid[i+2][j+1]==-(move)))
                   if(grid[i+1][j]!=0&&!(grid[i][j-1]==-(move)&&grid[i-1][j-2]==-(move)&&grid[i-2][j-3]==-(move)))
                   {
                       if(grid[i-1][j+1]==(move)&&grid[i-1][j+2]==(move)&&grid[i-1][j+3]==(move)) return j;
                       if(grid[i-1][j-1]==(move)&&grid[i-1][j+1]==(move)&&grid[i-1][j+2]==(move)) return j;
                       if(grid[i-1][j-2]==(move)&&grid[i-1][j-1]==(move)&&grid[i-1][j+1]==(move)) return j;
                       if(grid[i-1][j-3]==(move)&&grid[i-1][j-2]==(move)&&grid[i-1][j-1]==(move)) return j;
                       if(grid[i-2][j-1]==(move)&&grid[i-3][j-2]==(move)&&grid[i-4][j-3]==(move)) return j;
                       if(grid[i][j+1]==(move)&&grid[i-2][j-1]==(move)&&grid[i-3][j-2]==(move)) return j;
                       if(grid[i][j+1]==(move)&&grid[i+1][j+2]==(move)&&grid[i+2][j+3]==(move)) return j;
                       if(grid[i+2][j+1]==(move)&&grid[i+3][j+2]==(move)&&grid[i+4][j+3]==(move)) return j;
                       if(grid[i][j-1]==(move)&&grid[i+2][j+1]==(move)&&grid[i+3][j+2]==(move)) return j;
                       if(grid[i][j-1]==(move)&&grid[i-1][j-2]==(move)&&grid[i+2][j+1]==(move)) return j;
                       if(grid[i][j-1]==(move)&&grid[i-1][j-2]==(move)&&grid[i-2][j-3]==(move))return j;
                       if((grid[i][j-1]==(move)&&grid[i][j-2]==(move))||(grid[i][j-1]==(move)&&grid[i][j+1]==(move))||(grid[i][j+1]==(move)&&grid[i][j+2]==(move)))
                        return j;
                       if(grid[i-2][j]==(move)&&grid[i-1][j]==(move))
                        return j;
                       if((grid[i-1][j+1]==(move)&&grid[i-2][j+2]==(move))||(grid[i+1][j-1]==(move)&&grid[i-1][j+1]==(move))||(grid[i+1][j-1]==(move)&&grid[i+2][j-2]==(move)))
                        return j;
                       if((grid[i-1][j-1]==(move)&&grid[i-2][j-2]==(move))||(grid[i-1][j-1]==(move)&&grid[i-+1][j+1]==(move))||(grid[i+1][j+1]==(move)&&grid[i+2][j+2]==(move)))
                       return j;
                   }


    }
}
for(i=0;i<6;i++)
for(j=0;j<7;j++)
{
    if(grid[i][j]==0)
    {
        if(grid[i+1][j]!=0&&!(grid[i-1][j+1]==-(move)&&grid[i-1][j+2]==-(move)&&grid[i-1][j+3]==-(move)))
         if(grid[i+1][j]!=0&&!(grid[i-1][j-1]==-(move)&&grid[i-1][j+1]==-(move)&&grid[i-1][j+2]==-(move)))
          if(grid[i+1][j]!=0&&!(grid[i-1][j-2]==-(move)&&grid[i-1][j-1]==-(move)&&grid[i-1][j+1]==-(move)))
           if(grid[i+1][j]!=0&&!(grid[i-1][j-3]==-(move)&&grid[i-1][j-2]==-(move)&&grid[i-1][j-1]==-(move)))
            if(grid[i+1][j]!=0&&!(grid[i-2][j-1]==-(move)&&grid[i-3][j-2]==-(move)&&grid[i-4][j-3]==-(move)))
             if(grid[i+1][j]!=0&&!(grid[i][j+1]==-(move)&&grid[i-2][j-1]==-(move)&&grid[i-3][j-2]==-(move)))
              if(grid[i+1][j]!=0&&!(grid[i][j+1]==-(move)&&grid[i+1][j+2]==-(move)&&grid[i-2][j-1]==-(move)))
               if(grid[i+1][j]!=0&&!(grid[i][j+1]==-(move)&&grid[i+1][j+2]==-(move)&&grid[i+2][j+3]==-(move)))
                if(grid[i+1][j]!=0&&!(grid[i+2][j+1]==-(move)&&grid[i+3][j+2]==-(move)&&grid[i+4][j+3]==-(move)))
                 if(grid[i+1][j]!=0&&!(grid[i][j-1]==-(move)&&grid[i+2][j+1]==-(move)&&grid[i+3][j+2]==-(move)))
                  if(grid[i+1][j]!=0&&!(grid[i][j-1]==-(move)&&grid[i-1][j-2]==-(move)&&grid[i+2][j+1]==-(move)))
                   if(grid[i+1][j]!=0&&!(grid[i][j-1]==-(move)&&grid[i-1][j-2]==-(move)&&grid[i-2][j-3]==-(move)))
                   {
                       if(grid[i][j-1]==(move)||grid[i][j+1]==(move)||grid[i+1][j+1]==(move)||grid[i+1][j-1]==(move)||grid[i-1][j-1]==(move)||grid[i-1][j+1]==(move))
                    return j;
                       if(grid[i-1][j]==(move))
                      return j;

                   }


    }
}
for(i=0;i<6;i++)
for(j=0;j<7;j++)
{
    if(grid[i][j]==0)
    {
        if(grid[i+1][j]!=0&&!(grid[i-1][j+1]==-(move)&&grid[i-1][j+2]==-(move)&&grid[i-1][j+3]==-(move)))
         if(grid[i+1][j]!=0&&!(grid[i-1][j-1]==-(move)&&grid[i-1][j+1]==-(move)&&grid[i-1][j+2]==-(move)))
          if(grid[i+1][j]!=0&&!(grid[i-1][j-2]==-(move)&&grid[i-1][j-1]==-(move)&&grid[i-1][j+1]==-(move)))
           if(grid[i+1][j]!=0&&!(grid[i-1][j-3]==-(move)&&grid[i-1][j-2]==-(move)&&grid[i-1][j-1]==-(move)))
            if(grid[i+1][j]!=0&&!(grid[i-2][j-1]==-(move)&&grid[i-3][j-2]==-(move)&&grid[i-4][j-3]==-(move)))
             if(grid[i+1][j]!=0&&!(grid[i][j+1]==-(move)&&grid[i-2][j-1]==-(move)&&grid[i-3][j-2]==-(move)))
              if(grid[i+1][j]!=0&&!(grid[i][j+1]==-(move)&&grid[i+1][j+2]==-(move)&&grid[i-2][j-1]==-(move)))
               if(grid[i+1][j]!=0&&!(grid[i][j+1]==-(move)&&grid[i+1][j+2]==-(move)&&grid[i+2][j+3]==-(move)))
                if(grid[i+1][j]!=0&&!(grid[i+2][j+1]==-(move)&&grid[i+3][j+2]==-(move)&&grid[i+4][j+3]==-(move)))
                 if(grid[i+1][j]!=0&&!(grid[i][j-1]==-(move)&&grid[i+2][j+1]==-(move)&&grid[i+3][j+2]==-(move)))
                  if(grid[i+1][j]!=0&&!(grid[i][j-1]==-(move)&&grid[i-1][j-2]==-(move)&&grid[i+2][j+1]==-(move)))
                   if(grid[i+1][j]!=0&&!(grid[i][j-1]==-(move)&&grid[i-1][j-2]==-(move)&&grid[i-2][j-3]==-(move)))
                   {
                       if((grid[i][j-1]==-(move)&&grid[i][j-2]==-(move))||(grid[i][j-1]==-(move)&&grid[i][j+1]==-(move))||(grid[i][j+1]==-(move)&&grid[i][j+2]==-(move)))
                        return j;
                       if(grid[i-2][j]==-(move)&&grid[i-1][j]==-(move))
                        return j;
                       if((grid[i-1][j+1]==-(move)&&grid[i-2][j+2]==-(move))||(grid[i+1][j-1]==-(move)&&grid[i-1][j+1]==-(move))||(grid[i+1][j-1]==-(move)&&grid[i+2][j-2]==-(move)))
                        return j;
                       if((grid[i-1][j-1]==-(move)&&grid[i-2][j-2]==-(move))||(grid[i-1][j-1]==-(move)&&grid[i-+1][j+1]==-(move))||(grid[i+1][j+1]==-(move)&&grid[i+2][j+2]==-(move)))
                        return j;
                       if(grid[i][j-1]==-(move)||grid[i][j+1]==-(move)||grid[i+1][j+1]==-(move)||grid[i+1][j-1]==-(move)||grid[i-1][j-1]==-(move)||grid[i-1][j+1]==-(move))
                         return j;
                       if(grid[i-1][j]==-(move))
                        return j;

                   }


    }
}

do{
j=rand()%7;}while(grid[0][j]!=0);
printf("j= %d ",j);
return j;

	
}

