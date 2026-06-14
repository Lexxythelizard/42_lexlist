/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:25:15 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/10 18:25:17 by lenivorb         ###   ########.fr       */
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
