// In this file we define related constants and functions
// for handling sound.

//define sound structure (deal with .wav file)

typedef struct{
	char chunkID[4];	//should always be "RIFF"
	int chunkSize;
	char format[4];		//should always be "WAVE"
	char sub_chunk_1ID[4];	//should always be "fmt"
	int sub_chunk_1Size;	//should be 16 for PCM
	short audioFormat;		//should be 1 for PCM
	short numberChannels;	//could be 1 for mono, 2 for stereo
	int sampleRate;		//usually 44100 or 16000
	int byteRate;		// can be calculated
	short blockAlign;	//how many bytes in 1 block
	short bitsPerSample;	//could be 8 or 16
	char sub_chunk_2ID[4];	//should always be "data"
	int sub_chunk_2Size;	//can be calculated
}WAVheader;

//function declarations
WAVheader read_wav_header(FILE *fp);
void display_wav_header(WAVheader h);
