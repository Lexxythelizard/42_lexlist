/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_pop_by_idx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:50:44 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_pop_by_index() takes a pointer to pointer to node and idx
pops the searched nod and 
assigning popped nodes next to the next of previous node:
previous -> next = popped -> next

RETURN:

	t_node*	:	pointer to popped node
*/

// --- define ---

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
