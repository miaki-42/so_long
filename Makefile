NAME = so_long

SRCS = main.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

INCS = $(addprefix -I, . libft/include minilibx-linux)
LIBS = -lXext -lX11 -lm

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(LIBS) -o $@

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re