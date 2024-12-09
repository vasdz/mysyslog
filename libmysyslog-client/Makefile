CC = gcc
CFLAGS = -Wall -Wextra -I../libmysyslog
LDFLAGS = -L../libmysyslog -lmysyslog
TARGET = libmysyslog-client

all: $(TARGET)

$(TARGET): libmysyslog-client.o
	$(CC) -o $(TARGET) libmysyslog-client.o $(LDFLAGS)

libmysyslog-client.o: libmysyslog-client.c
	$(CC) $(CFLAGS) -c libmysyslog-client.c

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
