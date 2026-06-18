/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/18 17:18:24 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
lexlist__del() takes a pointer to head and two function pointers:
- rm_info is mean to delete (frees the head -> info)
- rm_content is mean to delete (frees the content of each element)
rm_content gets parsed to del_tail which removes 
every element of head -> tail iteratively

use lexlist__del_simple() for easy freable content and info variables
*/

// --- prototype ---

static void	del_tail(t_head *head, void (*rm_content)(void*));

// --- define ---

int	lexlist__del(
		t_head *self,
		void (*rm_info)(void*),
		void (*rm_content)(void*))
{
	int	len;

	if (!self)
		return (-1);
	del_tail(self, rm_content);
	len = rm_head(self, rm_info);
	return (len);
}

/*	...comment...*/

static void	del_tail(t_head *head, void (*rm_content)(void*))
{
	t_node	*ptr;

	if (!head)
		return ;
	if (!(head -> tail))
		return ;
	ptr = head -> tail;
	while (head -> tail)
	{
		ptr = head -> tail -> next;
		rm_node(head -> tail, rm_content);
		head -> tail = ptr;
	}
	head -> tip = NULL;
	head -> len = 0;
}
