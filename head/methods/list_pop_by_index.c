/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_by_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:41:30 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/18 17:01:43 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
lexlist__pop_idx() takes a pointer to head and 
returns the content of the last element with idx: idx in list
element will be removed from list, without breaking the list
(works like headless_pop_idx, but just returns content and frees the node)
automaticly updates head -> len and head -> tip and reindexes all elements
*/

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
