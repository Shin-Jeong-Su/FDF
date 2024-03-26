NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
DBG = -g -fsanitize=address
IFLAGS = -I include
DEPFLAGS = -MMD -MP
RM = rm -rf

SRC = main\
		init_fdf\
		parse_map\
		parse_map_utils\
		display\
		display_utils\
		init_point\
		draw\
		malloc\
		my_deque\
		my_deque2
SRCS = $(addprefix ./mandatory_src/, $(addsuffix .c,$(SRC)))
OBJS = $(addprefix ./mandatory_src/, $(addsuffix .o,$(SRC)))
DEPS = $(addprefix ./mandatory_src/, $(addsuffix .d,$(SRC)))

SRC_BONUS = main\
		init_fdf\
		parse_map\
		parse_map_utils\
		display_bonus\
		display_utils\
		init_point\
		draw\
		event_bonus\
		event_bonus2\
		rotation\
		malloc\
		my_deque\
		my_deque2
SRCS_BONUS = $(addprefix ./bonus_src/, $(addsuffix .c,$(SRC_BONUS)))
OBJS_BONUS = $(addprefix ./bonus_src/, $(addsuffix .o,$(SRC_BONUS)))
DEPS_BONUS = $(addprefix ./bonus_src/, $(addsuffix .d,$(SRC_BONUS)))
LIB = ./libft/libft.a

all : mandatory

mandatory : $(OBJS) $(LIB)
	@$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)
	@if [ -e bonus ]; then \
		rm bonus; \
	fi
	@touch mandatory
	@echo "Made fdf"
-include $(DEPS)

bonus : $(OBJS_BONUS) $(LIB)
	@$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)
	@if [ -e mandatory ]; then \
		rm mandatory; \
	fi
	@touch bonus
	@echo "Made fdf bonus"
-include $(DEPS_BONUS)

d : $(LIB)
	@$(CC) $(DBG) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ $(SRCS) -o $(NAME)

bonus_d : $(LIB)
	@$(CC) $(DBG) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ $(SRCS_BONUS) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	
$(LIB) : 
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft

clean :
	@$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS) mandatory bonus
	@$(MAKE) clean -C ./libft
	@echo "cleaned"

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft
	@echo "fcleaned"

re : fclean all
