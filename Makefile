# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = dental_reservation_system

# Source files
SOURCES = main.c ui.c reservation_manager.c search_sort.c statistics.c utils.c
OBJECTS = $(SOURCES:.c=.o)

# Header files
HEADERS = types.h ui.h reservation_manager.h search_sort.h statistics.h utils.h

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Install dependencies (if needed)
install:
	@echo "No external dependencies required"

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  clean   - Remove build files"
	@echo "  run     - Build and run the program"
	@echo "  debug   - Build with debug symbols"
	@echo "  help    - Show this help message"

.PHONY: all clean run debug install help
