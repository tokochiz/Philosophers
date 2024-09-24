NAME = philo
CC = cc
INC_DIR = include

SRC_DIR = srcs
SRCFILES = main.c \
			error.c \
			init.c \
			ft_utils.c 

CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -fsanitize=thread

SRCS = $(addprefix $(SRC_DIR)/, $(SRCFILES))
OP_SRCS = $(addprefix $(OP_DIR)/, $(OPFILES))
OBJS = $(SRCS:.c=.o) $(OP_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C fclean

re: fclean all

.PHONY: all clean fclean re