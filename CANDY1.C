/*
			AUTHOR NAME:-AMAAN SAJINA
			DOC:-06/01/2022
			MODULE:-CREATE A CANDY GAME !
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	int candyX=41,candyY=1,boxX=40,boxY=22;
	int score=0,lives=3,d=0;
	char ch;
	textbackground(RED);
	start:
	clrscr();

	gotoxy(60,5);
	cprintf("score=%i",score); //score

	gotoxy(60,6);
	cprintf("lives=%i",lives);  //lives


	textcolor(YELLOW);
	gotoxy(candyX,candyY);
	cprintf("0");      //candy

	textcolor(YELLOW);
	gotoxy(boxX,boxY);
	cprintf("#");      //left piller

	gotoxy(boxX+5,boxY);
	cprintf("#");     //right piller

	gotoxy(boxX,boxY+1);
	cprintf("######");   //base

	if(kbhit())
	{
		ch=getch();
		switch(ch)
		{
			case 'a' :if(boxX>1)
				{
					boxX=boxX-2;
				}//end of if
				break;

			case 'd' :if(boxX<76)
				{
					boxX=boxX+2;
				}//end of if

				break;

			case 'x' : exit(0);
		}  //end of switch
	}//end of if

	if(candyY==22)
	{
		 d=candyX-boxX;
		if(d==1 || d==2 || d==3 || d==4)
		{
			sound(50);
			delay(200);
			nosound();
			score++;
		} //end of if
		else
		{
			sound(2000);
			delay(200);
			nosound();
			lives--;
			if(lives==0)
			{
				clrscr();
				gotoxy(20,13);
				textcolor(WHITE);
				sound(200);
				delay(200);
				nosound();
				cprintf("Oops!GAME OVER!!BETTER LUCK NEXT TIME!!!");
				getch();
				exit(0);
			}  //end of if
		}   //end of else

		candyX=rand()%80+1;
		candyY=1;
	}   //end of if

	delay(200);
	candyY++;

	goto start;

} //end of main





