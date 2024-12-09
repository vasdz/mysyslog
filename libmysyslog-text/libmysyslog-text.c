#include "libmysyslog-text.h"
#include <stdio.h>
#include <time.h>

static const char* log_level_descriptions[] = {"DEBUG", "INFO", "WARN", "ERROR", "CRITICAL"};

int write_log_as_text(const char* msg, int level, const char* filepath) {
    FILE* log_file = fopen(filepath, "a");
    if (!log_file) return -1;

    time_t current_time = time(NULL);
    fprintf(log_file, "%ld %s %s\n", current_time, log_level_descriptions[level], msg);
    fclose(log_file);

    return 0;
}
