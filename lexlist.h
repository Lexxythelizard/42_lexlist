/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:59:32 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/15 17:46:23 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXLIST_H
# define LEXLIST_H

// --- include ---

# include "./struct/lists.h"
# include <stddef.h>

// --- DOC ---

/*
	...you comment here...
*/

// --- prototype ---

// create and interact

int		lexlist__append(
			t_head *self,
			void *content);

void	*lexlist__get(
			t_head *self,
			int idx);

t_head	*lexlist__init(
			void *info);

int		lexlist__insert(
			t_head *self,
			void *content,
			int idx);

void	*lexlist__pop_idx(
			t_head *self, int idx);

void	*lexlist__pop(
			t_head *self);

// delete functions

int		lexlist__del(
			t_head *self,
			void (*rm_info)(void*),
			void (*rm_content)(void*));

int		lexlist__rm(
			t_head **self,
			void (*rm_info)(void*),
			void (*rm_content)(void*));

void	**lexlist__strip(
			t_head **self,
			void (*rm_info)(void*));

int		lexlist__del_simple(
			t_head *self);

int		lexlist__remove_simple(
			t_head **self);

void	**lexlist__strip_simple(
			t_head **self);

// headless function

t_node	*headless_init_new_list(
		void *content);

void	headless_add_back(
			t_node **node,
			t_node *new);

t_node	*headless_add_front(
			t_node **node,
			t_node *new);

t_node	*headless_by_idx(
			t_node *node,
			int idx);

t_node	*headless_last(
			t_node *node);

t_node	*headless_pop_by_index(
			t_node **node,
			int idx);

t_node	*headless_pop(
			t_node **node);

int		headless_clear_node(
			t_node **node,
			void (*del_content)(void*));

int		headless_clear_node_simple(
			t_node **node);

int		headless_clear_list(
			t_node **node,
			void (*del_content));

int		headless_clear_list_simple(
			t_node **node);

t_node	*headless_cut(
			t_node **node,
			int idx);

int		headless_reindex(
			t_node *first);

int		headless_count(
			t_node *node);

// --- end ---

#endif
