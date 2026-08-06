NAME	= bsq

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c read_input.c parse_header.c parse_map.c square.c print_map.c utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c bsq.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
