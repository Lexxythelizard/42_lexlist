/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:41:30 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/10 17:10:47 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "lists.h"
#include "lexlist.h"
#include "list_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

void	*list_pop(t_head *head);

// --- define ---

void	*list_pop(t_head *head)
{
	void	*content;
	t_node	*ptr;

	if (!head)
		return (NULL);
	if ((!(head -> tail)) || (!(head -> tip)))
		return (NULL);
	ptr = head -> tail;
	content = head -> tip -> content;
	head -> len--;
	if (head -> tail == head -> tip)
	{
		free (head -> tail);
		head -> tail = NULL;
		head -> tip = NULL;
		return (content);
	}
	while (ptr -> next != head -> tail)
		ptr = ptr -> next;
	ptr -> next = NULL;
	free (head -> tip);
	head -> tip = ptr;
	return (content);
}
