/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_core.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:04:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/09 13:29:51 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_CORE_H
# define LIST_CORE_H

// --- include ---

# include "../struct/lists.h"
# include <stdlib.h>

// --- DOC ---

/*
    This header contains the 'hidden' functions 
    to interact with the struct t_node and t_head
    includes 
    - "../struct/lists.h"
    - <stdlib.h>

    following functions are used in library functions, but will not be
    directly available in "lexlist" library
*/

// --- prototype ---

// head utils
t_head		*init_empty_head(void);
t_head		*init_head(t_head *new, void *info);
t_head		*init_new_head(void *info);
t_head		*del_head(t_head *head, void (*del_info)(void*));
int			rm_head(t_head *head, void (*del_info)(void*));
// node utils
t_node		*init_empty_node(void);
t_node		*init_node(t_node *node, void *content, int idx);
t_node		*init_new_node(void *content);
t_node		*del_node(t_node *node, void (*rm_content)(void*));
int			rm_node(t_node *node, void (*rm_content)(void*));

// --- end ---

#endif
