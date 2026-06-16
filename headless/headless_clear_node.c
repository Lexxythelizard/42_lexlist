/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_clear_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:16:35 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:38:36 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../struct/lists.h"
#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_clear_node() iterates removes (frees and NULL sets) 
the parsed node incl its content
takes a pointer to pointer to node and a pointer to func del_content

RETURNS:

    int:    number of removed nodes / -1 if fails

*/

// --- define ---

int	headless_clear_node(t_node **node, void (*del_content)(void*))
{
	int	idx;

	if ((!node) || (!del_content))
		return (-1);
	idx = rm_node(*node, del_content);
	*node = NULL;
	return (idx);
}
