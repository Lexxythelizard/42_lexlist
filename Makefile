# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/10 19:30:37 by lenivorb          #+#    #+#              #
#    Updated: 2026/06/10 20:01:41 by lenivorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------- variables --------------------

# library name

NAME		= 	./lexlist.a

# for compile

Compile 	= 	cc

Flags 		= 	-Wall -Wextra -Werror

Dont_link 	= 	-c

# directories

Core_Dir	= 	./core

Headl_Dir	= 	./headless

Func_Dir	= 	./func

# headers

Includes 	= 	lexlist.h

Include 	= 	-I $(Includes)

# soruce files

Src_Core	=	$(Core_Dir)/core/nodes.c \
				$(Core_Dir)/core/heads.c \
				$(Core_Dir)/core/basicfunc.c

Src_Headl	=	$(Headl_Dir)/headless_add_back.c \
				$(Headl_Dir)/headless_add_fornt.c \
				$(Headl_Dir)/headless_by_idx.c \
				$(Headl_Dir)/headless_clear_list.c \
				$(Headl_Dir)/headless_clear_node.c \
				$(Headl_Dir)/headless_cut.c \
				$(Headl_Dir)/headless_pop.c \
				$(Headl_Dir)/headless_pop_by_idx.c \
				$(Headl_Dir)/headless_utils.c

Src_Func	=	$(Func_Dir)/list_append.c \
				$(Func_Dir)/list_by_index.c \
				$(Func_Dir)/list_insert.c \
				$(Func_Dir)/list_pop.c \
				$(Func_Dir)/list_pop_by_index.c

Obj_Core 	=	$(Src_Core:.c=.o)

Obj_Headl 	=	$(Src_Headl:.c=.o)

Obj_Func	=	$(Src_Func:.c=.o)

# -------------------- commands --------------------

all : $(NAME)

re : fclean $(name)

fclean: clean
	rm -f $(NAME)

clean: clean_core clean_headl clean_func

clean_core:
	rm -f $(Obj_Core) $@

clean_headl:
	rm -f $(Obj_Headl) $@

clean_func:
	rm -f $(Obj_Func) $@

# -------------------- library --------------------

# !!! UNDER CONSTRUCTION !!!

$(NAME) : $(Objects) $(Includes)
	ar rcs $(NAME) $(Objects)

# -------------------- object files --------------------

# --------> Core

create_core: $(Src_Core) $(Includes_Core)
	echo "under construction"

# --------> Headless

create_headl: $(Src_Headl) $(Includes_Headl)
	echo "under construction"

# --------> List

create_func: $(Src_Func) $(Includes_Func)
	echo "under construction"

# -------------------- PHONY --------------------

.PHONY: all re fclean clean clean_core clean_headl clean_func create_core create_headl create_func
