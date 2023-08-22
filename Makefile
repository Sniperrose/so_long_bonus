# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galtange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:11:37 by galtange          #+#    #+#              #
#    Updated: 2022/11/01 16:12:09 by galtange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = ./srcs/
SRCS =	ft_utils.c\
		get_next_line.c\
		ft_getmap.c\
		ft_mapchek.c\
		ft_validpath.c\
		ft_split2.c\
		ft_errors.c\
		solong.c\
		ft_getimages.c\
		ft_moves.c\
		ft_move_hor.c\
		ft_move_ver.c\

SRCS_BONUS_DIR = ./srcs_bonus/
SRCS_BONUS =	ft_errors_bonus.c\
			    ft_getmap_bonus.c\
				ft_moves_bonus.c\
				ft_split2_bonus.c\
				get_next_line.c\
				ft_freeimgs_bonus.c\
				ft_mapchek_bonus.c\
				ft_move_ver_bonus.c\
				ft_utils_bonus.c\
				ft_getimages_bonus.c\
				ft_move_hor_bonus.c\
				ft_showmvs_bonus.c\
				ft_validpath_bonus.c\
				solong_bonus.c\
				ft_sprite_bonus.c\

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}
OBJS_BONUS = ${addprefix ${SRCS_BONUS_DIR}, ${SRCS_BONUS:.c=.o}}

LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

MLX_DIR = minilibx-linux
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
MFLAGS = -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
IFLAGS:= -I ./includes
LFLAGS:= -L $(LIBFT_DIR) -lft

NAME = so_long
NAMEBONUS = so_long_bonus
RM = rm -f

all:	${NAME}		
bonus:	${NAMEBONUS}

$(NAME): $(OBJS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@$(CC) $(CFLAGS) $(OBJS) $(SRCS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS) 

$(NAMEBONUS): $(OBJS_BONUS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(SRCS_BONUS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAMEBONUS) $(MFLAGS) 

clean:
		@${RM} ${OBJS}
		@${RM} -r ${OBJ_DIR} 
		@${RM} ${OBJS_BONUS}
		@${RM} -r ${OBJS_BONUS_DIR} 
		@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} clean

fclean: clean
		@${RM} ${OBJS} ${NAME}
		@${RM} ${OBJS_BONUS} ${NAMEBONUS}

re: 	fclean all

.PHONY: all clean fclean re
