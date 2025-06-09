NAME	= megaphone
CC		= g++
FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= megaphone.cpp
OBJECT	= $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME) : $(OBJECT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re