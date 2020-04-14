//move between files: alt_. ; alt_,
#include<stdio.h>
#include "screen.h"

void  setfgcolor(int fg){
	printf("%c[1;%dm", ESC, fg);
}

void setbgcolor(int bg){
	printf("%c[1;%dm", ESC, bg);
}

//set both background and foreground colors
void setcolors(int f, int b){
	setfgcolor(f);
	//setbgcolor(bg(b));
	setbgcolor(b);
}

void resetcolor(void){
	printf("%c[0m", ESC);
}
void clearscreen(void){
	printf("%c[2J", ESC);
}

void gotoXY(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
}

//draw lines
void drawbar(int col, int height){
	int i;
	for(i=1; i<=height; i++){
		gotoXY(i, col);
#ifdef UNICODE			//conditional compilation
		printf("%s",BAR);
#else
		printf("%c", '+');
#endif
	}
}

void drawrect(int row, int col, int height, int width){
	int  i,j;
	for(i=row; i<row+height; i++){
		for(j=col; j<col+width;j++){
			gotoXY(i,j);
#ifdef UNICODE
			printf("%s",BAR);
#else
			printf("%c",'#');
#endif
		}
		printf("\n");
	}
}
Position getscreensize(void){
	//in this function, we will use trminal query function to query cursor
	//position, the terminal should return a string
	//back to the program
	//if a query string "ESC[6n " is issued to the terminal
	Position p;
	int r,c;
	char ret[100] = "\0";
	gotoXY(999,999);
	printf("%c[6n",ESC);	//send the query string for cursor position
	scanf("%s",ret);
#ifdef DEBUG
	printf("%s\n",ret);
#endif
#include<string.h>
	if(strlen(ret)>0){
		char dum;			//dummy char to consume those symbols
		sscanf(ret, "%c%c%d%c%d%c", &dum, &dum, &r, &dum, &c, &dum);
		p.row = r;
		p.col = c;
	}
	else{
		p.row = 0;
		p.col = 0;
	}
	return p;
}
