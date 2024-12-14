NAME = philo
CC = cc
INC_DIR = include

SRC_DIR = srcs
SRC_FILES = main.c 

SETUP_DIR = ./$(SRC_DIR)/setup
SETUP_FILES = init_table.c \
			init_philos.c \
			check_arg.c \
			input_validation.c \
			table.c 

UTILS_DIR = ./$(SRC_DIR)/utils
UTILS_FILE = ft_atoi.c \
			ft_isspace.c \
			time.c

CONTEXT_DIR = ./$(SRC_DIR)/context
CONTEXT_FILE = start_philo.c \
			   start_lifecycle.c \
			   fork.c \
			   eating.c \
			   sleeping.c \
			   print_stats.c		   

CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) 
#-g -fsanitize=thread

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SETUP_SRCS = $(addprefix $(SETUP_DIR)/, $(SETUP_FILES))
UTILS_SRCS = $(addprefix $(UTILS_DIR)/, $(UTILS_FILE))
CONTEXT_SRCS = $(addprefix $(CONTEXT_DIR)/, $(CONTEXT_FILE))
OBJS = $(SRCS:.c=.o) $(SETUP_SRCS:.c=.o) $(UTILS_SRCS:.c=.o) $(CONTEXT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re