NAME = MutantStack

SRCS = main.cpp 

OBJS = $(SRCS:.cpp=.o)

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = $(NAME)

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)

.PHONY: clean fclean re
