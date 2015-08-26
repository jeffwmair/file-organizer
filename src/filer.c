#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "filer.h"
#include "logger.h"

double days_old_date(time_t t);

void do_filing(const char * sourcedir, const char * destdir) {

	log_message("Doing filing...\n");

	// get the names of the files in the dir
	char filenames[MAX_FILES_PER_DIR][MAX_FILENAME_LENGTH];
	int numFiles = 0;
	get_directory_filenames(sourcedir, filenames, &numFiles);

	/* get current time */
	time_t t_now = time(NULL);
	struct tm tm = *localtime(&t_now);

	int i;
	for (i = 0; i < numFiles; i++) {
		const char * filename = filenames[i];
		if (is_older_than_n_days(DAYS_UNTIL_AUTO_MOVE, filename)) {
			printf("'%s' is older!\n", filename);
			organize_file(filename);
		}
	}
}

int is_older_than_n_days(int n, const char * filename) {
	struct stat attrib;
	stat(filename, &attrib);
	char date[10];
	time_t t_file = attrib.st_ctime;
	struct tm tm_file = *localtime(&attrib.st_ctime);
	double days_old = days_old_date(t_file);
	return days_old > n;
}

time_t get_file_date(const char* filename) {
}

/**
 * Move the file to an appropriate directory
 */
void organize_file(const char * filename) {
	/**
	 *
	 * if the directory does not exist
	 * 		create the directory
	 * 			name with yyyy-MM-dd
	 *
	 * 	move the file to the directory
	 *
	 */

	// directory name
	

	log_message("Moving file...");
	// nothing done yet
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
