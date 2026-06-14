/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/09 18:38:07 by lenivorb         ###   ########.fr       */
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

void	headless_add_back(t_node **node, t_node *new);

// --- define ---

/*add_node_back() takes the node and bassicly added it to the back of the list*/

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
