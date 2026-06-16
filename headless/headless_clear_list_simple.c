/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_clear_list_simple.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:16:35 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:39:06 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_clear_list_simple() does the same headless_clear_list() does 
it takes a pointer to pointer to (first) node 
and parsing it with &free to headless_clear_list()

RETURNS:

    int:    number of removed nodes	/ -1 if fails

*/

// --- prototype ---

int	headless_clear_list_simple(t_node **node);

// --- define ---

/*	...you comment... */

int	headless_clear_list_simple(t_node **node)
{
	return (headless_clear_list(node, &free));
}
