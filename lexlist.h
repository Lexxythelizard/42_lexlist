/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:59:32 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/09 20:25:23 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXLIST_H
# define LEXLIST_H

// --- include ---

# include "lists.h"

// --- DOC ---

/*
	...you comment here...
*/

// --- Makros ---

# define YOUR_MAKRO 161

// --- prototype ---

/*following six functions need to get implemented (not in headless)*/
int		list_append(t_head *head, void *content);
void	*list_by_idx(t_head *head, int idx);
int		list_insert(t_head *head, void *content, int idx);
void	*list_last(t_head *head);
void	*list_pop_by_index(t_head *head, int idx);
void	*list_pop(t_head *head);

void	headless_add_back(t_node **node, t_node *new);
void	headless_add_front(t_node **node, t_node *new);
t_node	*headless_by_idx(t_node *node, int idx);
t_node	*headless_last(t_node *node);
t_node	*headless_pop_by_index(t_node **node, int idx);
t_node  *headless_pop(t_node **node);

int		headless_clear_node(t_node **node, void (*del_content)(void*));
int		headless_clear_list(t_node **node, void (*del_content));
t_node  *headless_cut(t_node **node, int idx);
int		headless_reindex(t_node *first);
int		headless_count(t_node *node);
// --- end ---

#endif

