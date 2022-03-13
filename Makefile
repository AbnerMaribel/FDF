NAME	= fdf

# Colors
WHITE	=	\033[00m
RED		=	\033[01;31m
BLUE	=	\033[01;34m
MAGENTA	=	\033[01;35m
CYAN	=	\033[01;36m

SRCS	= 	main.c ft_free.c reading_file.c draw.c gradient.c utils.c rotate.c data_init.c\
 			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

LIB 	= ./libft/libft.a

HEADER  = fdf.h ./libft/libft.h ./get_next_line/get_next_line.h

RM		= rm -f
		 
OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

$(NAME):	$(OBJS) $(HEADER)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) $(LIB)  -o ${NAME}
	@echo "🦋$(RED)F$(MAGENTA)D$(BLUE)F $(CYAN)compiled $(WHITE)🦋"

%.o : %.c
	@$(CC) -Imlx -c $< -o $@

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BOBJS)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME) $(LIB)

re:			fclean all

.PHONY:		all clean fclean re