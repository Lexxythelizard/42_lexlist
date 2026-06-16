/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:11:47 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:55:42 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_reindex() takes a pointer to (first) node and reassinging idx 
in ascending order started with 0
returns number of reindexed nodes

headless_count() takes a pointer to any node and 
counts the nodes from node to end
return number of counted nodes
*/

// --- define ---

int	headless_reindex(t_node *first)
{
	int		i;
	t_node	*ptr;

	i = 0;
	if (!first)
		return (-1);
	ptr = first;
	ptr -> idx = 0;
	while (ptr -> next)
	{
		i++;
		ptr = ptr -> next;
		ptr -> idx = i;
	}
	return (i + 1);
}

int	headless_count(t_node *node)
{
	int		count;
	t_node	*ptr;

	count = 0;
	ptr = node;
	if (!ptr)
		return (-1);
	while (ptr)
	{
		count++;
		ptr = ptr -> next;
	}
	return (count);
}
