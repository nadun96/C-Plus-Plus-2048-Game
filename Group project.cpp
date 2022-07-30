//GROUP 10

#include<iostream>
#include<conio.h>	//* getch
#include <stdlib.h> //* srand, rand
#include <time.h>   //* time 
using namespace std;

void up(int arr[4][4])
{
	int y,x,yy,xx;
	for(x=0;x<4;x++)
	{
		yy=0,xx=x;
		for(y=1;y<4;y++)
		{
			if(arr[y][x]!=0)
			{
				if(arr[y-1][x]==0 || arr[y-1][x]==arr[y][x])
				{
					if(arr[yy][xx]==arr[y][x])
					{
						arr[yy][xx]*=2;
						arr[y][x]=0;
					}
					else
					{
						if(arr[yy][xx]==0)
						{
							arr[yy][xx]=arr[y][x];
							arr[y][x]=0;
						}
						else
						{
							arr[++yy][xx]=arr[y][x];
							arr[y][x]=0;
						}
					}
				}
				else yy++;
			}
		}
	}
}


void down(int arr[4][4])
{
	int y,x,yy,xx;
	for(x=0;x<4;x++)
	{
		yy=3,xx=x;
		for(y=2;y>=0;y--)
		{
			if(arr[y][x]!=0)
			{
				if(arr[y+1][x]==0 || arr[y+1][x]==arr[y][x])
				{
					if(arr[yy][xx]==arr[y][x])
					{
						arr[yy][xx]*=2;
						arr[y][x]=0;
					}
					else
					{
						if(arr[yy][xx]==0)
						{
							arr[yy][xx]=arr[y][x];
							arr[y][x]=0;
						}
						else
						{
							arr[--yy][xx]=arr[y][x];
							arr[y][x]=0;
						}
					}
				}
				else yy--;
			}
		}
	}
}


void left(int arr[4][4])
{
	int y,x,yy,xx;
	for(y=0;y<4;y++)
	{
		yy=y,xx=0;
		for(x=1;x<4;x++)
		{
			if(arr[y][x]!=0)
			{
				if(arr[y][x-1]==0 || arr[y][x-1]==arr[y][x])
				{
					if(arr[yy][xx]==arr[y][x])
					{
						arr[yy][xx]*=2;
						arr[y][x]=0;
					}
					else
					{
						if(arr[yy][xx]==0)
						{
							arr[yy][xx]=arr[y][x];
							arr[y][x]=0;
						}
						else
						{
							arr[yy][++xx]=arr[y][x];
							arr[y][x]=0;
						}
					}
				}
				else xx++;
			}
		}
	}
}


void right(int arr[4][4])
{
	int y,x,yy,xx;
	for(y=0;y<4;y++)
	{
		yy=y,xx=3;
		for(x=2;x>=0;x--)
		{
			if(arr[y][x]!=0)
			{
				if(arr[y][x+1]==0 || arr[y][x+1]==arr[y][x])
				{
					if(arr[yy][xx]==arr[y][x])
					{
						arr[yy][xx]*=2;
						arr[y][x]=0;
					}
					else
					{
						if(arr[yy][xx]==0)
						{
							arr[yy][xx]=arr[y][x];
							arr[y][x]=0;
						}
						else
						{
							arr[yy][--xx]=arr[y][x];
							arr[y][x]=0;
						}
					}
				}
				else xx--;
			}
		}
	}
}


void newnumber(int arr[4][4])
{
	int yy,xx;
	srand(time(0));
	while(1)
	{
		yy=rand()%4;
		xx=rand()%4;
		if(arr[yy][xx]==0)
		{
			arr[yy][xx]=2;
			break;
		}
	}

}


void instruct(int arr[4][4])
{
	cout<<"\n\t\t\t Press Esc quit the game\n\n";
	cout<<"\n\t\t   up arrow - move Upwards   down arrow - move Downwards";
	cout<<"\n\t\t left arrow - move Lefwards  right arrow - move Rightwards";
	cout<<"\n\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(arr[i][j]==0) cout<<"|   ";
			else
				cout<<"| "<<arr[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t-----------------\n";
}


int checknum(int tmp[4][4],int arr[4][4])
{
	int rt=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(tmp[i][j]!=arr[i][j])
    		{
    			rt=0;
    			break;
			}
	return rt;
}


int checkwin(int arr[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(arr[i][j] == 2048)
    		{
    			return 1;
    		
			}
	return 0;
}


int gameover(int arr[4][4])
{
	int f=0,g=0,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(arr[i][j]==0)
    		{
    			f=1;
				break;	
			}
			
	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(arr[i+1][j]==arr[i][j] || arr[i][j+1]==arr[i][j])
    		{
    			g=1;
    			break;
			}
			
	if(f || g) return 1;
	else return 0;
}




int main()
{
	cout<<"\n\n\n\n\t\t\tWELCOME TO 2048 GAME\n\n\n Press any key to continue";
	getch();
	system("cls"); //*Clear Screen
	int x,y,i,j;
	int arr[4][4]={0},tmp[4][4]={0};
	srand(time(0));
	x=rand()%4;
	y=rand()%4;
	arr[x][y]=2;
	instruct(arr);
	
	int ch;
	while (1)
    {
    	for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			tmp[i][j]=arr[i][j];
    	ch=getch();
    	system("cls");  
    	
    	if(ch==72) up(arr); //* In ASCII decimal 72 for up arrow key
    	if(ch==80) down(arr); //* In ASCII decimal 80 for down arrow key
    	if(ch==75) left(arr); //* In ASCII decimal 75 for left arrow key
    	if(ch==77) right(arr); //* In ASCII decimal 77 for right arrow key
		if(ch==27) break; //* In ASCII decimal 27 for Escape Key
		
		
		if(!checknum(tmp,arr))
			newnumber(arr);
		instruct(arr);
			
		if (checkwin(arr))
		{
			cout<<"\n\n\t\t\t\t YOU WON THE GAME"<<endl;
			getch();
			break;
		}
			
		if(!gameover(arr))
		{
			cout<<"\n\n\t\t\tGAME OVER!!\n\n\n";
			getch();
			break;
		}	
	}
	return 0;
}

