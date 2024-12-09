#include "libmysyslog.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

static const char* log_level_names[] = {"DEBUG", "INFO", "WARN", "ERROR", "CRITICAL"};

static int write_text_log(const char* msg, int level, const char* filepath);
static int write_json_log(const char* msg, int level, const char* filepath);

int mysyslog(const char* msg, int level, int driver, int format, const char* filepath) {
    switch (driver) {
        case TEXT_DRIVER:
            return write_text_log(msg, level, filepath);
        case JSON_DRIVER:
            return write_json_log(msg, level, filepath);
        default:
            return -1; // Unsupported driver
    }
}

static int write_text_log(const char* msg, int level, const char* filepath) {
    FILE* log_file = fopen(filepath, "a");
    if (!log_file) return -1;

    time_t current_time = time(NULL);
    fprintf(log_file, "%ld %s %s\n", current_time, log_level_names[level], msg);
    fclose(log_file);
    return 0;
}

static int write_json_log(const char* msg, int level, const char* filepath) {
    FILE* log_file = fopen(filepath, "a");
    if (!log_file) return -1;

    time_t current_time = time(NULL);
    fprintf(log_file, "{\"timestamp\":%ld,\"level\":\"%s\",\"message\":\"%s\"}\n", current_time, log_level_names[level], msg);
    fclose(log_file);
    return 0;
}
