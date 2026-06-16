/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:25:15 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:26:44 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_add_front() takes the node and make it the first node of the list
takes a pointer to the pointer of the (old) first node
appends the old first node:

	new -> next = *node

RETURN:

    pointer to new

*/

// --- prototype ---

t_node	*headless_add_front(t_node **node, t_node *new);

// --- define ---

t_node	*headless_add_front(t_node **node, t_node *new)
{
	if ((!node) || (!new))
		return (NULL);
	new -> next = *node;
	*node = new;
	return (new);
}
