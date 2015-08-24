#include <stdio.h>
#include <string.h>
#include "filereader.h"
#include "directory.h"

int main(int argc, char * argv[]) {

	/*
	 * Program idea:
	 *  - Check for files in a particular directory
	 *  - any files older than x months, do the following
	 *  	- automatically move into another directory, and place in 
	 *  	sub-directory named based on the date (2015-01-01)
	 *
	 * 	- do all this in a loop; sleep a relatively long time
	 * 		- once per day would be sufficient
	 */

	if (argc != 2) {
		fprintf(stderr, "Wrong number of args");
		return 1;
	}
	char * dirname = argv[1];

	if (!directory_exists(dirname)) {
		fprintf(stderr, "Directory with name '%s' could not be found", dirname);
		return 1;
	}

	// get the names of the files in the dir
	char filenames[1000][500];
	int numFiles = 0;
	get_directory_filenames(dirname, filenames, &numFiles);

	int i;
	for (i = 0; i < numFiles; i++) {
		printf("%s\n", filenames[i]);
	}

	return 0;

}
