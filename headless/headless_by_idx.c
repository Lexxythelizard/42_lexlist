/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_by_idx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/09 18:40:44 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "list.h"
#include "list_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

t_node	*headless_by_idx(t_node *node, int idx);

// --- define ---

/*	...you comment... */

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
