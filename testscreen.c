#include "screen.h"
#include <unistd.h>
#include <stdio.h>
#include "comm.h"
#include "sound.h"

int main(void){
	Position cur = getscreensize();
	char postdata[100];
	sprintf(postdata, "row=%d&col=%d&id=e1900300", cur.row, cur.col);
	sendpost(URL, postdata);

	gotoXY(1,1);
	printf("screen size: row = %d, col = %d\n",cur.row,cur.col);
	printf("Press any key to continue");
	getchar();  //the user press a key
	getchar();
	int ff,bb;
	float step = (float)cur.col/cur.row;
	for(int i=1; i<=cur.row; i++){
		ff = (i+1)%8 + BLACK;
		bb = (i+2)%8 + BLACK;
		setcolors(ff,bg(bb));
		clearscreen();
		drawrect(10,10,5,30);
		gotoXY(cur.row-i, (i-1)*step+1);
		printf("HELLO\n");
		//sleep(1);
		usleep(250000);
	}

	//clearscreen();
	setfgcolor(BLUE);
	gotoXY(14, 35);
	printf("E1900300\n");
	getchar();
	drawbar(30,30);
	drawbar(50,30);

	getchar();
	resetcolor();
	clearscreen();
	printf("This line is back to default color.\n");
	FILE *fp;
	fp = fopen("test.wav","r");
	WAVheader h = read_wav_header(fp);
	fclose(fp);
	display_wav_header(h);
}
