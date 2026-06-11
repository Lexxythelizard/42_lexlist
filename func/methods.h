/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:59:32 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 16:30:48 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METHODS_H
# define METHODS_H

// --- include ---

# include "lists.h"

// --- DOC ---

/*
	...you comment here...
*/

// --- prototype ---

int		list_append(t_head *head, void *content);
void	*list_by_idx(t_head *head, int idx);
int		list_insert(t_head *head, void *content, int idx);
void	*list_pop_by_index(t_head *head, int idx);
void	*list_pop(t_head *head);

void	assign_list_append(
			t_basicfunc *basicsfunc,
			int *(f)(t_head*, void*));
void	assign_list_by_idx(
			t_basicfunc *basicsfunc,
			void *(f)(t_head*, int));
void	assign_list_insert(
			t_basicfunc *basicsfunc,
			int (f)(t_head*, void*, int));
void	assign_list_pop_idx(
			t_basicfunc *basicsfunc,
			void *(f)(t_head*, int));
void	assign_list_pop(
			t_basicfunc *basicsfunc,
			int (f)(t_head*, void*, int));

// --- end ---

#endif
