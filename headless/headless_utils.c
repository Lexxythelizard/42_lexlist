/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:11:47 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/09 20:19:01 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "lists.h"
#include "list_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

int	headless_reindex(t_node *first);
int headless_count(t_node *node);

// --- define ---

/*	...you comment... */

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
		ptr = node -> next;
		ptr -> idx = i;
	}
	return (i);
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
