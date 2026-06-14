/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:39:22 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/10 18:22:42 by lenivorb         ###   ########.fr       */
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

int	lexlist__insert(t_head *self, void *content, int idx);

// --- define ---

int	lexlist__insert(t_head *self, void *content, int idx)
{
	t_node	*ptr_pre;
	t_node	*new;

	if ((!self) || (!content) || (idx < 0) || (idx > head -> len))
		return (-1);
	if (idx == self -> len)
		return (lexlist__append(self, content));
	new = init_new_node(content, 0);
	if (!new)
		return (-1);
	if (!idx)
		headless_add_front(&(self -> tail), new);
	else
	{
		new -> next = headless_by_idx(self -> tail, idx);
		ptr_pre = headless_by_idx(self -> tail, (idx - 1));
		ptr_pre -> next = new;
	}
	head -> len = headless_reindex(self -> tail);
	return (self -> len);
}
