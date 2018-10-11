
APP_NAME = run

CC = gcc

CFLAGS = -Ofast -Wall
INCFLAGS = -I./

SOURCES = $(wildcard ./*.c)
OBJECTS = $(SOURCES:./%.c=./bin/%.o)

all: $(APP_NAME)

./bin/%.o: ./%.c
	$(CC) $(CFLAGS) $(INCFLAGS) -o $@ -c $<

$(APP_NAME): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -rf bin/*.o $(APP_NAME)
