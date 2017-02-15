# myoung and mowen

NAME = demo_test

CC = gcc
CFLAGS = -Wall -Wextra -Werror


FILES = demo/01_demo_pass.c
FILES += demo/02_demo_bus.c
FILES += demo/03_demo_seg.c
FILES += demo/04_demo_fail.c
FILES += demo/00_demo_launcher.c
FILES += main.c

FILES += ../framework/test_list.c

INC = -I ../framework/ -I ..

all: $(NAME)

test: all
	./$(NAME)

$(NAME): $(FILES)
	$(CC) $(CFLAGS) $(INC) $(FILES)
