CC = gcc
CFLAGS = -Wall -Wextra -fPIC
LDFLAGS = -shared
TARGET = libmysyslog-json.so

all: $(TARGET)

$(TARGET): libmysyslog-json.o
	$(CC) $(LDFLAGS) -o $@ $^

libmysyslog-json.o: libmysyslog-json.c libmysyslog-json.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
