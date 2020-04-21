#include <math.h>
#include <stdio.h>
#include "sound.h"
#include "screen.h"
WAVheader read_wav_header(FILE *fp){
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}


void display_wav_header(WAVheader h){
	printf("Chunk ID: ");
	for(int i = 0; i<4; i++){
		printf("%c", h.chunkID[i]);
	}
	printf("\n");
	printf("Chunk size: %d\n", h.chunkSize);
	printf("Num of channels: %d\n", h.numberChannels);
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Block align: %d\n", h.blockAlign);
	printf("Bits per sample: %d\n", h.bitsPerSample);
	double duration = (double)h.sub_chunk_2Size/h.byteRate;
	printf("Duration: %f\n", duration);
}

void wavdata(WAVheader h, FILE *fp){
	// we will read sound sample from the opened file
	//the samples are cal in to decibel value using Root Mean Square
	// (RMS) formula. We will display a 5-sec record sound into bar chart
	// our sound file uses sample rate of 16000, for 5 secs, there are
	// 80000 samples, we want to display them into 160 bars

	int peak = 0, flag = 0;
	short samples[500];		// to read 500 samples from wav file
	for(int i=0; i<160; i++){
		fread(samples, sizeof(samples), 1, fp);
		double sum = 0.0;
		for(int j = 0; j<500; j++){
			sum += (samples[j]*samples[j]);
		}
		double re = sqrt(sum/500);
#ifdef SDEBUG
		printf("db[%d] = %f\n", i+1, 20*log10(re));
#else
		//display bar for re-value
		if(20*log10(re) > 70){
			setfgcolor(RED);
			if(flag == 0){
				flag = 1;
				peak++;
			}
		}
		else{
			setfgcolor(WHITE);
			flag = 0;
		}
		drawbar(i+1, (int)20*log10(re)/3);
		resetcolor();
#endif
	}
	gotoXY(1,1);
	printf("Sample Rate: %d\n", h.sampleRate);
	gotoXY(1,75);
	printf("Duration: %f\n", (float)h.sub_chunk_2Size/h.byteRate);
	gotoXY(1,150);
	
	//display_wav_header(h);
	printf("Peaks: %d\n",peak);
}
