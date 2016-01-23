//	Correct for both bots

int fin4(int grid1[6][7],int move,int fin,int row,int col,int i,int j)
{
int f,c,x,y;
int grid[6][7],i1,j1;
for(i1=0;i1<6;i1++)
 
   for(j1=0;j1<7;j1++)
    {
        grid[i1][j1]=grid1[i1][j1];
     
    }
    if(col!=-1)
	grid[row][col]=move;
		//check if conn 4
			//verical
			if(j>=3)
				if(((grid[j-1][i]==move)&&(grid[j-2][i]==move))&&(grid[j-3][i]==move))
					if(fin) {return i;} else fin=1;
			
			//horizontal
			if(i>=3)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i-3]==move))
			if(fin) {return i;}else fin=1;

			if(i>=2&&i<=5)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i+1]==move))
			if(fin) {return i;}else fin=1;

			if(i>=1&&i<=4)
			if((grid[j][i-1]==move)&&(grid[j][i+1]==move)&&(grid[j][i+2]==move))
			if(fin) {return i;}else fin=1;

			if(i<=3)
			if((grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(grid[j][i+3]==move))
			if(fin) {return i;}else fin=1;
			
			//diagonal
			//right
			for(x=j-1,y=i-1,c=0,f=1;(x>=0&&y>=0)&&f==1;x=x-1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			if(fin) {return i;}else fin=1;
			}

			for(x=j+1,y=i+1,f=1;x<=5&&y<=6&&f==1;x=x+1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				if(fin) {return i;}else fin=1;
			}
			//left
			for(x=j+1,y=i-1,c=0,f=1;x<=5&&y>=0&&f==1;x=x+1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			if(fin) {return i;}else fin=1;
			}

			for(x=j-1,y=i+1,f=1;x>=0&&y<=6&&f==1;x=x-1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				if(fin) {return i;}else fin=1;
			}
return -1;

}



int fin42(int grid1[6][7],int move,int fin,int row,int col,int fut,int *r)
{
int f,c,x,y,i,j;
int grid[6][7],i1,j1;
for(i1=0;i1<6;i1++)
 
   for(j1=0;j1<7;j1++)
    {
        grid[i1][j1]=grid1[i1][j1];
     
    }
	if(col!=-1)
	grid[row][col]=move;
		//check if conn 4


for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		

			//verical
			if(j>=3)
				if((grid[j-1][i]==move)&&(grid[j-2][i]==move)&&(grid[j-3][i]==move))
					if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}
			
			//horizontal
			if(i>=3)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i-3]==move))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}

			if(i>=2&&i<=5)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i+1]==move))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}

			if(i>=1&&i<=4)
			if((grid[j][i-1]==move)&&(grid[j][i+1]==move)&&(grid[j][i+2]==move))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}

			if(i<=3)
			if((grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(grid[j][i+3]==move))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}
			
			//diagonal
			//right
			for(x=j-1,y=i-1,c=0,f=1;x>=0&&y>=0&&f==1;x=x-1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}
			if(c!=3)
			for(x=j+1,y=i+1, 1;x<=5&&y<=6&&f==1;x=x+1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}
			//left
			if(fin!=2)
				{
			for(x=j+1,y=i-1,c=0,f=1;x<=5&&y>=0&&f==1;x=x+1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}
			if(c!=3)
			for(x=j-1,y=i+1,f=1;x>=0&&y<=6&&f==1;x=x-1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}}if(!fut) break;
}}}
if(fin==2)
{


for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{


			//verical
			if(j>=3)
				if((grid[j-1][i]==move)&&(grid[j-2][i]==move)&&(grid[j-3][i]==move))
					 {*r=j; return i;} 
			
			//horizontal
			if(i>=3)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i-3]==move))
			{*r=j; return i;} 

			if(i>=2&&i<=5)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i+1]==move))
			{*r=j; return i;} 

			if(i>=1&&i<=4)
			if((grid[j][i-1]==move)&&(grid[j][i+1]==move)&&(grid[j][i+2]==move))
			{*r=j; return i;} 

			if(i<=3)
			if((grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(grid[j][i+3]==move))
			{*r=j; return i;} 
			
			//diagonal
			//right
			for(x=j-1,y=i-1,c=0,f=1;x>=0&&y>=0&&f==1;x=x-1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			{*r=j; return i;} 
			}

			for(x=j+1,y=i+1,f=1;x<=5&&y<=6&&f==1;x=x+1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				{*r=j; return i;} 
			}
			//left
			for(x=j+1,y=i-1,c=0,f=1;x<=5&&y>=0&&f==1;x=x+1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			{*r=j; return i;} 
			}

			for(x=j-1,y=i+1,f=1;x>=0&&y<=6&&f==1;x=x-1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				{*r=j; return i;} 
			}if(!fut) break;
}}}
	
}	
	
	
	
	
	return -1;

}









int fin42o(int grid1[6][7],int move,int fin,int row,int col,int fut,int *r)
{
int f,c,x,y,i,j;
int grid[6][7],i1,j1,moveo;
moveo=-move;
for(i1=0;i1<6;i1++)
 
   for(j1=0;j1<7;j1++)
    {
        grid[i1][j1]=grid1[i1][j1];
     
    }
	if(col!=-1)
	grid[row][col]=moveo;
		//check if conn 4


for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{


			//verical
			if(j>=3)
				if((grid[j-1][i]==move)&&(grid[j-2][i]==move)&&(grid[j-3][i]==move))
					if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}
			
			//horizontal
			if(i>=3)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i-3]==move))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}

			if(i>=2&&i<=5)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i+1]==move))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}

			if(i>=1&&i<=4)
			if((grid[j][i-1]==move)&&(grid[j][i+1]==move)&&(grid[j][i+2]==move))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}

			if(i<=3)
			if((grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(grid[j][i+3]==move))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}
			
			//diagonal
			//right
			for(x=j-1,y=i-1,c=0,f=1;x>=0&&y>=0&&f==1;x=x-1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}
			if(c!=3)
			for(x=j+1,y=i+1, 1;x<=5&&y<=6&&f==1;x=x+1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}
		if(fin!=2)
		{
			//left
			for(x=j+1,y=i-1,c=0,f=1;x<=5&&y>=0&&f==1;x=x+1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}
			if(c!=3)
			for(x=j-1,y=i+1,f=1;x>=0&&y<=6&&f==1;x=x-1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}
		}if(!fut) break;
}}}
if(fin==2)
{


for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{


			//verical
			if(j>=3)
				if((grid[j-1][i]==move)&&(grid[j-2][i]==move)&&(grid[j-3][i]==move))
					 {*r=j; return i;} 
			
			//horizontal
			if(i>=3)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i-3]==move))
			{*r=j; return i;} 

			if(i>=2&&i<=5)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i+1]==move))
			{*r=j; return i;} 

			if(i>=1&&i<=4)
			if((grid[j][i-1]==move)&&(grid[j][i+1]==move)&&(grid[j][i+2]==move))
			{*r=j; return i;} 

			if(i<=3)
			if((grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(grid[j][i+3]==move))
			{*r=j; return i;} 
			
			//diagonal
			//right
			for(x=j-1,y=i-1,c=0,f=1;x>=0&&y>=0&&f==1;x=x-1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			{*r=j; return i;} 
			}

			for(x=j+1,y=i+1,f=1;x<=5&&y<=6&&f==1;x=x+1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				{*r=j; return i;} 
			}
			//left
			for(x=j+1,y=i-1,c=0,f=1;x<=5&&y>=0&&f==1;x=x+1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			{*r=j; return i;} 
			}

			for(x=j-1,y=i+1,f=1;x>=0&&y<=6&&f==1;x=x-1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				{*r=j; return i;} 
			}if(!fut) break;
}}}
	
}	
	
	
	
	
	return -1;

}








int fin42f(int grid1[6][7],int move,int fin,int row,int col,int fut,int *r)
{
int f,c,x,y,i,v,j,row1,col1;
int grid[6][7],i1,j1;
for(i1=0;i1<6;i1++)
 
   for(j1=0;j1<7;j1++)
    {
        grid[i1][j1]=grid1[i1][j1];
     
    }
	if(col!=-1)
	grid[row][col]=move;
		//check if conn 4


for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{


			//verical
			if(j>=3&&i==col)
				if((grid[j-1][i]==move)&&(grid[j-2][i]==move)&&(grid[j-3][i]==move)&&((row>=j-3)&&(row<=j-1)))
					if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;row1=j;col1=i;}
			
			//horizontal
			if(j==row)
				{
			if(i>=3)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i-3]==move)&&(((i-1)==col)||((i-2)==col)||((i-3)==col)))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;row1=j;col1=i;}

			if(i>=2&&i<=5)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i+1]==move)&&(((i-1)==col)||((i-2)==col)||((i+1)==col)))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;row1=j;col1=i;}

			if(i>=1&&i<=4)
			if((grid[j][i-1]==move)&&(grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(((i-1)==col)||((i+1)==col)||((i+2)==col)))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;row1=j;col1=i;}

			if(i<=3)
			if((grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(grid[j][i+3]==move)&&(((i+1)==col)||((i+2)==col)||((i+3)==col)))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;row1=j;col1=i;}
				}
			//diagonal
			//right
			for(x=j-1,y=i-1,c=0,v=0,f=1;x>=0&&y>=0&&f==1;x=x-1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else {if(x==row&&y==col) v=1;c++;}

			if(c==3&&v==1)
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;row1=j;col1=i;break;}
			}
			if(c!=3)
			for(x=j+1,y=i+1,f=1;x<=5&&y<=6&&f==1;x=x+1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else {if(x==row&&y==col) v=1;c++;}

				if(c==3&&v==1)
				if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;row1=j;col1=i;break;}
			}
			//left
				if(fin!=2)
				{
			for(x=j+1,y=i-1,c=0,v=0,f=1;x<=5&&y>=0&&f==1;x=x+1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else {if(x==row&&y==col) v=1;c++;}

			if(c==3&&v==1)
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;row1=j;col1=i;break;}
			}
			if(c!=3)
			for(x=j-1,y=i+1,f=1;x>=0&&y<=6&&f==1;x=x-1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else {if(x==row&&y==col) v=1;c++;}

				if(c==3&&v==1)
				if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;row1=j;col1=i;break;}
			}}if(!fut) break;
}}}
if(fin==2)
{
v=0;

for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{


			//verical
			if(j>=3&&i==col1)
				if((grid[j-1][i]==move)&&(grid[j-2][i]==move)&&(grid[j-3][i]==move)&&((row1>=j-3)&&(row1<=j-1)))
					if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}
			
			//horizontal
			if(j==row1)
				{
			if(i>=3)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i-3]==move)&&(((i-1)==col1)||((i-2)==col1)||((i-3)==col1)))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}

			if(i>=2&&i<=5)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i+1]==move)&&(((i-1)==col1)||((i-2)==col1)||((i+1)==col1)))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}

			if(i>=1&&i<=4)
			if((grid[j][i-1]==move)&&(grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(((i-1)==col1)||((i+1)==col1)||((i+2)==col1)))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}

			if(i<=3)
			if((grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(grid[j][i+3]==move)&&(((i+1)==col1)||((i+2)==col1)||((i+3)==col1)))
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;}
				}
			//diagonal
			//right
			for(x=j-1,y=i-1,c=0,v=0,f=1;x>=0&&y>=0&&f==1;x=x-1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else {if(x==row1&&y==col1) v=1;c++;}

			if(c==3&&v==1)
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}
			if(c!=3)
			for(x=j+1,y=i+1,f=1;x<=5&&y<=6&&f==1;x=x+1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else {if(x==row1&&y==col1) v=1;c++;}

				if(c==3&&v==1)
				if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}
			//left
					if(fin!=2)
					{
			for(x=j+1,y=i-1,c=0,v=0,f=1;x<=5&&y>=0&&f==1;x=x+1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else {if(x==row1&&y==col1) v=1;c++;}

			if(c==3&&v==1)
			if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}
			if(c!=3)
			for(x=j-1,y=i+1,f=1;x>=0&&y<=6&&f==1;x=x-1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else {if(x==row1&&y==col1) v=1;c++;}

				if(c==3&&v==1)
				if(fin) {*r=j; return i;} else {fin=2;grid[j][i]=-move;break;}
			}}if(!fut) break;
}}}






for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{


			//verical
			if(j>=3)
				if((grid[j-1][i]==move)&&(grid[j-2][i]==move)&&(grid[j-3][i]==move))
					 {*r=j; return i;} 
			
			//horizontal
			if(i>=3)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i-3]==move))
			{*r=j; return i;} 

			if(i>=2&&i<=5)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i+1]==move))
			{*r=j; return i;} 

			if(i>=1&&i<=4)
			if((grid[j][i-1]==move)&&(grid[j][i+1]==move)&&(grid[j][i+2]==move))
			{*r=j; return i;} 

			if(i<=3)
			if((grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(grid[j][i+3]==move))
			{*r=j; return i;} 
			
			//diagonal
			//right
			for(x=j-1,y=i-1,c=0,f=1;x>=0&&y>=0&&f==1;x=x-1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			{*r=j; return i;} 
			}

			for(x=j+1,y=i+1,f=1;x<=5&&y<=6&&f==1;x=x+1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				{*r=j; return i;} 
			}
			//left
			for(x=j+1,y=i-1,c=0,f=1;x<=5&&y>=0&&f==1;x=x+1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			{*r=j; return i;} 
			}

			for(x=j-1,y=i+1,f=1;x>=0&&y<=6&&f==1;x=x-1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				{*r=j; return i;} 
			} break;
}}}
	
}	
	
	
	
	
	return -1;

}













int fin43(int grid1[6][7],int move,int fin,int row,int col,int fut,int *r)
{
int f,c,x,y,i,j;
int grid[6][7],i1,j1;
for(i1=0;i1<6;i1++)
 
   for(j1=0;j1<7;j1++)
    {
        grid[i1][j1]=grid1[i1][j1];
     
    }
	if(col!=-1)
	grid[row][col]=move;
		//check if conn 4


for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{


			//verical
			if(j>=3)
				if((grid[j-1][i]==move)&&(grid[j-2][i]==move)&&(grid[j-3][i]==move))
					if(fin) {*r=j; return i;} else {fin=1;grid[j][i]=-move;}
			
			//horizontal
			if(i>=3)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i-3]==move))
			if(fin) {*r=j; return i;} else {fin=1;grid[j][i]=-move;}

			if(i>=2&&i<=5)
			if((grid[j][i-1]==move)&&(grid[j][i-2]==move)&&(grid[j][i+1]==move))
			if(fin) {*r=j; return i;} else {fin=1;grid[j][i]=-move;}

			if(i>=1&&i<=4)
			if((grid[j][i-1]==move)&&(grid[j][i+1]==move)&&(grid[j][i+2]==move))
			if(fin) {*r=j; return i;} else {fin=1;grid[j][i]=-move;}

			if(i<=3)
			if((grid[j][i+1]==move)&&(grid[j][i+2]==move)&&(grid[j][i+3]==move))
			if(fin) {*r=j; return i;} else {fin=1;grid[j][i]=-move;}
			
			//diagonal
			//right
			for(x=j-1,y=i-1,c=0,f=1;x>=0&&y>=0&&f==1;x=x-1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			if(fin) {*r=j; return i;} else {fin=1;grid[j][i]=-move;}
			}

			for(x=j+1,y=i+1,f=1;x<=5&&y<=6&&f==1;x=x+1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				if(fin) {*r=j; return i;} else {fin=1;grid[j][i]=-move;}
			}
			//left
			for(x=j+1,y=i-1,c=0,f=1;x<=5&&y>=0&&f==1;x=x+1,y=y-1)
			{
			if(grid[x][y]!=move) f=0; else c++;

			if(c==3)
			if(fin) {*r=j; return i;} else {fin=1;grid[j][i]=-move;}
			}

			for(x=j-1,y=i+1,f=1;x>=0&&y<=6&&f==1;x=x-1,y=y+1)
			{
			if(grid[x][y]!=move) f=0; else c++;

				if(c==3)
				if(fin) {*r=j; return i;} else {fin=1;grid[j][i]=-move;}
			}if(!fut) break;
}}}return -1;

}


int fin44(int grid1[6][7],int move,int j,int i)
{
int r,fin,finc,fino;
int grid[6][7],i1,j1;
for(i1=0;i1<6;i1++)
 
   for(j1=0;j1<7;j1++)
    {
        grid[i1][j1]=grid1[i1][j1];
     
    }
grid[j][i]=move;
for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		fin=fin42(grid,move,1,j,i,0,&r);
		if(fin!=-1)
		{
		finc=fin42(grid,move,0,j,i,0,&r);
		fino=fin42o(grid,-move,1,j,i,0,&r);
		if(fino==-1&&finc!=-1)
			return 1;}
break;
}}}
return 0;
}

char botName[50]="Sudhindra";
int bot(int grid[6][7],int move)
{

int myst=1;
//int pri[7]={1,2,3,4,3,2,1};
int r,c,r1,r2,c1,c3,i,ni,j,k,q,ni2,f=0;
int fin,finc,fino,tp1,tp,dp,fino2,dp1,i1,j1,tc,grid1[6][7];
//int moveo=move*(-1);
for(i=0;i<7;i++)
if(grid[0][i]!=0)
	myst=0;

if(myst)
return 3;
for(i=0;i<6;i++)
 
   for(j=0;j<7;j++)
    {
        grid1[i][j]=grid[i][j];
     
    }
for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
				
		fin=fin4(grid,move,1,-1,-1,i,j);
		if(fin!=-1)
			{return i;}
break;}}}

for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{	

		
		fino=fin4(grid,-move,1,-1,-1,i,j);
		if(fino!=-1)
			{return i;}
break;
}}}
		


for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		fin=fin42(grid1,move,1,j,i,0,&r);
		if(fin!=-1)
		{
		fino=fin42o(grid1,-move,1,j,i,0,&r);
		finc=fin42(grid1,move,0,j,i,0,&r);
		
		if(fino==-1&&finc!=-1)
			{return i;}}
break;
}}}
		
for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		fin=fin42(grid1,-move,1,j,i,0,&r);
		if(fin!=-1)
		{
		finc=fin42(grid1,-move,0,j,i,0,&r);
					
		fino=fin42o(grid1,move,1,j,i,0,&r);
				
		if(fino==-1&&finc!=-1)
			{return i;}}
break;
}}}




if(f)

{
	for(j=0;j<6;j++)
	{
		if(grid[j][c1]==0)
		{
		fin=fin4(grid,-move,1,-1,-1,c1,j+1);
		if(fin==-1)
		{return c1;}
		else
		break;
		}
	}


}













		
		
r1=99;c1=-1;tp1=0;
for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		//fin=fin42(grid[6][7],move,1,j,i,0);
		
		//fino=fin42(grid[6][7],move,1,j,i,0);
		//if(fino==-1&&fin==-1)
		//{
		fino=fin42o(grid1,-move,1,j,i,0,&r);
		if(fino==-1)
		{
		c=fin42f(grid1,move,1,j,i,1,&r);r2=r;
		if(c!=-1)
		{
		finc=fin42f(grid1,move,0,j,i,1,&r);
		if(finc!=-1&&r1>r2)
		{	
			for(k=0;k<r2;k++)
			{
			tp=1;
			if(grid[k][c]==0)
				{
			fin=fin4(grid,-move,1,-1,-1,c,k);
			if(fin!=-1)
			{tp=0;break;}
				}
			}
			if(tp>=tp1){tp1=tp;
			f=1;ni=i;
			r1=r2;
			c1=c;}	
		}
		}
		}

break;
		}
	}
}
if(c1!=-1)
{return ni;}




r1=99;c1=-1;tp1=0;
for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{

		fino=fin42o(grid1,-move,1,j,i,0,&r);
		if(fino==-1)
		{
		c=fin42f(grid1,move,1,j,i,1,&r);
		r2=r;
		if(c!=-1)
		{
		fin=fin4(grid,move,1,-1,-1,c,r-1);
		if(finc!=-1&&r1>r2)
		{	
			for(k=0;k<r2;k++)
			{
			tp=1;
			if(grid[k][c]==0)
				{
			fin=fin4(grid,-move,1,-1,-1,c,k);
			if(fin!=-1)
			{tp=0;break;}
				}
			}
			if(tp>=tp1){tp1=tp;
			f=1;ni=i;
			r1=r2;
			c1=c;	}
		}}
		}

break;
		}
	}
}
if(c1!=-1)
{return ni;}	


	
		

r1=99;c1=-1;tp1=0;
for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		
		fino=fin42o(grid1,-move,1,j,i,0,&r);
		if(fino==-1)
		{
		q=fin42(grid1,move,1,j,i,0,&r);
		c=fin42f(grid1,move,1,j,i,1,&r);
		
		
		if(q==-1&&c!=-1&&r1>r)
		{	
			for(k=0;k<r;k++)
			{
			tp=1;
			if(grid[k][c]==0)
				{
				fin=fin4(grid,-move,1,-1,-1,c,k);
				if(fin!=-1)
					{tp=0;break;}
				}
			}
			if(tp>=tp1){tp1=tp;
			ni=i;
			r1=r;
			c1=c;}	
		}
		}

break;
		}
	}
}
if(c1!=-1)
{return ni;}





r1=99;c1=-1;tp1=0;
for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		
		fino=fin42o(grid1,move,1,j,i,0,&r);
		if(fino==-1)
		{
		q=fin42(grid1,-move,1,j,i,0,&r);
		c=fin42f(grid1,-move,1,j,i,1,&r);
		
		
		if(q==-1&&c!=-1&&r1>r)
		{	
			for(k=0;k<r;k++)
			{
			tp=1;
			if(grid[k][c]==0)
				{
				fin=fin4(grid,move,1,-1,-1,c,k);
				if(fin!=-1)
					{tp=0;break;}
				}
			}
			if(tp>=tp1){tp1=tp;
			ni=i;
			r1=r;
			c1=c;}	
		}
		}

break;
		}
	}
}
if(c1!=-1)
{return ni;}






c3=-1;
for(i=3,k=3;i<7&&k>=0;i++,k--)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		fin=fin42(grid1,move,1,j,i,0,&r);
		
		fino=fin42o(grid1,-move,1,j,i,0,&r);
		if(fino==-1&&fin==-1)
			{
			if(fin44(grid1,move,j,i))
				if(c3==-1)
					c3=i;
				//else
				//if(pri[i]>pri[c3])
					//c3=i;
			}
break;
		}
	}
if(c3!=-1)
{return c3;}
	for(j=0;j<6;j++)
	{
		if(grid[j][k]==0)
		{
		fin=fin42(grid1,move,1,j,k,0,&r);
		
		fino=fin42o(grid1,-move,1,j,k,0,&r);
		if(fino==-1&&fin==-1)
			{
			if(fin44(grid1,move,j,k))
				if(c3==-1)
					c3=k;
				//else
				//if(pri[i]>pri[c3])
					//c3=k;
			}
break;
		}

	}
if(c3!=-1)
{return c3;}
}




r1=99;c1=-1;tp1=0;
for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		//fin=fin42(grid[6][7],move,1,j,i,0);
		
		//fino=fin42(grid[6][7],move,1,j,i,0);
		//if(fino==-1&&fin==-1)
		//{
		fino=fin42o(grid1,move,1,j,i,0,&r);
		if(fino==-1)
		{
		c=fin42f(grid1,-move,1,j,i,1,&r);r2=r;
		if(c!=-1)
		{
		finc=fin42f(grid1,-move,0,j,i,1,&r);
		if(finc!=-1&&r1>r2)
		{	
			for(k=0;k<r2;k++)
			{
			tp=1;
			if(grid[k][c]==0)
				{
			fin=fin4(grid,move,1,-1,-1,c,k);
			if(fin!=-1)
			{tp=0;break;}
				}
			}
			if(tp>=tp1){tp1=tp;
			ni=i;
			r1=r2;
			c1=c;}	
		}
		}
		}

break;
		}
	}
}
if(c1!=-1)
{return ni;}




c3=-1;
for(i=3,k=3;i<7&&k>=0;i++,k--)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		fin=fin42(grid1,move,1,j,i,0,&r);
		
		fino=fin42o(grid1,-move,1,j,i,0,&r);
		if(fino==-1&&fin==-1)
			{
			//if(fin44(grid[6][7],move,j,i))
				if(c3==-1)
					c3=i;
				//else
				//if(pri[i]>pri[c3])
					//c3=i;
			}
		break;
		}
	}
if(c3!=-1)
{return c3;}
	for(j=0;j<6;j++)
	{
		if(grid[j][k]==0)
		{
		fin=fin42(grid1,move,1,j,k,0,&r);
		
		fino=fin42o(grid1,-move,1,j,k,0,&r);
		if(fino==-1&&fin==-1)
			{
			//if(fin44(grid[6][7],move,j,k))
				if(c3==-1)
					c3=k;
				//else
				//if(pri[i]>pri[c3])
					//c3=k;
			}
break;
		}

	}
if(c3!=-1)
{return c3;}
}



dp1=0;ni2=-1;
for(i=0;i<7;i++)
{dp=0;
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{
		fin=fin42(grid1,move,1,j,i,0,&r);
		
		fino=fin42o(grid1,-move,1,j,i,0,&r);
		if(fino==-1&&fin!=-1)
			{
						for(i1=0;i1<7;i1++)
						{
							if(i1==i) continue;
							for(j1=0;j1<6;j1++)
							{
								if(grid[j1][i1]==0)
								{
									fino=fin42o(grid1,-move,1,j,i,0,&r);
									if(fino!=-1)
										tc++;
									else
										break;
								}
							}
						}
						if(tc%2==1)
							dp=dp+2;
	
					
					for(k=j+2;k<5;k++)
					{
						if(grid1[k][i]==0)
						{

						fino=fin4(grid1,-move,1,-1,-1,i,k);
						if(fino)
							dp=dp-1;

						fino2=fin4(grid1,-move,1,-1,-1,i,k+1);
						if(fino&&fino2)
						{
							dp=dp-2;
						}
						}
					}
					
					//return i;
					if(dp>=dp1)
					{
						dp1=dp;
						ni2=i;
					}
			}
break;
}}}
if(ni2!=-1)
		return ni2;

for(i=0;i<7;i++)
{
	for(j=0;j<6;j++)
	{
		if(grid[j][i]==0)
		{

			{return c3;}
break;
}}}


} 


