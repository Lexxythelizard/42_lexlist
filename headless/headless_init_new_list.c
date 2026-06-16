/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headless_init_new_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:59:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 14:45:56 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/list_core.h"
#include "../lexlist.h"

// --- DOC ---

/*
headless_init_new_list() takes a pointer to content and 
returs a pointer to new begin of ne list
only headless which is meant to takes a pointer to content
*/

// --- define ---

t_node	*headless_init_new_list(void *content)
{
	t_node	*new;

	if ((!content))
		return (NULL);
	new = init_new_node(content);
	if (!(new))
		return (NULL);
	return (new);
}
