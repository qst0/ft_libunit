# myoung and mowen

NAME = libunit.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = main.c
FILES += framework/test_list.c

INC = -I ./framework/

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $(CFLAGS) $(INC) $(FILES)
