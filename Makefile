# Created: 2020/11/02

NAME = libasm.a

FLAG = -Wall -Werror -Wextra

SRCS = ft_strlen.s\
	ft_strcpy.s\
	ft_strcmp.s\
	ft_write.s\
	ft_read.s\
	ft_strdup.s

OBJS = $(SRCS:.s=.o)

%.o:	%.s
	@nasm -f macho64 $<

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@rm -f test

fclean: clean
	@rm -f $(NAME)
	@rm -f hello.txt
	
re: fclean all

test: $(NAME)
	@gcc $(FLAG) -L. -lasm  main.c $(OBJS) -o $(NAME)
	@./$(NAME)