NAME		=	rush-02

SRCS		=	src/ft_utils.c src/ft_utils2.c src/parsing.c src/rush02.c src/ft_error.c src/convert_num.c

OBJS		=	$(SRCS:c=o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

INC			=	-I ./includes

all:		$(OBJS) $(NAME)

%.o:		%.c
				@echo "Compiling $<"
				@$(CC) $(CFLAGS) -c $(INC) $< -o $(<:c=o)
				@echo "Compiling OK!"

$(NAME):	$(OBJS)
				@echo "Creating executable $@"
				@cc $(CFLAGS) $^ -o $@
				@echo "Job's done!"
clean:
				@echo "Cleaning objects..."
				@rm -f $(OBJS) $(BONUS_OBJS)
				@echo "Cleaned up!"

fclean:		clean
				@echo "Cleaning..."
				@rm -f $(NAME)
				@echo "Cleaned up!"

re:			fclean all

.PHONY:		all clean fclean re