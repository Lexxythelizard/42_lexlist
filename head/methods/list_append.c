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

#include "../../struct/lists.h"
#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

int	lexlist__append(t_head *self, void *content);

// --- define ---

int	lexlist__append(t_head *self, void *content)
{
	int		i;
	t_node	*new;

	if ((!self) || (!content))
		return (-1);
	new = init_new_node(content, self -> len);
	if (!new)
		return (-1);
	if (self -> len)
		self -> tip -> next = new;
	else
		self -> tail = new;
	self -> tip = new;
	self -> len++;
	return (self -> len - 1);
}
