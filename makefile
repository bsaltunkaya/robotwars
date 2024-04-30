# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Source files
SRC = main.cpp Robot.cpp

# Output executable
OUT = RobotWars

# Default target to build and run
all: $(OUT) run

# Link the program
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Run the program
run: $(OUT)
	./$(OUT)

# Clean up files
clean:
	rm -f $(OUT)

.PHONY: all run clean
