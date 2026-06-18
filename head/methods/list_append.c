/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:44:42 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/10 18:24:26 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
lexlist__append() takes a pointer to head and a void pointerr to content
appends a new element (node) at the end of the list (tail),
assigns idx to new element and updates tip automaticly
*/

// --- define ---

int	lexlist__append(t_head *self, void *content)
{
	t_node	*new;

	if ((!self) || (!content))
		return (-1);
	new = init_empty_node();
	if (!new)
		return (-1);
	init_node(new, content, self -> len);
	if (self -> len)
		self -> tip -> next = new;
	else
		self -> tail = new;
	self -> tip = new;
	self -> len++;
	return (self -> len - 1);
}
