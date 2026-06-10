/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/09 19:00:04 by lenivorb         ###   ########.fr       */
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

t_node	*headless_last(t_node *node);

// --- define ---

/*	...you comment... */

t_node	*headless_last(t_node *node)
{
	if (!node)
		return (NULL);
	while (node -> next)
		node = node -> next;
	return (node);
}
