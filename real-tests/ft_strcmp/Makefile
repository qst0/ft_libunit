# myoung and mowen

NAME = strcmp_test

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES += 00_ft_strcmp_launcher.c
FILES += 01_ft_strcmp_str1.c
FILES += 02_ft_strcmp_str2.c
FILES += 03_ft_strcmp_str3.c
FILES += 04_ft_strcmp_str4.c
FILES += 05_ft_strcmp_str5.c
FILES += 06_ft_strcmp_str6.c
FILES += 07_ft_strcmp_str7.c
FILES += 08_ft_strcmp_str8.c

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
