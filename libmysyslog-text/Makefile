CC = gcc
CFLAGS = -Wall -Wextra -fPIC
LDFLAGS = -shared
TARGET = libmysyslog-text.so

all: $(TARGET)

$(TARGET): libmysyslog-text.o
	$(CC) $(LDFLAGS) -o $@ $^

libmysyslog-text.o: libmysyslog-text.c libmysyslog-text.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
