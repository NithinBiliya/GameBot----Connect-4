//	No errors... Check working for both bots

char botName[50]="Anisha_Anitha";
int bot(int grid[6][7],int move) {
/*int i,j,k,m,n,move2;
	if(move==1)
        move2=-1;
    else
        move2=1;
    for(j=0;j<6;j++)
        for(k=0;k<7;k++)
            {
               if((grid[j][k]==0 && grid[j+1][k]!=0 && j+1<6)||(grid[j][k]==0 && j==5))
                  {                      grid[j][k]=move1;
               for(m=0;m<6;m++)
                  for(n=0;n<7;n++)
                  {

                       if( n-3>=0 && grid[m][n]==grid[m][n-1] && grid[m][n-1] ==grid[m][n-2] && grid[m][n-2]==grid[m][n-3] && grid[m][n-3]==move)
                            {grid[j][k]=0;return k;}
                        else
                        if( n+3<7 && grid[m][n]==grid[m][n+1] && grid[m][n+1]==grid[m][n+2] && grid[m][n+2]==grid[m][n+3] && grid[m][n+3]==move)
                            {grid[j][k]=0;return k;}
                        else
                        if(m+3<6 && grid[m][n]==grid[m+1][n] && grid[m+1][n]==grid[m+2][n] && grid[m+2][n]==grid[m+3][n] && grid[m+3][n]==move)
                            {grid[j][k]=0;return k;}
                        else
                        if( n-3>=0 && m-3>=0 && grid[m][n]==grid[m-1][n-1] && grid[m-1][n-1]==grid[m-2][n-2] && grid[m-2][n-2]==grid[m-3][n-3] && grid[m-3][n-3]==move)
                            {grid[j][k]=0;return k;}
                        else
                        if( m-3>=0 && n+3<7 && grid[m][n]==grid[m-1][n+1] && grid[m-1][n+1]==grid[m-2][n+2] && grid[m-2][n+2]==grid[m-3][n+3] && grid[m-3][n+3]==move)
                            {grid[j][k]=0;return k;}
                        else
                        if(n-3>=0 && m+3<6 && grid[m][n]==grid[m+1][n-1] && grid[m+1][n-1]==grid[m+2][n-2] && grid[m+2][n-2]==grid[m+3][n-3] && grid[m+3][n-3]==move)
                            {grid[j][k]=0;return k;}
                        else
                        if( n+3<7 && m+3<6 && grid[m][n]==grid[m+1][n+1] && grid[m+1][n+1]==grid[m+2][n+2] && grid[m+2][n+2]==grid[m+3][n+3] && grid[m+3][n+3]==move)
                            {grid[j][k]=0;return k;}
                    }



               grid[j][k]=move2;
             for(m=0;m<6;m++)
                 for(n=0;n<7;n++)
                   {
                        if( n-3>=0 && grid[m][n]==grid[m][n-1] && grid[m][n-1]==grid[m][n-2] && grid[m][n-2]==grid[m][n-3] && grid[m][n-3]==move2)
                            {grid[j][k]=0;return k;}
                        else
                        if(n+3<7 && grid[m][n]==grid[m][n+1] && grid[m][n+1]==grid[m][n+2] && grid[m][n+2]==grid[m][n+3] && grid[m][n+3]==move2)
                            {grid[j][k]=0;return k;}
                        else
                        if(m+3<6 && grid[m][n]==grid[m][n+1] && grid[m+1][n]==grid[m+2][n] && grid[m+2][n]==grid[m+3][n] && grid[m+3][n]==move2)
                            {grid[j][k]=0;return k;}
                        else
                        if(m-3>=0 && n-3>=0 && grid[m][n]==grid[m-1][n-1] && grid[m-1][n-1]==grid[m-2][n-2] && grid[m-2][n-2]==grid[m-3][n-3] && grid[m-3][n-3]==move2)
                            {grid[j][k]=0;return k;}
                        else
                        if(m-3>=0 && n+3<7 && grid[m][n]==grid[m-1][n+1] && grid[m-1][n+1]==grid[m-2][n+2] && grid[m-2][n+2]==grid[m-3][n+3] && grid[m-3][n+3]==move2)
                            {grid[j][k]=0;return k;}
                        else
                        if(m+3<6 && n-3>=0 && grid[m][n]==grid[m+1][n-1] && grid[m+1][n-1]==grid[m+2][n-2] && grid[m+2][n-2]==grid[m+3][n-3] && grid[m+3][n-3]==move2)
                            {grid[j][k]=0;return k;}
                        else
                        if(m+3<6 && n+3<7 && grid[m][n]==grid[m+1][n+1] && grid[m+1][n+1]==grid[m+2][n+2] && grid[m+2][n+2]==grid[m+3][n+3] && grid[m+3][n+3]==move2)
                            {grid[j][k]=0;return k;}
                    }


    grid[j][k]=move;
    for(m=0;m<6;m++)
        for(n=0;n<7;n++)
        {
           if(grid[m][n]==0 && grid[m+1][n]!=0 && m+1<6)

                      {

                        if((m>=0 && n-3>=0 && grid[m][n-1]==grid[m][n-2] && grid[m][n-2]==grid[m][n-3] && grid[m][n-3]==move2)||(grid[m][n-1]==grid[m][n-2] && grid[m][n-2]==grid[m][n+1] &&grid[m][n+1]==move2))
                            {grid[j][k]=0;break;}
                        else
                        if((m>=0 && n+3<7 && grid[m][n+1]==grid[m][n+2] && grid[m][n+2]==grid[m][n+3] && grid[m][n+3]==move2)||(grid[m][n-1]==grid[m][n-2] && grid[m][n-2]==grid[m][n+1] &&grid[m][n+1]==move2))
                            {grid[j][k]=0;break;}
                        else
                        if(m+3<6 && grid[m+1][n]==grid[m+2][n] && grid[m+2][n]==grid[m+3][n] && grid[m+3][n]==move2)
                            {grid[j][k]=0;break;}
                        else
                        if((m-3>=0 && n-3>=0 && grid[m-1][n-1]==grid[m-2][n-2] && grid[m-2][n-2]==grid[m-3][n-3] && grid[m-3][n-3]==move2)||(grid[m-1][n-1]==grid[m-2][n-2] && grid[m-2][n-2]==grid[m+1][n+1]&&grid[m+1][n+1]==move2))
                            {grid[j][k]=0;break;}
                        else
                        if((m-3>=0 && n+3<7 && grid[m-1][n+1]==grid[m-2][n+2] && grid[m-2][n+2]==grid[m-3][n+3] && grid[m-3][n+3]==move2)||(grid[m-1][n+1]==grid[m-2][n+2] && grid[m-2][n+2]==grid[m+1][n-1] &&grid[m+1][n-1]==move2))
                            {grid[j][k]=0;break;}
                        else
                        if((m+3<6 && n-3>=0 && grid[m+1][n-1]==grid[m+2][n-2] && grid[m+2][n-2]==grid[m+3][n-3] && grid[m+3][n-3]==move2)||(grid[m+1][n-1]==grid[m+2][n-2] && grid[m+2][n-2]==grid[m-1][n+1] &&grid[m-1][n+1]==move2))
                            {grid[j][k]=0;break;}
                        else
                        if((m+3<6 && n+3<7 && grid[m+1][n+1]==grid[m+2][n+2] && grid[m+2][n+2]==grid[m+3][n+3] && grid[m+3][n+3]==move2)||(grid[m+1][n-1]==grid[m+2][n-2] && grid[m+2][n-2]==grid[m-1][n-1] &&grid[m-1][n-1]==move2))
                            {grid[j][k]=0;break;}


                        }

        }
            }}
do {
		i=rand()%7;
	}while(grid[0][i]!=0);		//	Condition to check whether the randomly selected column is full
	return i;*/
	int j,k,m,n,flag=-1,move2;
	if(move==1)
        move2=-1;
    else
        move2=1;
    for(j=0;j<6;j++)
    {
        for(k=0;k<7;k++)
        {
            if((grid[j][k]==0 && grid[j+1][k]!=0 && j+1<6)||(grid[j][k]==0 && j==5))
            {
            grid[j][k]=move;
            for(m=0;m<6;m++)
            for(n=0;n<7;n++)

            {
                if(grid[m][n]==grid[m][n-1]&& grid[m][n-1]==grid[m][n-2] && grid[m][n-1]==grid[m][n-3] && grid[m][n-3]==move && n-3>=0)
                {
                    grid[j][k]=0;
                    return k;
                }
                 else   if(grid[m][n]==grid[m][n+1]&& grid[m][n+1]==grid[m][n+2] && grid[m][n+1]==grid[m][n+3] && grid[m][n+3]==move && n+3<7)
                    {
                        grid[j][k]=0;
                        return k;
                    }
               else     if(grid[m][n]==grid[m+1][n]&& grid[m+1][n]==grid[m+2][n] && grid[m+1][n]==grid[m+3][n] && grid[m+1][n]==move && m+3<6)
                    {
                        grid[j][k]=0;
                        return k;
                    }
               else     if(grid[m][n]==grid[m-1][n-1]&& grid[m-1][n-1]==grid[m-2][n-2] && grid[m-1][n-1]==grid[m-3][n-3] && grid[m-3][n-3]==move && m-3>=0 && n-3>=0)
                    {
                        grid[j][k]=0;
                        return k;
                    }
               else     if(grid[m][n]==grid[m-1][n+1]&& grid[m-1][n+1]==grid[m-2][n+2] && grid[m-1][n+1]==grid[m-3][n+3] && grid[m-3][n+3]==move && m-3>=0 && n+3<7)
                    {
                        grid[j][k]=0;
                        return k;
                    }
               else     if(grid[m][n]==grid[m+1][n-1]&& grid[m+1][n-1]==grid[m+2][n-2] && grid[m+1][n-1]==grid[m+3][n-3] && grid[m+3][n-3]==move && m+3<6 && n-3>=0)
                    {
                        grid[j][k]=0;
                        return k;
                    }
               else     if(grid[m][n]==grid[m+1][n+1]&& grid[m+1][n+1]==grid[m+2][n+2] && grid[m+1][n+1]==grid[m+3][n+3] && grid[m+3][n+3]==move && m+3<6 && n+3<7)
                    {
                        grid[j][k]=0;
                        return k;
                    }
            }
            grid[j][k]=move2;
            for(m=0;m<6;m++)
            for(n=0;n<7;n++)

            {
                if(grid[m][n]==grid[m][n-1]&& grid[m][n-1]==grid[m][n-2] && grid[m][n-1]==grid[m][n-3] && grid[m][n-3]==move2 && n-3>=0)
                {
                    grid[j][k]=0;
                    return k;
                }
                    if(grid[m][n]==grid[m][n+1]&& grid[m][n+1]==grid[m][n+2] && grid[m][n+1]==grid[m][n+3] && grid[m][n+3]==move2 && n+3<7)
                    {
                        grid[j][k]=0;
                        return k;
                    }
                    if(grid[m][n]==grid[m+1][n]&& grid[m+1][n]==grid[m+2][n] && grid[m+1][n]==grid[m+3][n] && grid[m+1][n]==move2 && m+3<6)
                    {
                        grid[j][k]=0;
                        return k;
                    }
                    if(grid[m][n]==grid[m-1][n-1]&& grid[m-1][n-1]==grid[m-2][n-2] && grid[m-1][n-1]==grid[m-3][n-3] && grid[m-3][n-3]==move2 && m-3>=0 && n-3>=0)
                    {
                        grid[j][k]=0;
                        return k;
                    }
                    if(grid[m][n]==grid[m-1][n+1]&& grid[m-1][n+1]==grid[m-2][n+2] && grid[m-1][n+1]==grid[m-3][n+3] && grid[m-3][n+3]==move2 && m-3>=0 && n+3<7)
                    {
                        grid[j][k]=0;
                        return k;
                    }
                    if(grid[m][n]==grid[m+1][n-1]&& grid[m+1][n-1]==grid[m+2][n-2] && grid[m+1][n-1]==grid[m+3][n-3] && grid[m+3][n-3]==move2 && m+3<6 && n-3>=0)
                    {
                        grid[j][k]=0;
                        return k;
                    }
                    if(grid[m][n]==grid[m+1][n+1]&& grid[m+1][n+1]==grid[m+2][n+2] && grid[m+1][n+1]==grid[m+3][n+3] && grid[m+3][n+3]==move2 && m+3<6 && n+3<7)
                    {
                        grid[j][k]=0;
                        return k;
                    }
            }
            grid[j][k]=move;
            for(m=0;m<6;m++)
            for(n=0;n<7;n++)
            if(grid[m][n]==0 && grid[m+1][n]!=0 && m+1<6)
            {
                if((grid[m][n-1]==grid[m][n-2] && grid[m][n-1]==grid[m][n-3] && grid[m][n-3]==move2 && n-3>=0)||(grid[m][n-1]==grid[m][n-2] && grid[m][n-1]==grid[m][n+1] && grid[m][n-1]==-1 && n-2>=0 && n+1<7))
                {
                    grid[j][k]=0;
                    flag=k;
                    break;
                }
                    if((grid[m][n+1]==grid[m][n+2] && grid[m][n+1]==grid[m][n+3] && grid[m][n+3]==move2 && n+3<7)||(grid[m][n-1]==grid[m][n+2] && grid[m][n+1]==grid[m][n+2] && grid[m][n-1]==-1 && n-1>=0 && n+2<7))
                    {
                        grid[j][k]=0;
                        flag=k;
                        break;
                    }
                    if(grid[m+1][n]==grid[m+2][n] && grid[m+1][n]==grid[m+3][n] && grid[m+1][n]==move2 && m+3<6)
                    {
                        grid[j][k]=0;
                        flag=k;
                        break;
                    }
                    if((grid[m-1][n-1]==grid[m-2][n-2] && grid[m-1][n-1]==grid[m-3][n-3] && grid[m-3][n-3]==move2 && m-3>=0 && n-3>=0)||(grid[m-1][n-1]==grid[m-2][n-2] && grid[m-1][n-1]==grid[m+1][n+1] && grid[m-2][n-2]==-1 && n-2>=0 && n+1<7 && m-2>=0 && m+1<6))
                    {
                        grid[j][k]=0;
                        flag=k;
                        break;
                    }
                    if((grid[m-1][n+1]==grid[m-2][n+2] && grid[m-1][n+1]==grid[m-3][n+3] && grid[m-3][n+3]==move2 && m-3>=0 && n+3<7)||(grid[m+1][n-1]==grid[m-2][n+2] && grid[m+1][n-1]==grid[m-1][n+1] && grid[m-2][n+2]==-1 && n-1>=0 && n+2<7 && m-2>=0 && m+1<6))
                    {
                        grid[j][k]=0;
                        flag=k;
                        break;
                    }
                    if((grid[m+1][n-1]==grid[m+2][n-2] && grid[m+1][n-1]==grid[m+3][n-3] && grid[m+3][n-3]==move2 && m+3<6 && n-3>=0)||(grid[m-1][n+1]==grid[m+2][n-2] && grid[m-1][n+1]==grid[m+1][n-1] && grid[m+2][n-2]==-1 && n-2>=0 && n+1<7 && m-1>=0 && m+2<6))
                    {
                        grid[j][k]=0;
                        flag=k;
                        break;
                    }
                    if((grid[m+1][n+1]==grid[m+2][n+2] && grid[m+1][n+1]==grid[m+3][n+3] && grid[m+3][n+3]==move2 && m+3<6 && n+3<7)||(grid[m-1][n-1]==grid[m+2][n+2] && grid[m-1][n-1]==grid[m+1][n+1] && grid[m+2][n+2]==-1 && n-1>=0 && n+2<7 && m-1>=0 && m+2<6))
                    {
                        grid[j][k]=0;
                        flag=k;
                        break;
                    }
            }
            grid[j][k]=0;
            }
        }
    }
    do
    {
        k=rand()%7;
    }while(grid[0][k]!=0 && flag!=k);
    return k;

}
