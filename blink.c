#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define PIR1 1
#define PIR2 7
#define PIR3 5
#define PIR4 14

//Test comment
int main(void) {
	wiringPiSetup();
	pinMode (PIR1, INPUT);
	pinMode (PIR2, INPUT);
	pinMode (PIR3, INPUT);
	pinMode (PIR4, INPUT);

	printf("Calibrating... \n");
	while(digitalRead(PIR1) == 1 
			|| digitalRead(PIR2) == 1
			|| digitalRead(PIR3) == 1
			|| digitalRead(PIR4) == 1) {
		delay (1000);
	}

	printf("Finished calibrating \n");

	int inactive = 1;
	while(inactive == 1) {

		int read1 = digitalRead(PIR1);
		int read2 = digitalRead(PIR2);
		int read3 = digitalRead(PIR3);
		int read4 = digitalRead(PIR4);

		if(read1 == 1) {
			system("sudo uv4l restart");
			printf("Starting stream... \n");
			system("sudo uv4l --driver raspicam --width 640 --height 480 --framerate 5 --server-option '--port=8080'");
			delay(1000);
			printf("Opening stream \n");
			system("sensible-browser http://localhost:8080/stream");
			inactive = 0;
		}
		else if(read2 == 1) {
			system("sudo uv4l restart");
			printf("Starting stream... \n");
			system("sudo uv4l --driver uvc --device-path 001:007");
			delay(1000);
			printf("Opening stream \n");
			system("sensible-browser http://localhost:8080/stream");
			inactive = 0;
		}
		else if(read3 == 1) {
			system("sudo uv4l restart");
			printf("Starting stream... \n");
			system("sudo uv4l --driver uvc --device-path 001:007");
			delay(1000);
			printf("Opening stream \n");
			system("sensible-browser http://localhost:8080/stream");
			inactive = 0;
		}
		else if(read4 == 1) {
			system("sudo uv4l restart");
			printf("Starting stream... \n");
			system("sudo uv4l --driver uvc --device-path 001:007");
			delay(1000);
			printf("Opening stream \n");
			system("sensible-browser http://localhost:8080/stream");
			inactive = 0;
		}

		delay (500);
		printf("Read1: %d, Read2: %d, Read3: %d, Read4: %d\n", read1, read2, read3, read4);
	}

	printf("Exiting... \n");
	system("sudo pkill uv4l");
	return 0;
}
