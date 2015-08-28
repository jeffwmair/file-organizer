#include <time.h>
#include <stdio.h>
#include "logger.h"

void log_message(const char * message) {

	// open the log file
	FILE *logfile = fopen(LOG_FILE, "a");
	time_t t_now = time(NULL);
	struct tm tm = *localtime(&t_now);
	char date_prefix[20];
	// generate a formatted date string
	sprintf(date_prefix, "%d-%02d-%02d %02d:%02d:%02d", 
			tm.tm_year+1900, 
			tm.tm_mon+1, 
			tm.tm_mday,
			tm.tm_hour,
			tm.tm_min,
			tm.tm_sec);

	// write to the log file
	char the_message[500];
	sprintf(the_message, "%s - %s\n", date_prefix, message);
	fprintf(logfile, "%s", the_message);
	printf("%s", the_message);

	// close the file
	fclose(logfile);
}
