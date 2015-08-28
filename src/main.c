#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "filer.h"
#include "directory.h"

#define REQUIRED_ARGS 3

void exit_on_no_directory(char * dirname);

/**
 * Main entry point of the program.
 */
int main(int argc, char * argv[]) {

	// make sure we got the right number of args
	if (argc != REQUIRED_ARGS) {
		fprintf(stderr, "Wrong number of args.");
		return EXIT_FAILURE;
	}
	
	// input arguments
	char * sourcedirname = argv[1];
	char * destindirname = argv[2];

	if (!directory_exists(sourcedirname)) exit_on_no_directory(sourcedirname);
	if (!directory_exists(destindirname)) exit_on_no_directory(destindirname);

	// main program loop
	while (1) {
		do_filing(sourcedirname, destindirname);
		sleep(1);
	}

}

/**
 * Exit the program on missing directory
 */
void exit_on_no_directory(char * dirname) {
	char err_msg[500];
	get_message_missing_dir(dirname, err_msg);
	fprintf(stderr, "%s", err_msg);
	exit(EXIT_FAILURE);
}
