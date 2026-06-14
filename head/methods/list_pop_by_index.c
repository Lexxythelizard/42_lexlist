/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_by_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:41:30 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/10 18:23:21 by lenivorb         ###   ########.fr       */
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

void	*lexlist__pop_idx(t_head *self, int idx);

// --- define ---

void	*lexlist__pop_idx(t_head *self, int idx)
{
	void	*content;
	t_node	*ptr;
	t_node	*ptr_pre;

	if ((!self) || (idx < 0) || (idx >= self -> len))
		return (NULL);
	if ((!(self -> tail)) || (!(self -> tip)))
		return (NULL);
	if (idx == (self -> len - 1))
		return (lexlist__pop(self));
	ptr = headless_by_idx(self -> tail, idx);
	ptr_pre = headless_by_idx(self -> tail, (idx - 1));
	if ((!ptr) || !(ptr_pre))
		return (NULL);
	if (!idx)
		self -> tail = ptr -> next;
	else
		ptr_pre -> next = ptr -> next;
	content = ptr -> content;
	free(ptr);
	self -> len--;
	headless_reindex(self -> tail);
	return (content);
}
