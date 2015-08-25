#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "filereader.h"
#include "directory.h"

double days_old_date(time_t t);

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


	/* get current time */
	time_t t_now = time(NULL);
	struct tm tm = *localtime(&t_now);
	int cur_year = tm.tm_year + 1900;
	int cur_month = tm.tm_mon + 1;
	int cur_mday = tm.tm_mday;
	printf("NOW: Year:%d, Month:%d, Day:%d\n", cur_year, cur_month, cur_mday);
	printf("********************************\n");

	int i;
	for (i = 0; i < numFiles; i++) {
		struct stat attrib;
		stat(filenames[i], &attrib);
		char date[10];
		time_t t_file = attrib.st_ctime;
		struct tm tm_file = *localtime(&attrib.st_ctime);
		printf("File info: %s: Yr:%d Mon:%d, MDay:%d. ", filenames[i], tm_file.tm_year+1900, tm_file.tm_mon+1, tm_file.tm_mday);
		double days_old = days_old_date(t_file);
		printf("File is %G days old.\n", days_old);
	}

	return 0;

}

/**
 * Calculates how many days ago the given date is
 */
double days_old_date(time_t t) {
	time_t t_now = time(NULL);
	struct tm tm = *localtime(&t_now);
	double seconds = difftime(t_now, t);
	double minutes = seconds / 60.0;
	double hours = minutes / 60.0;
	double days = hours / 24.0;
	return days;
}
