// usually in a header file we have 2 parts:
// 1. function declaration.
//2. constant definitions.

//constant definitions
#define ESC 27 		//or using hex 0x1B


//make enumeration for fg colors
enum FG {BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c+10)	//this is called macro definition
//making a constant in a name will make the program more meaningfull/readable
//now we can use color names in function setfgcolor()

#define UNICODE		//for conditional compilation
#define BAR "\u2590"

//#define DEBUG
typedef struct{
	int row;	//the number of rows and cols of the screen
	int col;
}Position;

//function declarations
void setfgcolor(int);
void resetcolor(void);
void clearscreen(void);
void gotoXY(int, int);
void drawbar(int, int);
void setbgcolor(int);
void setcolors(int, int);
void drawrect(int, int ,int, int);
Position getscreensize(void);
