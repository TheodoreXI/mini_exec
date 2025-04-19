CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c utils.c utils1.c utils2.c utils3.c utils4.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus/pipex_bonus.c bonus/utils6_bonus.c bonus/utils5_bonus.c bonus/utils_bonus.c bonus/utils1_bonus.c bonus/utils2_bonus.c bonus/utils3_bonus.c bonus/utils4_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = pipex
NAME_BONUS = pipex_bonus

all: $(NAME)

$(OBJS): %.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $(NAME)

bonus: $(NAME_BONUS)
$(BONUS_OBJS): %.o: %.c bonus/pipex_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME_BONUS) 

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
