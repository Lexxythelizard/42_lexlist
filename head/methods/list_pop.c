/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:41:30 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/18 13:45:24 by lenivorb         ###   ########.fr       */
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
