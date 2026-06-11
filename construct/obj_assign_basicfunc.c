/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_assign_basicfunc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:55:56 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 14:21:52 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "lists.h"
#include "core_list.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

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

// --- define ---

void	assign_list_append(
			t_basicfunc *basicsfunc,
			int *(f)(t_head*, void*))
{
	if ((!basicfunc) || (!f))
		return ;
	basicfunc -> append = f;
	return ;
}

void	assign_list_by_idx(
			t_basicfunc *basicsfunc,
			void *(f)(t_head*, int))
{
	if ((!basicfunc) || (!f))
		return ;
	basicfunc -> get = f;
	return ;
}

void	assign_list_insert(
		t_basicfunc *basicsfunc,
		int (f)(t_head*, void*, int))
{
	if ((!basicfunc) || (!f))
		return ;
	basicfunc -> insert = f;
	return ;
}

void	assign_list_pop_idx(
			t_basicfunc *basicsfunc,
			void *(f)(t_head*, int))
{
	if ((!basicfunc) || (!f))
		return ;
	basicfunc -> pop_idx = f;
	return ;
}

void	assign_list_pop(
			t_basicfunc *basicsfunc,
			int (f)(t_head*, void*, int))
{
	if ((!basicfunc) || (!f))
		return ;
	basicfunc -> pop = f;
	return ;
}
