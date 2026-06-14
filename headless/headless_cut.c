/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_cut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/09 17:30:31 by lenivorb         ###   ########.fr       */
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

t_node	*headless_cut(t_node **node, int idx);

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
