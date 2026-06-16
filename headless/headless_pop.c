/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:52:25 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_pop() takes a pointer to pointer to node
pops the last node node and assigning previous -> next = NULL

RETURN:

    t_node* :   pointer to popped node

*/

// --- define ---

t_node	*headless_pop(t_node **node)
{
	t_node	*last;
	t_node	*sec_last;

	if ((!node) || (!(*node)))
		return (NULL);
	if (!((*node)->next))
	{
		last = *node;
		*node = NULL;
		return (last);
	}
	last = headless_last(*node);
	sec_last = *node;
	while (sec_last -> next != last)
		sec_last = sec_last -> next;
	sec_last -> next = NULL;
	return (last);
}
