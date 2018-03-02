/*
 ============================================================================
 Name        : CameraData.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int in;
	int exit = 0;

	while(exit == 0) {

		printf("Enter 1 for v2 Cam or 2 for webcam or 0 to exit\n"); /* prints Hello */


		scanf("%d", &in);

		if(in == 1) {
			system("raspivid -b");
		}
		else if (in == 2) {
			system("guvcview");
		}
		else if (in != 0){
			printf("Bad input");
		}
		else {
			printf("Exiting");
			exit = 1;
		}
	}

	return 0;
}
