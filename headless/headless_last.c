/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:47:33 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_last() takes a pointer to any node in the list and 
iterates through it until it reaches the end

RETURN:

	t_node*	:	pointer to last node
*/

// --- define ---

t_node	*headless_last(t_node *node)
{
	if (!node)
		return (NULL);
	while (node -> next)
		node = node -> next;
	return (node);
}
