NAME = push_swap
ARCHIVE = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
MAKE_LIB = ar -rcs

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

BONUS = $(wildcard ./bonuses/*.c)
SRCS = $(wildcard ./mandatory/*.c)
OBJS = $(SRCS:.c=.o)
BOBJ = $(BONUS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(ARCHIVE)
	@$(CC) $(ARCHIVE) -o $(NAME)
	@echo "$(GREEN)Building $(NAME)...$(RESET)"
	@echo "$(BLUE)Executable $(NAME) created.$(RESET)"

$(ARCHIVE): $(OBJS) $(BOBJ)
	@$(MAKE_LIB) $(ARCHIVE) $(OBJS) $(BOBJ)

bonus: $(BOBJ) $(OBJS)
	@$(CC) $(ARCHIVE) -o checker
	@echo "$(GREEN)Bonus checker created.$(RESET)"
	@touch bonus

clean:
	@rm -f $(OBJS) $(BOBJ) $(ARCHIVE)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(NAME) checker bonus
	@echo "$(RED)Cleaned executables.$(RESET)"

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
