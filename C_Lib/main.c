#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include "MCP3008.h"

int main() {

	//MISO MOSI SCLK CS
	if(!MCP3008_Startup(9,8,7,6)) {
		printf("MCP3008 SPI initialization not successful.\n");
		return -1;
	}

	/* Read channels a few times */
	int nTimes = 100;
	int delay = 300;

	for(int i=0;i < nTimes; i++) {

		for(int channel = 0; channel < 8; channel++) {
			int adcValue = MCP3008_ReadChannel(channel);
			//Print comma-separated, end with newline
			printf("%d", adcValue);
			if(channel != 7) printf(",");
			else printf("\n");
		}

		usleep(delay * 1000);
	}

	printf("Goodbye.\n");

	return 0;
}
