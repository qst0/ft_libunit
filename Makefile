# myoung and mowen

NAME = libunit.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES += framework/test_list.c

INC = -I ./framework/

OBJS = $(FILES:.c=.o)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	make -C tests/demo

$(NAME): $(OBJS)
	ar crs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
