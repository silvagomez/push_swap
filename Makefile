# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 00:04:57 by dsilva-g          #+#    #+#              #
#    Updated: 2023/09/26 17:41:01 by dsilva-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	push_swap

#------------------------------------------------------------------------------#
#   INGREDIENTS                                                                #
#------------------------------------------------------------------------------#

CC				:=	cc
#CFLAGS			:=	-Wall -Wextra -Werror -fsanitize=address -g3
CFLAGS			:=	-Wall -Wextra -Werror -g

INCLUDE_PATH	:=	include/
INCLUDE			:=	$(INCLUDE_PATH)push_swap.h

LIBFT_PATH		:=	libft/
LIBFT			:=	$(LIBFT_PATH)libft.a

SRC_PATH		:=	src/
SRC				:=	\
					main.c \
					validate.c \
					ft_atol.c \
					error.c \
					free_memory.c \
					push_swap.c \
					push.c \
					swap.c \
					rotate.c \
					reverse_rotate.c \
					stack_init_a.c \
					stack_init_nodes.c \
					stack_add_node.c \
					stack_size.c \
					stack_free.c \
					stack_get_lowest_node.c \
					stack_get_highest_node.c \
					stack_get_cheapest_node.c \
					stack_get_last_node.c \
					stack_set_idx.c \
					stack_set_target.c \
					stack_set_move_cost.c \
					stack_set_cheapest.c \
					sort.c \
					r_rr_optimize.c

SRC				:=	$(SRC:%=$(SRC_PATH)%)

OBJ_PATH		:=	obj/
OBJ				:=	$(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

#------------------------------------------------------------------------------#
#   UTENSILS                                                                   #
#------------------------------------------------------------------------------#

RM				:=	rm
RMFLAG			:=	-fr

DIR_DUP			=	mkdir -p $(@D)

#------------------------------------------------------------------------------#
#   RECIPES                                                                    #
#------------------------------------------------------------------------------#

all				:	$(NAME)

$(NAME)			:	$(OBJ) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
					@echo -e "$(MAGENTA)File $(NAME)$(GREEN) compiled!$(WHITE)"

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c
				  	$(DIR_DUP)
					$(CC) $(CFLAGS) -I $(INCLUDE_PATH) -c $< -o $@

$(LIBFT)		:
					make -C $(LIBFT_PATH) all

clean			:
					make -C $(LIBFT_PATH) clean
					$(RM) $(RMFLAG) $(OBJ_PATH)
					@echo -e "$(MAGENTA)Removing fdf files... $(GREEN)done!$(WHITE)"

fclean			:	clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(RMFLAG) $(NAME)
					@echo -e "$(MAGENTA)Removing $(NAME) $(GREEN)done!$(WHITE)"

re				:	fclean all

norm			:
					norminette $(LIBFT_PATH) $(SRC_PATH) $(INCLUDE_PATH)

#------------------------------------------------------------------------------#
#   SPEC                                                                       #
#------------------------------------------------------------------------------#

.PHONY			:	all clean fclean re bonus

#------------------------------------------------------------------------------#
#   COLORS                                                                     #
#------------------------------------------------------------------------------#

GREEN			:=	\033[92m
BLUE			:=	\033[94m
MAGENTA			:=	\033[95m
WHITE			:=	\033[97m

#********************************************************************* END ****#
