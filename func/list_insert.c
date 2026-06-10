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

#include "lists.h"
#include "lexlist.h"
#include "list_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

int	list_insert(t_head *head, void *content, int idx);

// --- define ---

int	list_insert(t_head *head, void *content, int idx)
{
	t_node	*ptr_pre;
	t_node	*new;

	if ((!head) || (!content) || (idx < 0) || (idx > head -> len))
		return (-1);
	if (idx == head -> len)
		return (list_append(head, content));
	new = init_new_node(content, 0);
	if (!new)
		return (-1);
	if (!idx)
		headless_add_front(&(head -> tail), new);
	else
	{
		new -> next = headless_by_idx(head -> tail, idx);
		ptr_pre = headless_by_idx(head -> tail, (idx - 1));
		ptr_pre -> next = new;
	}
	head -> len = headless_reindex(head -> tail);
	return (head -> len);
}
