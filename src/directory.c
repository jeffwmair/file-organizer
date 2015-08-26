#include "directory.h"

/**
 * Test if the directory exists or not; return 1 for exists, 0 for not
 */
int directory_exists(const char * dirname) {
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (dirname)) != NULL) {
		closedir (dir);
		return 1;
	} else {
		return 0;
	}
}

/*
 * Get an array of filenames contained inside the given directory
 */
void get_directory_filenames(const char * dirname, char filenames[MAX_FILES_PER_DIR][MAX_FILENAME_LENGTH], int * filecount) {
	DIR *dir;
	struct dirent *ent;
	int i = 0;
	if ((dir = opendir (dirname)) != NULL) {
		while ((ent = readdir (dir)) != NULL) {
			// skip the current & parent directory 'dots'
			if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
				continue;
			}
			strcpy(filenames[i], dirname);
			strcat(filenames[i], ent->d_name);
			i++;
		}
		closedir (dir);
	} else {
		perror ("Could not open the directory");
	}

	// tell the caller how many files were found
	*filecount = i;
}
