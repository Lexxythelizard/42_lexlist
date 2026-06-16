/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_by_idx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:28:53 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_by_idx() takes a pointer to a node (should be first node) 
and loops until it finds the node with the matching index

RETURN:

	pointer to node / NULL if not found

*/

// --- define ---

t_node	*headless_by_idx(t_node *node, int idx)
{
	if ((!node) || (idx < 0))
		return (NULL);
	while (node -> next)
	{
		if (node -> idx == idx)
			return (node);
		node = node -> next;
	}
	return (NULL);
}
