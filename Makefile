# Directories
SRCDIR = src
INCDIR = include
BINDIR = bin

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11 -Wpedantic
INCFLAGS = -I$(INCDIR)

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)

# Object files
OBJS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRCS))

# Target executable
TARGET = $(BINDIR)/tetris

# Build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lncurses

$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)