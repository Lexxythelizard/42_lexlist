/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_by_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:29:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/10 18:22:21 by lenivorb         ###   ########.fr       */
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

void	*list_by_index(t_head *head, int idx);

// --- define ---

/* ...comment...*/

void	*list_by_index(t_head *head, int idx)
{
	t_node	*ptr;

	if ((!head) || (idx < 0) || (idx > head -> len - 1))
		return (NULL);
	ptr = head -> tail;
	while (ptr)
	{
		if (idx == ptr -> idx)
			return (ptr -> content);
		ptr = ptr -> next;
	}
	return (ptr);
}
