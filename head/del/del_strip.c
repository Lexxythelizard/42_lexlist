/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_strip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/18 17:29:48 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
strip_tail() takes a pointer to pointer to head and a function pointer to
rm_info is mean to delete (frees the head -> info)
iteratyvely removes all elements of head -> tail, 
but stores it contents in NULL terminated void** array
returns void **content

use lexlist__strip_simple() for easy freable info variables

*/

// --- prototype ---

static void	**strip_tail(t_head *head);

// --- define ---

void	**lexlist__strip(t_head **self, void (*rm_info)(void*))
{
	void	**strip;

	if ((!self) || (!(*self)) || (!rm_info))
		return (NULL);
	strip = strip_tail(*self);
	if (!strip)
		return (NULL);
	rm_head(*self, rm_info);
	*self = NULL;
	return (strip);
}

static void	**strip_tail(t_head *head)
{
	t_node	*ptr;
	void	**strip;
	int		i;

	if (!head)
		return (NULL);
	if (!(head -> tail))
		return (NULL);
	i = 0;
	strip = malloc((head -> len + 1) * 8);
	if (!strip)
		return (NULL);
	ptr = head -> tail;
	while ((head -> tail) && (i < (head -> len)))
	{
		ptr = head -> tail -> next;
		strip[i] = (head -> tail -> content);
		free(head -> tail);
		head -> tail = ptr;
		i++;
	}
	strip[i] = NULL;
	head -> tip = NULL;
	head -> len = 0;
	return (strip);
}
