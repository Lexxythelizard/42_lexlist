/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_clear_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:16:35 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:40:25 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_clear_list() iterates through the list 
and removes (frees and NULL sets) any node incl its content
takes a pointer to pointer of (fist) node and a pointer to func del_content

RETURNS:

	int:	number of removed nodes	/ -1 if fails
*/

// --- define ---

int	headless_clear_list(t_node **node, void (*del_content))
{
	int		del_nodes;
	t_node	*ptr0;
	t_node	*ptr1;

	if ((!node) || (!(*node)))
		return (-1);
	ptr0 = *node;
	del_nodes = 0;
	while (ptr0)
	{
		ptr1 = ptr0 -> next;
		rm_node(ptr0, del_content);
		ptr0 = ptr1;
		del_nodes++;
	}
	*node = NULL;
	return (del_nodes);
}
