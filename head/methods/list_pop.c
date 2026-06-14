/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:41:30 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/10 17:10:47 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../struct/lists.h"
#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

void	*lexlist__pop(t_head *self);

// --- define ---

void	*lexlist__pop(t_head *self)
{
	void	*content;
	t_node	*ptr;

	if (!self)
		return (NULL);
	if ((!(self -> tail)) || (!(self -> tip)))
		return (NULL);
	ptr = self -> tail;
	content = self -> tip -> content;
	self -> len--;
	if (self -> tail == self -> tip)
	{
		free (self -> tail);
		self -> tail = NULL;
		self -> tip = NULL;
		return (content);
	}
	while (ptr -> next != self -> tail)
		ptr = ptr -> next;
	ptr -> next = NULL;
	free (self -> tip);
	self -> tip = ptr;
	return (content);
}
