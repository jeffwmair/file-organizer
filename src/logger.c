#include <stdio.h>
#include "logger.h"

void log_message(const char * message) {
	// log it to disk; use LOG_FILE
	printf("%s", message);
}
