# myoung and mowen

NAME = libft_test

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES += 00_ft_atoi_launcher.c
FILES += 01_ft_atoi_min.c
FILES += 02_ft_atoi_max.c
FILES += 03_ft_atoi_hard.c
FILES += 04_ft_atoi_medium.c
FILES += 05_ft_atoi_easy.c
FILES += 06_ft_atoi_veryhard.c
FILES += 07_ft_atoi_none.c

FILES += ../main.c

#USER MUST SET THESE VALUES BELOW!

LIBFT_H = ~/Desktop/libft/includes
LIBFT_A = ~/Desktop/libft

LIBFT_INC = -I $(LIBFT_H)
LIBFT_LINK = -L $(LIBFT_A) -lft
LIBFT = $(LIBFT_INC) $(LIBFT_LINK)

UNIT_INC = -I ../../framework -I ../..
UNIT_LINK = -L ../.. -lunit
UNIT = $(UNIT_INC) $(UNIT_LINK)

all: $(NAME)

libft.a:
	make -C $(LIBFT_A)

clean:
	@echo "Cleaning..."

fclean:
	@echo "Full clean..."
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME)

$(NAME): libft.a $(FILES)
	$(CC) $(CFLAGS) $(UNIT) $(LIBFT) $(FILES) -o $(NAME)
