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

# include "lists.h"

// --- DOC ---

/*
	...you comment here...
*/

// --- prototype ---

// head utils
t_head		*init_head(t_head *new, void *info, void *basicfunc);
t_head		*init_head(t_head *new, void *info, void *basicfunc);
t_head		*init_new_head(void *info, void *basicfunc);
t_head		*del_head(t_head *head, void (*del_info)(void*));
int			rm_head(t_head *head, void (*del_info)(void*));
// node utils
t_node		*init_empty(void);
t_node		*init_node(t_node *node, void *content, int idx);
t_node		*init_new_list(void *content);
t_node		*del_node(t_node *node, void (*rm_content)(void*));
int			rm_node(t_node *node, void (*rm_content)(void*));
// basicfunc utils
t_basicfunc	*init_empty_basicfunc(void);
t_basicfunc	*init_basicfunc(t_basicfunc *new,
				void *(*append)(t_node**, void*),
				void *(*by_index)(s_node*, int),
				void *(*last)(s_node*),
				void *(*pop)(s_basic_func**));
t_basicfunc	*init_new_basicfunc(
				void *(*append)(t_node**, void*),
				void *(*by_index)(s_node*, int),
				void *(*last)(s_node*),
				void *(*pop)(s_basic_func**));
t_basicfumc	*del_basicfunc(t_basicfunc *basicfunc);
int			rm_basicfunc(t_basicfunc **basicfunc);

// --- end ---

#endif
