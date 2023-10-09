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
NAME_BONUS = cub3d_bonus

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
		mandatory/operations/no_leak.c\
		mandatory/operations/file.c\
		mandatory/operations/file2.c\
		mandatory/operations/rgb_utils.c\
		mandatory/operations/map_utils.c\
		mandatory/operations/map_utils2.c\
		mandatory/operations/check.c\
		mandatory/operations/check2.c\
		mandatory/operations/minimap.c\
		mandatory/operations/movement.c\
		mandatory/operations/game.c\
		mandatory/operations/game2.c\
		mandatory/operations/game3.c\
		mandatory/operations/key_handle.c\
		mandatory/operations/close_window.c\
		mandatory/operations/init.c\
		mandatory/operations/init2.c\
		mandatory/operations/error.c\
		mandatory/operations/direction.c\
		mandatory/operations/xpm_files.c\
		mandatory/operations/draw.c\

SRCS_BONUS = bonus/main_bonus.c\
			bonus/operations/utils_bonus.c\
			bonus/operations/utils2_bonus.c\
			bonus/operations/free_bonus.c\
			bonus/operations/free2_bonus.c\
			bonus/operations/no_leak_bonus.c\
			bonus/operations/file_bonus.c\
			bonus/operations/file2_bonus.c\
			bonus/operations/rgb_utils_bonus.c\
			bonus/operations/map_utils_bonus.c\
			bonus/operations/map_utils2_bonus.c\
			bonus/operations/check_bonus.c\
			bonus/operations/check2_bonus.c\
			bonus/operations/minimap_bonus.c\
			bonus/operations/movement_bonus.c\
			bonus/operations/game_bonus.c\
			bonus/operations/game2_bonus.c\
			bonus/operations/game3_bonus.c\
			bonus/operations/key_handle_bonus.c\
			bonus/operations/close_window_bonus.c\
			bonus/operations/init_bonus.c\
			bonus/operations/init2_bonus.c\
			bonus/operations/error_bonus.c\
			bonus/operations/direction_bonus.c\
			bonus/operations/xpm_files_bonus.c\
			bonus/operations/draw_bonus.c\

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MFLAGS) -o $(NAME) -lm
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

bonus: $(OBJS_BONUS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MINILIBX) $(MFLAGS) -o $(NAME_BONUS) -lm
	@mkdir -p obj_bonus
	@mv $(OBJS_BONUS) obj_bonus/
	clear
	echo "$(BLUE) ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ $(RESET)"
	echo "$(WHITE)██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗$(RESET)"
	echo "$(BLUE)██║     ██║   ██║██████╔╝ █████╔╝██║  ██║$(RESET)"
	echo "$(WHITE)██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║$(RESET)"
	echo "$(BLUE)╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝$(RESET)"
	echo "$(WHITE) ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ $(RESET)"
	echo ""
	echo "$(GREEN)CUB3D_BONUS executable is ready!$(RESET)"

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	@$(RM) -r obj
	echo "$(RED)Object files have been deleted!$(RESET)"

clean_bonus:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS_BONUS)
	@$(RM) -r obj_bonus
	echo "$(RED)Object files from BONUS have been deleted!$(RESET)"

fclean: clean clean_bonus
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) map_temp.map
	clear
	echo "$(RED)Object and Executable files have been deleted!$(RESET)"

re: fclean all

.SILENT:
