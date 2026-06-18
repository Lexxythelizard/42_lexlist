/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_by_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:29:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/10 18:22:21 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
lexlist__get() takes pointer to head and idx
returns pointer to content of element with idx: idx if found else NULL
list remains unchanged
*/

// --- define ---

void	*lexlist__get(t_head *self, int idx)
{
	t_node	*ptr;

	if ((!self) || (idx < 0) || (idx > self -> len - 1))
		return (NULL);
	ptr = self -> tail;
	while (ptr)
	{
		if (idx == ptr -> idx)
			return (ptr -> content);
		ptr = ptr -> next;
	}
	return (ptr);
}
