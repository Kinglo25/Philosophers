NAME		=	philo

SRCS		=	srcs/main.c srcs/init.c \
				srcs/utils.c srcs/utils1.c srcs/philo.c

OBJS		=	$(SRCS:c=o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -fsanitize=thread -g

INC			= 	-I./inc/

all:			$(OBJS) $(NAME)

%.o:		%.c
				@echo "Compiling $<"
				@$(CC) $(CFLAGS) -c $(INC) $< -o $(<:c=o)
				@echo "Compiling OK!"

$(NAME):	$(OBJS)
				@echo "Linking $^"
				@cc $(CFLAGS) $^ -o $@ -lpthread 
				@echo "Executable created!"
clean:
				@echo "Cleaning objects..."
				@rm -f $(OBJS) $(BONUS_OBJS)
				@echo "Cleaned up!"

fclean:		clean
				@echo "Removing executable..."
				@rm -f $(NAME)
				@echo "Removed!"

re:			fclean all

.PHONY:		all clean fclean re