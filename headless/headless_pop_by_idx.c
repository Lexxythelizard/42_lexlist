/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_pop_by_idx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/09 19:11:16 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../struct/lists.h"
#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

t_node	*headless_pop_by_index(t_node **node, int idx);

// --- define ---

/*	...you comment... */

t_node	*headless_pop_by_index(t_node **node, int idx)
{
	t_node	*popped;

	if ((!node) || (!(*node)) || (idx < 0))
		return (NULL);
	popped = headless_by_idx(*node, idx);
	if (idx)
		(headless_by_idx(*node, (idx - 1)))-> next = popped -> next;
	else 
		(*node)->next = popped -> next;
	popped -> next = NULL;
	return (popped);
}
