/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init_basicfunc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:27:59 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 14:42:58 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "lists.h"
#include "list_core.h"
#include "methods.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

t_basicfunc	*list_assign_basicfunc(void);

// --- define ---

t_basicfunc	*list_assign_basicfunc(void)
{
	t_basicfunc	*new;

	new = init_empty_basicfunc();
	if (!new)
		return (NULL);
	assign_list_append(new, &list_append);
	assign_list_by_idx(new, &list_by_idx);
	assign_list_insert(new, &list_insert);
	assign_list_pop_idx(new, &list_pop_by_index);
	assign_list_pop(new, &list_pop);
	return (new);
}
