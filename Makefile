# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/10 19:30:37 by lenivorb          #+#    #+#              #
#    Updated: 2026/06/11 13:51:11 by lenivorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------- variables --------------------

# library name

NAME		= 	./lexlist.a

# MODE

DEBUGG_MODE	=	0

# for compile

Compile 	= 	cc

Flags 		= 	-Wall -Wextra -Werror

Include 	= 	-I

Dont_link 	= 	-c

Dest	 	= 	-o

Debugg_mode	=	-g

# directories

This_Dir	=	.

Core_Dir	= 	$(This_Dir)/core

Struc_Dir	= 	$(This_Dir)/struct

Headl_Dir	= 	$(This_Dir)/headless

Head_Dir	= 	$(This_Dir)/head

Method_Dir	= 	$(Head_Dir)/method

Del_Dir		= 	$(Head_Dir)/del

# headers

User_Lib 	= 	lexlist.h

Incl_This	=	$(Include) $(This_Dir)

Incl_Core	=	$(Include) $(Core_Dir)

Incl_Struct	=	$(Include) $(Struct_Dir)

Incl_Headl	=	$(Include) $(Headl_Dir)

# soruce files

Src_Core	=	$(Core_Dir)/nodes.c \
				$(Core_Dir)/heads.c

Src_Headl	=	$(Headl_Dir)/headless_add_back.c \
				$(Headl_Dir)/headless_add_fornt.c \
				$(Headl_Dir)/headless_by_idx.c \
				$(Headl_Dir)/headless_clear_list.c \
				$(Headl_Dir)/headless_clear_node.c \
				$(Headl_Dir)/headless_cut.c \
				$(Headl_Dir)/headless_last.c \
				$(Headl_Dir)/headless_pop.c \
				$(Headl_Dir)/headless_pop_by_idx.c \
				$(Headl_Dir)/headless_utils.c

Src_Head	=	$(Method_Dir)/list_append.c \
				$(Method_Dir)/list_by_index.c \
				$(Method_Dir)/list_insert.c \
				$(Method_Dir)/list_pop.c \
				$(Method_Dir)/list_pop_by_index.c \
				$(Del_Dir)/del_del.c \
				$(Del_Dir)/del_del_simple.c \
				$(Del_Dir)/del_rm.c \
				$(Del_Dir)/del_rm_simple.c \
				$(Del_Dir)/del_strip.c \
				$(Del_Dir)/del_strip_simple.c

Obj_Core 	=	$(Src_Core:.c=.o)

Obj_Headl 	=	$(Src_Headl:.c=.o)

Obj_Head	=	$(Src_Head:.c=.o)

Objects		=	$(Obj_Core) $(Obj_Headl) $(Obj_Head)

# -------------------- compile rules --------------------

$(Obj_Core): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(Flags) $(Dont_link) $(Debugg_mode) \
		$(Incl_Struct) $(Incl_Core) $< $(Dest) $@; \
	else \
		$(Compile) $(Flags) $(Dont_link) \
		$(Incl_Struct) $(Incl_Core) $< $(Dest) $@; \
	fi

$(Obj_Headl): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(Flags) $(Dont_link) $(Debugg_mode) \
		$(Incl_Struct) $(Incl_Core) $(Incl_This) $< $(Dest) $@; \
	else \
		$(Compile) $(Flags) $(Dont_link) \
		$(Incl_Struct) $(Incl_Core) $(Incl_This) $< $(Dest) $@; \
	fi

$(Obj_Head): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(Flags) $(Dont_link) $(Debugg_mode) \
		$(Incl_Struct) $(Incl_Core) $(Incl_This) $< $(Dest) $@; \
	else \
		$(Compile) $(Flags) $(Dont_link) \
		$(Incl_Struct) $(Incl_Core) $(Incl_This) $< $(Dest) $@; \
	fi

# -------------------- commands --------------------

all : $(NAME)

re : fclean all

fclean: clean
	rm -f $(NAME)

clean: clean_core clean_headl clean_func

clean_core:
	rm -f $(Obj_Core) $@

clean_headl:
	rm -f $(Obj_Headl) $@

clean_head:
	rm -f $(Obj_Head) $@

# -------------------- library --------------------

$(NAME) : $(Objects) $(User_Lib)
	ar rcs $(NAME) $(Objects)

# -------------------- object files --------------------

# --------> Core

create_core: $(Obj_Core)

# --------> Headless

create_headl: $(Obj_Headl)

# --------> List

create_head: $(Obj_Head)

# -------------------- PHONY --------------------

.PHONY: all re fclean clean clean_core clean_headl clean_func create_core create_headl create_func
