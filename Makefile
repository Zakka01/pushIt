CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined

PUSH_NAME = push_swap
BONUS_NAME = checker

PUSH_DIR = push_swap_prgrm
BONUS_DIR = checker_prgrm

PUSH_SRC = $(wildcard $(PUSH_DIR)/*.c)
CHECK_SRC = $(wildcard $(BONUS_DIR)/*.c)

PUSH_OBJ = $(PUSH_SRC:.c=.o)
BONUS_OBJ = $(CHECK_SRC:.c=.o)

RM = rm -f

all: $(PUSH_NAME) $(BONUS_NAME)

push_swap: $(PUSH_NAME)

bonus: $(BONUS_NAME)

$(PUSH_NAME): $(PUSH_OBJ)
	$(CC) $(CFLAGS) $(PUSH_OBJ) -o $(PUSH_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

push_swap/%.o: push_swap/%.c push_swap/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

checker/%.o: checker/%.c checker/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(PUSH_OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(PUSH_NAME) $(BONUS_NAME)

re: fclean all
