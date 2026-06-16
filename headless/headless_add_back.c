/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:23:31 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
add_node_back() takes the node and bassicly added it to the back of the list
takes a pointer to the pointer of the current /first node
if first node is NULL it makes new node first node

RETURN:

	---
*/

// --- define ---

void	headless_add_back(t_node **node, t_node *new)
{
	t_node	*ptr;

	if ((!node) || (!new))
		return ;
	ptr = *node;
	if (!(*node))
	{
		*node = new;
		return ;
	}
	while (ptr -> next)
		ptr = ptr -> next;
	ptr -> next = new;
	headless_reindex(*node);
}
