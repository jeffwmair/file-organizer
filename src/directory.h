#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define DIRNAME "./tempdir/file"

int directory_exists(const char * dirname);
void get_directory_filenames(const char * dirname, char filenames[1000][500], int * filecount);
