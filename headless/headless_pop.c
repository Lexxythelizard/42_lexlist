/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/09 20:25:45 by lenivorb         ###   ########.fr       */
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

t_node	*headless_pop(t_node **node);

// --- define ---

/*	...you comment... */

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
	//sec_last = headless_by_idx(*node, (last -> idx - 1));
	sec_last = *node;
	while (sec_last -> next != last)
		sec_last = sec_last -> next;
	sec_last -> next = NULL;
	return (last);
}
