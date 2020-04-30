//  THe File contains function to manipulate screen, such as set foreground color 
// background color,clearscreen, restore default setting,etc.
// To enable screen manipulation , we need to use VT100 escape sequences
// see the link : http://www.termsys.demon.co.uk/vtansi.htm
// use SHIFT_insert key to paste

//move between files: alt_.,alt_,

#include <stdio.h> // for printf() function
#include "screen.h"// contains constants used in this file

//fucntion definitions
// a function name is an identifier in C , an udentifier should start with 
// a letter or an undersore , and followed by letter,digits,underscores

void setfgcolor( int fg){
	printf("%c[1;%dm", ESC, fg);

}

void setbgcolor(int bg){
	printf("%c[1;%dm", ESC, bg);
}

void setcolors(int f, int b){
	setfgcolor(f);
	setbgcolor(b);
}
void clearscreen(void){
	printf("%c[2J", ESC); // we can use 27 = 0x1B

}

void resetcolors(void){
	printf("%c[0m",ESC);
}

void gotoXY(int row ,int col){
	printf("%c[%d;%dH",ESC ,row,col);
}

void drawbar(int col,int height){
	int i;
	for(i=1;i<=height;i++){
		gotoXY(35-i,col);
#ifdef UNICODE	//following codes are in coditional compilation
		printf("%s",BAR);
#else
		printf("%c",'#');
#endif
	}
}

void drawrect(int row, int col, int height, int width) {
    for (int i = row; i < row + height; i++) {
        for (int j = col; j < col + width; j++) {
            gotoXY(i, j);
#ifdef UNICODE
            printf("%s", BAR);
#else
            printf("%s", '|');
#endif
        }
}
}

Position getscreensize(void)
{
	//in this function, we will use terminal query function to query cursor
	//position, the terminal should return a string back to the program
	//if a query string "ESC[6n" is issued to the terminal
	Position p;
	int r, c;	//for decoding the report string
	char ret[100] = "\0";	//an empty string to get report
	gotoXY(999,999);	//force the cursor to the bottom right corner
	printf("%c[6n", ESC);
	scanf("%s", ret);	//we get report from the terminal
#ifdef DEBUG
	printf("%s\n", ret);
#endif
	//we will decode the returned string
#include <string.h>
	if(strlen(ret)>0)	//in this case we got a cursor position report
	{
		char dum;	//dummy char to consume those symbols
		sscanf(ret, "%c%c%d%c%d%c", &dum, &dum, &r, &dum, &c, &dum);
		p.row = r;
		p.col = c;
	}
	else
	{
		p.row = 0;
		p.col = 0;
	}
	return p;
}


