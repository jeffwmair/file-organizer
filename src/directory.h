#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES_PER_DIR 1000
#define MAX_FILENAME_LENGTH 500

void get_message_missing_dir(const char * dirname, char * msg);
int directory_exists(const char * dirname);
void get_directory_filenames(const char * dirname, char filenames[MAX_FILES_PER_DIR][MAX_FILENAME_LENGTH], int * filecount);
void make_directory(const char * dirname);
