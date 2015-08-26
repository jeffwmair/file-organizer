#define DAYS_UNTIL_AUTO_MOVE 45

#include "directory.h"

void do_filing(const char * sourcedir, const char * destdir);
int is_older_than_n_days(int n, const char * filename);
void organize_file(const char * filename);
