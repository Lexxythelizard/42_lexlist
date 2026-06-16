/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_clear_node_simple.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:16:35 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:39:55 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_clear_node_simple() does the same headless_clear_node() does 
it takes a pointer to pointer to node 
and parsing it with &free to headless_clear_node()

RETURNS:

    int:    number of removed nodes / -1 if fails

*/

// --- define ---

int	headless_clear_node_simple(t_node **node)
{
	return (headless_clear_node(node, &free));
}
