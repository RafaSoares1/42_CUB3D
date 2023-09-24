RESET   = \033[0m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

NAME = cub3d

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext
RM = rm -rf

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

SRCS = 	mandatory/main.c\
		mandatory/operations/utils.c\
		mandatory/operations/utils2.c\
		mandatory/operations/free.c\
		mandatory/operations/free2.c\
		mandatory/operations/file.c\
		mandatory/operations/file2.c\
		mandatory/operations/rgb_utils.c\
		mandatory/operations/map_utils.c\
		mandatory/operations/map_utils2.c\
		mandatory/operations/check.c\
		mandatory/operations/game.c\
		mandatory/operations/move.c\
		mandatory/operations/close_window.c\
		mandatory/operations/init.c\
		mandatory/operations/error.c\
		

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MFLAGS) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJS) obj/
	clear
	echo "$(BLUE) ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ $(RESET)"
	echo "$(WHITE)██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗$(RESET)"
	echo "$(BLUE)██║     ██║   ██║██████╔╝ █████╔╝██║  ██║$(RESET)"
	echo "$(WHITE)██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║$(RESET)"
	echo "$(BLUE)╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝$(RESET)"
	echo "$(WHITE) ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ $(RESET)"
	echo ""
	echo "$(GREEN)CUB3D executable is ready!$(RESET)"

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	@$(RM) -r obj
	echo "$(RED)Object files have been deleted!$(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME)
	@$(RM) map_temp.map
	clear
	echo "$(RED)Object and Executable files have been deleted!$(RESET)"

re: fclean all

.SILENT:
