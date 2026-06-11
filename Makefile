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

Core_Dir	= 	./core

Headl_Dir	= 	./headless

Func_Dir	= 	./func

# headers

Includes 	= 	lexlist.h

Incl_Core	=	$(Core_Dir)

Incl_Headl	=	$(Headl_Dir)/backend

Incl_Lib	=	.

Incl_Struct	=	$(Core_Dir)

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

Objects		=	$(Obj_Core) $(Obj_Headl) $(Obj_Func)

# -------------------- include rules --------------------

INCL_CORE	=	$(Include) $(Incl_Core) $(Include) $(Incl_Struct)

INCL_HEADL	=	$(Include) $(Incl_Struct) $(Include) $(Incl_Core) \
				$(Include) $(Incl_Headl)

INCL_FUNC	=	$(Include) $(Incl_Struct) $(Include) $(Incl_Core) \
				$(Include) $(Incl_Headl) $(Include) $(Incl_Func)

# -------------------- compile rules --------------------

$(Obj_Core): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(Flags) $(Dont_link) $(Debugg_mode) $(INCL_CORE) $< $(Dest) $@; \
	else \
		$(Compile) $(Flags) $(Dont_link) $(INCL_CORE) $< $(Dest) $@; \
	fi

$(Obj_Headl): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(Flags) $(Dont_link) $(Debugg_mode) $(INCL_HEADL) $< $(Dest) $@; \
	else \
		$(Compile) $(Flags) $(Dont_link) $(INCL_HEADL) $< $(Dest) $@; \
	fi

$(Obj_Func): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(Flags) $(Dont_link) $(Debugg_mode) $(INCL_FUNC) $< $(Dest) $@; \
	else \
		$(Compile) $(Flags) $(Dont_link) $(INCL_FUNC) $< $(Dest) $@; \
	fi

# -------------------- commands --------------------

all : $(NAME)

re : fclean $(NAME)

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

create_core: $(Obj_Core)

# --------> Headless

create_headl: $(Obj_Headl)

# --------> List

create_func: $(Obj_Func)

# -------------------- PHONY --------------------

.PHONY: all re fclean clean clean_core clean_headl clean_func create_core create_headl create_func
