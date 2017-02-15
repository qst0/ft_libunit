# myoung and mowen

NAME = demo_test

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = 01_demo_pass.c
FILES += 02_demo_bus.c
FILES += 03_demo_seg.c
FILES += 04_demo_fail.c
FILES += 00_demo_launcher.c
FILES += ../main.c

UNIT_INC = -I ../../framework -I ../..
UNIT_LINK = -L ../.. -lunit
UNIT = $(UNIT_INC) $(UNIT_LINK)

all: $(NAME)

clean:
	echo "write clean"

fclean:
	echo "write fclean"

re: fclean all

test: all
	./$(NAME)

$(NAME): $(FILES)
	$(CC) $(CFLAGS) $(UNIT) $(FILES) -o $(NAME)
