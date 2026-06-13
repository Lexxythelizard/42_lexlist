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
	TODO:
		- implement another util tail strip
		- implement lexlist__del
		- implement lexlist__remove
		- implement lexlist__strip
		- implement lexlist__del_simple		\___ just parse free as function
		- implement lexlist__remove_simple  /
*/

// --- prototype ---

void		*list_strip(t_head *head);
int			list_rm(t_head *head);
static void	del_tail(t_head *head);

// --- define ---

void	*list_strip(t_head *head)
{
	void	*strip;
	t_node	*ptr;
	int		i;

	if ((!head) || (!(*head)))
		return (NULL);
	i = 0;
	del_info(*head);
	strip = calloc((((*head)->len) + 1) * 8);
	while ((i < ((*head)->len)) && ((*head)->tail))
	{
		ptr = (*head)->tail -> next;
		strip[i] = (*head)->tail -> content;
		free((*head)->tail);
		(*head)->tail = ptr;
		i++;
	}
	del_func(*head);
	free(*head);
	*head = NULL;
	return (strip);
}

int	list_rm(t_head **self, void (*rm_info)(void*), void (*rm_content)(void*))
{
	int	len;

	if ((!self) || (!(*self)))
		return (-1);
	del_tail(*self, rm_content);
	len = rm_head(*self, rm_info)
	*self = NULL
	return (len);
}

/*	...comment...*/

void	del_tail(t_head *head, void (*rm_content)(void*))
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
	head - > len = 0;
}

/* strip tail  */
