/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_clear_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:16:35 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/09 17:14:39 by lenivorb         ###   ########.fr       */
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

int	headless_clear_list(t_node **node, void (*del_content));

// --- define ---

/*	...you comment... */

int	headless_clear_list(t_node **node, void (*del_content))
{
	int		del_nodes;
	t_node	*ptr0;
	t_node	*ptr1;

	if (!node)
		return (-1);
	ptr0 = *node;
	if (!ptr0)
		return (0);
	del_nodes = 1;
	while (ptr0 -> next)
	{
		ptr1 = ptr0 -> next;
		rm_node(ptr0, del_content);
		ptr0 = ptr1;
		del_nodes++;
	}
	if (del_nodes > 1)
	{
		rm_node(ptr0, del_content);
		del_nodes++;
	}
	headless_clear_node(node, del_content);
	return (del_nodes);
}
