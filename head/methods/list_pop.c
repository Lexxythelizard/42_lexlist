/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:41:30 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/18 16:55:06 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
lexlist__pop() takes a pointer to head and 
returns the content of the last element in list
element will be removed from list
automaticly updates head -> len and head -> tip
*/

// --- define ---

void	*lexlist__pop(t_head *self)
{
	void	*content;
	t_node	*ptr;

	if (!self)
		return (NULL);
	if ((!(self -> tail)) || (!(self -> tip)))
		return (NULL);
	content = self -> tip -> content;
	self -> len--;
	if (self -> tail == self -> tip)
	{
		free (self -> tail);
		self -> tail = NULL;
		self -> tip = NULL;
		return (content);
	}
	ptr = headless_by_idx(self -> tail, (self -> len - 1));
	ptr -> next = NULL;
	free (self -> tip);
	self -> tip = ptr;
	return (content);
}
