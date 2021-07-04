#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


char a[8][8];  int f1=0,f2=0;
void Bound()
{
	int i,j,count=48;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++) {
		if((i==2 || j==2 || i==5 || j==5))
		{
		a[i][j]='*';
	    }
	else if((i==1 && j==1) || (i==1 && j==4)||(i==1 && j==7)
	 || (i==4 && j==1) || (i==4 && j==4)||(i==4 && j==7)||
	(i==7 && j==1) || (i==7 && j==4)||(i==7 && j==7))
	{ 	a[i][j]=(char)count;
	count++;
		}	
		else
		a[i][j]=' ';
		
	}
		
	}
}
void print()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			printf("%c ",a[i][j]);
			
		}
		printf("\n");
	}
}

int sp()
{ f1=0; 
    if((a[0][0]=='O'&&a[0][3]=='O'&&a[0][6]=='O')
	||(a[3][0]=='O'&&a[3][3]=='O'&&a[3][6]=='O')
	||(a[6][0]=='O'&&a[6][3]=='O'&&a[6][6]=='O')
	||(a[0][0]=='O'&&a[3][0]=='O'&&a[6][0]=='O')
	||(a[0][3]=='O'&&a[3][3]=='O'&&a[6][3]=='O')
	||(a[0][6]=='O'&&a[3][6]=='O'&&a[6][6]=='O')
	||(a[0][0]=='O'&&a[3][3]=='O'&&a[6][6]=='O')
	||(a[0][6]=='O'&&a[3][3]=='O'&&a[6][0]=='O'))
	f1=1;
	return f1;
}
int sc()
{  f2=0;
	if((a[0][0]=='X'&&a[0][3]=='X'&&a[0][6]=='X')
	||(a[3][0]=='X'&&a[3][3]=='X'&&a[3][6]=='X')
	||(a[6][0]=='X'&&a[6][3]=='X'&&a[6][6]=='X')
	||(a[0][0]=='X'&&a[3][0]=='X'&&a[6][0]=='X')
	||(a[0][3]=='X'&&a[3][3]=='X'&&a[6][3]=='X')
	||(a[0][6]=='X'&&a[3][6]=='X'&&a[6][6]=='X')
	||(a[0][0]=='X'&&a[3][3]=='X'&&a[6][6]=='X')
	||(a[0][6]=='X'&&a[3][3]=='X'&&a[6][0]=='X'))
	  f2=1; 
	  return f2;
	}	

void play()
{  int f1=0,f2=0,t=1; int flag=0;
   int pos,cp,pp;
   for(int k=0;k<9;k++) 
   { 
	
		if(k%2==0) { label:
	    scanf("%d",&pos); pp=pos; 
	    if((pos==0 && (a[0][0]=='O'||a[0][0]=='X'))||(pos==1 &&
		 (a[0][3]=='O'||a[0][3]=='X'))||(pos==2 && (a[0][6]=='O'
		 ||a[0][6]=='X'))||(pos==3 && (a[3][0]=='O'||a[3][0]=='X'
		 )) ||(pos==4 && (a[3][3]=='O'||a[3][3]=='X'))||(pos==5 &&
		 (a[3][6]=='O'||a[3][6]=='X'))||(pos==6 && (a[6][0]=='O'||
		 a[6][0]=='X'))||(pos==7 && (a[6][3]=='O'||a[6][3]=='X'))||
		 (pos==8 &&(a[6][6]=='O'||a[6][6]=='X')))
	      goto label;
		}
	    else 
		{
	    if(k==1)
		{
		  if(a[3][3]==' ')
		  pos=4;
		  else
		  pos=0; 
	    }
		else 
		{
	     if(((a[0][0]=='O'&&a[0][3]=='O')||(a[3][3]=='O'&&a[6][0]=='O')
		 ||(a[3][6]=='O'&&a[6][6]=='O'))&& a[0][6]==' ')
		 pos=2;
	    else if(((a[0][3]=='O'&&a[0][6]=='O')||(a[3][0]=='O'&&a[6][0]=='O')
		||(a[3][3]=='O'&&a[6][6]=='O')) && a[0][0]==' ')
		pos=0;
		else if(((a[3][0]=='O'&&a[3][3]=='O')||(a[0][6]=='O'&&a[6][6]=='O')) &&a[3][6]==' ')
		pos=5;
		else if(((a[0][0]=='O'&& a[0][6]=='O')||(a[3][3]=='O'&&a[6][3]=='O'))
		&&(a[0][3]==' '))
		pos=1;
		else if(((a[0][0]=='O'&&a[6][0]=='O')||(a[0][0]=='O'&&a[0][6]=='O')||(a[3][3]=='O'&&a[3][6]=='O'))&& a[0][3]==' ')
		pos=3;
		else if(((a[0][3]=='O'&&a[6][3]=='O')||(a[0][6]=='O'&&a[6][0]=='O')
		||(a[3][0]=='O'&&a[3][6]=='O')||(a[0][0]=='O'&&a[6][6]=='O'))&&a[3][3]==' ')
         pos=4;
		else if(((a[0][0]=='O'&&a[3][0]=='O')||(a[0][6]=='O'&&a[3][3]=='O')||
		(a[6][6]=='O'&&a[3][6]=='O'))&&a[6][0]==' ')
		pos=6;
		else if(((a[0][3]=='O'&&a[3][3]=='O')||(a[6][0]=='O'&&a[6][6]=='O')) && a[6][3]==' ')
		pos=7;
		else if(((a[0][6]=='O'&&a[3][6]=='O')||(a[6][0]=='O'&&a[6][3]=='O'))&&a[6][6]==' ')
	   pos=8;
	   else if((a[0][0]=='O'||a[6][6]=='O' || a[6][0]=='O')&&a[0][2]==' ')
	   pos=2;
	   else
	   if((a[0][0]=='O'||a[6][6]=='O' || a[0][2]=='O')&&a[6][0]==' ')
	   pos=6;
	   else if((a[0][2]=='O'||a[6][6]=='O' || a[6][0]=='O')&&a[0][0]==' ')
	    pos=0;
	   else if((a[0][0]=='O'||a[0][2]=='O' || a[6][0]=='O') && a[6][6]==' ')
	   pos=8; 
	   else
	   if(a[0][0]==' ')
	   pos=0;
	   else if(a[0][3]=' ')
	   pos=1;
	   else if(a[0][6]=' ')
       pos=2;
	   else if(a[3][0]=' ')	
	   pos=3;
	   else if(a[3][3]=' ')
       pos=4;
       else if(a[3][6]=' ')
       pos=5;
       else if(a[6][0]=' ')
       pos=6;
       else if(a[6][3]=' ')
       pos=7;
       else if(a[6][6]=' ')
       pos=8;
     }
	   cp=pos;	  
    }

	if(pp==pos)
    switch(pos)
	{
      case 0:
        a[0][0]='O'; break;
      case 1:
        a[0][3]='O'; break;
      case 2:
        a[0][6]='O'; break;
      case 3:
        a[3][0]='O'; break;
      case 4:
        a[3][3]='O'; break;
      case 5:
        a[3][6]='O'; break;
      case 6:
        a[6][0]='O'; break;
      case 7:
        a[6][3]='O'; break;
      case 8:
        a[6][6]='O'; break;
	}
	else //if(cp==pos)
	switch(cp){
		case 0:
        a[0][0]='X'; break;
      case 1:
        a[0][3]='X'; break;
      case 2:
        a[0][6]='X'; break;
      case 3:
        a[3][0]='X'; break;
      case 4:
        a[3][3]='X'; break;
      case 5:
        a[3][6]='X'; break;
      case 6:
        a[6][0]='X'; break;
      case 7:
        a[6][3]='X'; break;
      case 8:
        a[6][6]='X'; break;
	}
	if(k>=5) 
	{  f1=sp();
	   f2=sc();
    } 
	  if(f1==1 || f2==1)
	     break;
	    system("cls");	print();
   }
 
 if(f1==1 && f2==1)
{
    system("cls");
 printf("draw \t score=1\n");
}
  else if(f1==1)
  {   system("cls");
   printf("You win\n");
}
   else if(f2==1)
   {  system("cls");
   printf("you loose\n");  
}
   else {   system("cls");
   printf("draw \t score=0\n");
}
}
void print1()
{
for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)	
	if((i==1 && j==1) || (i==1 && j==4)||(i==1 && j==7)
	 || (i==4 && j==1) || (i==4 && j==4)||(i==4 && j==7)||
	(i==7 && j==1) || (i==7 && j==4)||(i==7 && j==7))
	 	a[i][j]=' ';
			
for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		printf("%c ",a[i][j]);
		printf("\n");
	}	
}

int main()
{   
	system("cls");
	printf("rule of the game:\n");
	printf("rule 1: position is given in the board.\n\tchoose pos value for putting symbol\n");
    printf("rule 2 :your symbol  is 'X'\t Computer Symbol is 'Y'\n");
    printf("rule 3:condition for is winning the game: \n\tany continous rows , columns,diagonal or alternate should be same symbol\n");
	Bound();
	print();
	play();
	print1();	
}
