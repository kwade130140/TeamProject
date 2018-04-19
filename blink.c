#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define PIR1 1
#define PIR2 7
#define PIR3 5
#define PIR4 14


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
			delay (1000);
			inactive = 0;
		}
		else if(read2 == 1) {
			system("sudo uv4l restart");
			printf("Starting stream... \n");
			system("sudo uv4l --driver uvc --device-path 001:006");
			delay (1000);
			inactive = 0;
		}
		else if(read3 == 1) {
			system("sudo uv4l restart");
			printf("Starting stream... \n");
			system("sudo uv4l --driver uvc --device-path 001:006");
			delay (1000);
			inactive = 0;
		}
		else if(read4 == 1) {
			system("sudo uv4l restart");
			printf("Starting stream... \n");
			system("sudo uv4l --driver uvc --device-path 001:006");
			delay (1000);
			inactive = 0;
		}

		delay (500);
		printf("Read1: %d, Read2: %d, Read3: %d, Read4: %d\n", read1, read2, read3, read4);
	}

	int streamNo = 0;
	while(inactive == 0) {
		delay(10000);
		system("sudo uv4l restart");
		printf("Switching stream... \n");

		switch(streamNo) {
		case 0:
			system("sudo uv4l --driver uvc --device-path 001:006");
			streamNo = 1;
			break;
		case 1:
			system("sudo uv4l --driver uvc --device-path 001:006");
			streamNo = 2;
			break;
		case 2:
			system("sudo uv4l --driver uvc --device-path 001:006");
			streamNo = 3;
			break;
		case 3:
			system("sudo uv4l --driver raspicam --width 640 --height 480 --framerate 10 --server-option '--port=8080'");
			streamNo = 0;
			break;
		}
	}

	printf("Exiting... \n");
	system("sudo pkill uv4l");
	return 0;
}
