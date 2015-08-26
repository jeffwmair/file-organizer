#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "filer.h"
#include "directory.h"

#define REQUIRED_ARGS 3

/**
 * Main entry point of the program.
 */
int main(int argc, char * argv[]) {

	// make sure we got the right number of args
	if (argc != REQUIRED_ARGS) {
		fprintf(stderr, "Wrong number of args.");
		return EXIT_FAILURE;
	}

	char * sourcedirname = argv[1];
	char * destindirname = argv[2];

	if (!directory_exists(sourcedirname)) {
		fprintf(stderr, "Directory with name '%s' could not be found", sourcedirname);
		return EXIT_FAILURE;
	}

	if (!directory_exists(destindirname)) {
		fprintf(stderr, "Directory with name '%s' could not be found", destindirname);
		return EXIT_FAILURE;
	}

	// main program loop
	while (1) {
		do_filing(sourcedirname, destindirname);
		sleep(1);
	}

}

