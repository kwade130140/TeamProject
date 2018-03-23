#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define PIR1 1
#define PIR2 7
#define LED 0

int main(void) {
	wiringPiSetup();
	pinMode (PIR1, INPUT);
	pinMode (PIR2, INPUT);
	pinMode (LED, OUTPUT);

	printf("Pin: %d for LED and Pin: %d for IR1 and Pin: %d for IR2 \n", LED, PIR1, PIR2);

	digitalWrite(LED, LOW);

	printf("Calibrating... \n");
	while(digitalRead(PIR1) == 1 || digitalRead(PIR2) == 1) {
		delay (2000);
	}

	printf("Finished calibrating \n");

	int inactive = 1;
	while(inactive == 1) {

		int read1 = digitalRead(PIR1);
		int read2 = digitalRead(PIR2);

		if(read1 == 1) {
			digitalWrite (LED, HIGH);
			system("sudo service motion start");
			printf("Starting stream... \n");
			delay(1000);
			printf("Opening stream \n");
			system("sensible-browser http://localhost:8081");
			inactive = 0;
			digitalWrite (LED, LOW);

		}
		else if(read2 == 1) {
			digitalWrite (LED, HIGH);
			system("sudo service motion start");
			printf("Starting stream... \n");
			delay(1000);
			printf("Opening stream \n");
			system("sensible-browser http://localhost:8082");
			inactive = 0;
			digitalWrite (LED, LOW);
		}

		delay (500);

		printf("IR Sensor1: %d \n", read1);
		printf("IR Sensor2: %d \n", read2);

	}

	printf("Exiting... \n");
	system("sudo service motion stop");
	digitalWrite(LED, LOW);
	return 0;
}
