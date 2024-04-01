# Compiler
CC := c++

# Compiler flags
CFLAGS := -Wall -Wextra -Werror -std=c++98

# Source files
SRCS := main.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Executable
TARGET := program

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Clean up object files, executable and other files
fclean: clean
	rm -f $(TARGET)

# Rebuild
re: clean all

# Phony targets
.PHONY: all clean re
