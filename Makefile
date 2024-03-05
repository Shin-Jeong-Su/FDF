NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror 
DBG = -g -fsanitize=address
DEPFLAGS = -MMD -MP
RM = rm -rf

SRC = main
SRCS = $(addsuffix .c,$(SRC))
OBJS = $(addsuffix .o,$(SRC))
DEPS = $(addsuffix .d,$(SRC))
LIB = ./libft/libft.a

all : mandatory

mandatory : $(OBJS) $(LIB)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)
	touch mandatory
-include $(DEPS)

d : $(LIB)
	$(CC) $(DBG) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ $(SRCS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	
$(LIB) : 
	$(MAKE) -C ./libft
	$(MAKE) bonus -C ./libft

clean :
	$(RM) $(OBJS) $(DEPS) mandatory
	$(MAKE) clean -C ./libft

fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re : fclean all