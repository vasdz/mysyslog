CC = gcc
CFLAGS = -Wall -Wextra -I../libmysyslog
LDFLAGS = -L../libmysyslog -lmysyslog
TARGET = libmysyslog-daemon

all: $(TARGET)

$(TARGET): libmysyslog-daemon.o
	$(CC) -o $(TARGET) libmysyslog-daemon.o $(LDFLAGS)

libmysyslog-daemon.o: libmysyslog-daemon.c
	$(CC) $(CFLAGS) -c libmysyslog-daemon.c

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
