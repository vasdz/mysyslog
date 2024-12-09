#ifndef LIBMYSYSLOG_H
#define LIBMYSYSLOG_H

enum LogLevel {
    DEBUG = 0,
    INFO,
    WARN,
    ERROR,
    CRITICAL
};

enum LogDriver {
    TEXT_DRIVER = 0,
    JSON_DRIVER
};

int mysyslog(const char* msg, int level, int driver, int format, const char* filepath);

#endif // LIBMYSYSLOG_H
