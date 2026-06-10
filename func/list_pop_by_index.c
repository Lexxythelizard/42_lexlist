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

#include "lists.h"
#include "lexlist.h"
#include "list_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

void	*list_pop_by_index(t_head *head, int idx);

// --- define ---

void	*list_pop_by_index(t_head *head, int idx)
{
	void	*content;
	t_node	*ptr;
	t_node	*ptr_pre;

	if ((!head) || (idx < 0) || (idx >= head -> len))
		return (NULL);
	if ((!(head -> tail)) || (!(head -> tip)))
		return (NULL);
	if (idx == (head -> len - 1))
		return (list_pop(head));
	ptr = headless_by_idx(head -> tail, idx);
	ptr_pre = headless_by_idx(head -> tail, (idx - 1));
	if ((!ptr) || !(ptr_pre))
		return (NULL);
	if (!idx)
		head -> tail = ptr -> next;
	else
		ptr_pre -> next = ptr -> next;
	content = ptr -> content;
	free(ptr);
	head -> len--;
	headless_reindex(head -> tail);
	return (content);
}
