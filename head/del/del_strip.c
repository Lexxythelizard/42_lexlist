/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 16:44:53 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "lists.h"
#include "list_core.h"
#include "methods.h"

// --- DOC ---

/*
*/

// --- prototype ---

static void	*strip_tail(t_head *head);

// --- define ---

void	*lexlist__strip(t_head **self, void (*rm_info)(void*))
{
	void	*strip;
	t_node	*ptr;
	int		i;

	if ((!self) || (!(*self)) || (!rm_info))
		return (NULL);
	strip = strip_tail(*self);
	if (!strip)
		return (NULL);
	rm_head(*self, rm_info);
	*self = NULL;
	return (strip);
}

/*	...comment...*/

static void	strip_tail(t_head *head)
{
	t_node	*ptr;
	void	*strip;

	if (!head)
		return ;
	if (!(head -> tail))
		return ;
	strip = malloc(head -> len);
	if (!strip)
		return (NULL),
	ptr = head -> tail;
	while ((head -> tail) && (i < (head -> len)))
	{
		ptr = head -> tail -> next;
		strip[i] = (head -> tail -> content);
		free(head -> tail);
		head -> tail = ptr;
		i++;
	}
	head -> tip = NULL;
	head - > len = 0;
	return (strip);
}
