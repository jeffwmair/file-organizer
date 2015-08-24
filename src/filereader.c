#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "filereader.h"

/**
 * Read a file
 */
void readFile(FILE **fp) {
	*fp = fopen("textfile", "r");
	if (fp == NULL) {
		perror("Error opening the file!\n");
		exit(EXIT_FAILURE);
	}
}

