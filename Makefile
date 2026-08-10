CC := gcc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic -D_POSIX_C_SOURCE=200809L $(shell pkg-config --cflags sdl3 fribidi libdrm libdecor-0)
LIBS := $(shell pkg-config --libs sdl3 fribidi libdrm libdecor-0)

TARGET  := framebuffer
SRCS    := main.c

build:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LIBS)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: build run clean
