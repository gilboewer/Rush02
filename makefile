NAME	= rush-02
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INCS	= -I .
SRCS	= main.c \
		  numbertowords.c \
		  helper.c \
		  parse.c \
		  read.c \
		  words_utils.c \
		  hundreds.c
OBJS	= $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
