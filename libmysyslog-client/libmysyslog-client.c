#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmysyslog.h"

void show_help(const char* program_name) {
    printf("Usage: %s -m <message> -l <log_level> -d <driver> -f <format> -p <log_file>\n", program_name);
    printf("\nOptions:\n");
    printf("  -m <message>   Log message content\n");
    printf("  -l <log_level> Logging level (0: DEBUG, 1: INFO, etc.)\n");
    printf("  -d <driver>    Log driver type (0: TEXT, 1: JSON)\n");
    printf("  -f <format>    Additional format option (optional)\n");
    printf("  -p <log_file>  Path to the log file\n");
}

int main(int argc, char* argv[]) {
    int opt;
    char* log_message = NULL;
    int log_level = INFO; // Default log level
    int log_driver = TEXT_DRIVER; // Default log driver
    int log_format = 0; // Default log format
    char* log_file = NULL;

    // Parse command-line arguments
    while ((opt = getopt(argc, argv, "m:l:d:f:p:")) != -1) {
        switch (opt) {
            case 'm':
                log_message = optarg;
                break;
            case 'l':
                log_level = strtol(optarg, NULL, 10);
                break;
            case 'd':
                log_driver = strtol(optarg, NULL, 10);
                break;
            case 'f':
                log_format = strtol(optarg, NULL, 10);
                break;
            case 'p':
                log_file = optarg;
                break;
            default:
                show_help(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Validate required parameters
    if (!log_message || !log_file) {
        show_help(argv[0]);
        fprintf(stderr, "Error: Missing required arguments\n");
        exit(EXIT_FAILURE);
    }

    // Write log message
    if (mysyslog(log_message, log_level, log_driver, log_format, log_file) != 0) {
        fprintf(stderr, "Error: Failed to write log message\n");
        exit(EXIT_FAILURE);
    }

    printf("Log message successfully written to %s\n", log_file);
    return 0;
}
