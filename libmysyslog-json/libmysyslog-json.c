#include "libmysyslog-json.h"
#include <stdio.h>
#include <time.h>

static const char* log_level_labels[] = {"DEBUG", "INFO", "WARN", "ERROR", "CRITICAL"};

int write_log_as_json(const char* msg, int level, const char* filepath) {
    FILE* log_file = fopen(filepath, "a");
    if (!log_file) return -1;

    time_t current_time = time(NULL);
    fprintf(log_file, "{\"time\":%ld,\"level\":\"%s\",\"msg\":\"%s\"}\n", current_time, log_level_labels[level], msg);
    fclose(log_file);

    return 0;
}
