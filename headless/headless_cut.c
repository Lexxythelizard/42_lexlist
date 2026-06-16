/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_cut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:44:59 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_cut()
it takes a pointer to pointer to node and the idx of the node 
which it should cut
calls headless_by_idx(); sets headless_by_idx(node, idx - 1) -> next = NULL

RETURNS:

    t_node*:    pointer to cut of list

*/

// --- define ---

t_node	*headless_cut(t_node **node, int idx)
{
	t_node	*lst;
	t_node	*before;

	if ((!node) || (!(*node)) || (idx < 0))
		return (NULL);
	if (!idx)
	{
		lst = *node;
		*node = NULL;
		return (lst);
	}
	lst = headless_by_idx(*node, idx);
	before = headless_by_idx(*node, (idx - 1));
	if (before)
		before -> next = NULL;
	return (lst);
}
