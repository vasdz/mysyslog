#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libmysyslog.h"

#define CONFIG_FILE_PATH "/etc/mysyslog/mysyslog.cfg"

static volatile sig_atomic_t is_running = 1;

void handle_signal(int signal) {
    if (signal == SIGINT || signal == SIGTERM) {
        is_running = 0;
    }
}

void load_config(const char* filepath, int* log_level, int* log_driver, int* log_format, char* output_path) {
    FILE* config_file = fopen(filepath, "r");
    if (!config_file) {
        fprintf(stderr, "Error: Could not open config file: %s\n", filepath);
        exit(EXIT_FAILURE);
    }

    if (fscanf(config_file, "level=%d\n", log_level) != 1 ||
        fscanf(config_file, "driver=%d\n", log_driver) != 1 ||
        fscanf(config_file, "format=%d\n", log_format) != 1 ||
        fscanf(config_file, "path=%s\n", output_path) != 1) {
        fprintf(stderr, "Error: Invalid config file format.\n");
        fclose(config_file);
        exit(EXIT_FAILURE);
    }

    fclose(config_file);
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    int log_level, log_driver, log_format;
    char log_filepath[256];

    load_config(CONFIG_FILE_PATH, &log_level, &log_driver, &log_format, log_filepath);

    while (is_running) {
        mysyslog("Daemon is active", log_level, log_driver, log_format, log_filepath);
        sleep(5); // Log every 5 seconds
    }

    return 0;
}
