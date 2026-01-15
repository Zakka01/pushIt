CC = cc
CFLAGS = -Wall -Wextra -Werror

PUSH_NAME = push_swap
CHECK_NAME = checker

PUSH_DIR = push_swap_prgrm
CHECK_DIR = checker_prgrm

PUSH_SRC = $(wildcard $(PUSH_DIR)/*.c)
CHECK_SRC = $(wildcard $(CHECK_DIR)/*.c)

PUSH_OBJ = $(PUSH_SRC:.c=.o)
CHECK_OBJ = $(CHECK_SRC:.c=.o)

RM = rm -f

all: $(PUSH_NAME) $(CHECK_NAME)

$(PUSH_NAME): $(PUSH_OBJ)
	$(CC) $(CFLAGS) $(PUSH_OBJ) -o $(PUSH_NAME)

$(CHECK_NAME): $(CHECK_OBJ)
	$(CC) $(CFLAGS) $(CHECK_OBJ) -o $(CHECK_NAME)

push_swap/%.o: push_swap/%.c push_swap/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

checker/%.o: checker/%.c checker/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(PUSH_OBJ) $(CHECK_OBJ)

fclean: clean
	$(RM) $(PUSH_NAME) $(CHECK_NAME)

re: fclean all
