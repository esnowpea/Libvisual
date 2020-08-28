#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esnowpea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 12:48:11 by esnowpea          #+#    #+#              #
#    Updated: 2019/12/27 20:21:42 by esnowpea         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Lib_Visual
NAME_EXEC = libvisual.a
TABS = \t

CC = gcc
FLAGS = -O2 -Wall -Werror -Wextra
LIB_FLAGS = -L$(LIBFT_DIR) -lft -L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit

INCLUDES = -I$(HEADERS_DIR) -I$(LIBMLX_HEADERS) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ../../Libft/
LIBFT_HEADERS = $(LIBFT_DIR)inc/

LIBMLX = $(LIBMLX_DIR)libmlx.a
LIBMLX_DIR = ./minilibx_macos/
LIBMLX_HEADERS = $(LIBMLX_DIR)

HEADERS_LIST = $(NAME).h
HEADERS_DIR = ./inc/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = src/
SRC_LIST =	set_point.c \
			set_color.c \
			img_get_color.c \
			img_pixel_put.c \
			img_line_put.c \
			img_triangle_put.c \
			img_rectangle_put.c \
			img_ring_put.c \
			init_visual.c \
			int_to_color.c \
			print_img_to_win.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

all: $(NAME_EXEC)

$(NAME_EXEC): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME_EXEC) $(OBJ)
	@ranlib $(NAME_EXEC)
	@echo "\n$(NAME):$(TABS)$(GRN)library created$(END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME):$(TABS)$(GRN)$(OBJ_DIR) created$(END)"

$(LIBFT):
	@echo "$(NAME):$(TABS)$(GRN)Creating $(LIBFT)...$(END)"
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
ifneq ($(strip $(wildcard $(OBJ))),)
	@echo "$(NAME):$(TABS)$(RED)*.o files deleted$(END)"
	@echo "$(NAME):$(TABS)$(RED)$(OBJ_DIR) deleted$(END)"
endif

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME_EXEC)
ifneq ($(strip $(wildcard $(NAME_EXEC))),)
	@echo "$(NAME):$(TABS)$(RED)$(NAME_EXEC) deleted$(END)"
endif

re: fclean all
