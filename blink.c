#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define PIR1 1
#define PIR2 7
#define PIR3 4
#define PIR4 13

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
		delay (2000);
	}

	printf("Finished calibrating \n");

	int inactive = 1;
	while(inactive == 1) {

		int read1 = digitalRead(PIR1);
		int read2 = digitalRead(PIR2);

		if(read1 == 1) {
			system("sudo service motion start");
			printf("Starting stream... \n");
			delay(1000);
			printf("Opening stream \n");
			system("sensible-browser http://localhost:8081");
			inactive = 0;
		}
		else if(read2 == 1) {
			system("sudo service motion start");
			printf("Starting stream... \n");
			delay(1000);
			printf("Opening stream \n");
			system("sensible-browser http://localhost:8081");
			inactive = 0;
		}
		else if(read3 == 1) {
			system("sudo service motion start");
			printf("Starting stream... \n");
			delay(1000);
			printf("Opening stream \n");
			system("sensible-browser http://localhost:8081");
			inactive = 0;
		}
		else if(read4 == 1) {
			system("sudo service motion start");
			printf("Starting stream... \n");
			delay(1000);
			printf("Opening stream \n");
			system("sensible-browser http://localhost:8081");
			inactive = 0;
		}

		delay (500);
	}

	printf("Exiting... \n");
	system("sudo service motion stop");
	return 0;
}
