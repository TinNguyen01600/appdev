# appdev project 2020
# this project is for I-IT-1N students to understand what procedure
# and what tools are needed in an application developement

General Description of the Application

	This application will read a sound file (.wav file) and illustrates sound waves in the file 
	graphically by boxes; contemporaneously detect the "Sample Rate", "Duration", "number of
	Peaks", "Max decibel value" of the sound and send those information as a HTTP POST string 
	to a PHP program, which is recorded with a time stamp in a file.

The application is now available on Linux operating system.

Table of contents:
1. Configuration instructions
2. Installation instructions
3. Operatin instructions
4. File manifest
5. Copyright and licensing information
6. Contact information
7. Credits and acknowledgements


1. Configuration instructions
	1.1 Create 2 new folders name **appdev** and **public_html**.
	1.2 Convert your sound file (.ogg, .mp3,...) into a .wav file.
		(There are plentiful of websites on the Internet to do this)
	1.3 Download your sound file (.wav) into the **appdev** folder. 

2. Installation instructions
	2.1 Download the source code of the application from https://github.com/TinNguyen01600/appdev .
		2.1.1 Click to go to the link above.
		2.1.2 Click on the green button (Clone or download).
		2.1.3 Choose the option *Download ZIP*.
	2.2 Go to *Download* folder in *This PC* of your computer.
	2.3 Copy the ZIP file, whose name is appdev-master, to the **appdev** folder made previously.
	2.4 Go to **appdev** folder.
	2.5 Right click on the ZIP file and choose option *Extract here*.
		You should see there are 13 files in total.
	2.6 Move 2 .php files to the the folder **public_html**.
	2.7 Guarantee that the sound file .wav and 11 source code files **must** be in the same folder,
		in this case **appdev** folder.

3. Operating Instructions
	
	3rd party library needed: <stdio.h>; <unistd.h>; <i386-linux-gnu/curl/curl.h>; <math.h>
	
	3.1 Open command window.
	3.2 Go to the application file, using command line *cd appdev*.
	3.3 Listing all files in this folder, using command line *ls -l*.
		(There should be 12 files including 1 .wav file, 6 .c files, 3 .h files, 1 .md file and 1 makefile)
	3.4 Compile all the .c files into .o files for execution, using command line *make*.
	3.5 You should see 5 new-made files, including 4 .o files and 1 file name sound.
	3.6 Excute the application, using command line *./sound*.
	3.7 The pictorial interpretation of the sound waves is displayed with its data on the top of the screen.
4. File manifest
	Offer a list of files included in this app 
	In our case, the list may look like this:

	README.md:		this file
	screen.c:		contains screen manipulation functions
	screen.h:		contains screen function declarations and related constants
	comm.c:			contains function for client-server communication
	comm.h:			contains function declaration used in comm.c
	makefile:		contains linking rule, compiling rule, cleaning rule and archiving rule; 
					used to compile .c files into .o files for execution 
	testcurl.c:		contains main funtion to implement curl
	testscreen.c:	contains main function to run animation on screen.
	main.c:
	sound.c:
	sound.h:
	puttysize.php:
	test.php:

5. Copyright and licensing information
	This application follows GPLv2 license 

