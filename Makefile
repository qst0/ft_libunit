# myoung and mowen

NAME = libunit.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror


FILES = tests/01_demo_pass.c
FILES += tests/02_demo_bus.c
FILES += tests/03_demo_seg.c
FILES += tests/04_demo_fail.c
FILES += tests/00_demo_launcher.c
FILES += main.c

FILES += framework/test_list.c

INC = -I ./framework/ -I .

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $(CFLAGS) $(INC) $(FILES)
