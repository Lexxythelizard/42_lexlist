/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_tail.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 16:40:04 by lenivorb         ###   ########.fr       */
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

int	del_tail(t_head *head);

// --- define ---

int	del_tail(t_head *head)
{
	t_node	*ptr;
	int		len;

	if (!head)
		return (-1);
	if (!(head -> tail))
		return (-1);
	ptr = head -> tail;
	while (head -> tail)
	{
		ptr = head -> tail -> next;
		head -> del -> del_content(head -> tail -> content);
		head -> tail = ptr;
	}
	head -> tip = NULL;
	len = head -> len;
	head - > len = 0;
	return (len);
}
