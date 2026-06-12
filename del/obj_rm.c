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
	... your comment here ...
*/

// --- prototype ---

void		*list_strip(t_head *head);
int			list_rm(t_head *head);
static void	del_info(t_head *head);
static void	del_funct(void);
static void	del_tail(t_head *head);

// --- define ---

void	*list_strip(t_head *head)
{
	void	*strip;
	t_node	*ptr;
	int		i;

	if (!head)
		return (NULL);
	if (!(head -> info))
		return (NULL);
	strip = calloc(((head -> len) + 1) * 8);
	while ((i < head -> len) && (head -> tail))
	{
		ptr = head -> tail -> next;
		strip[i] = head -> tail -> content;
		free(head -> tail);
		head -> tail = ptr;
		i++;
	}
	head -> len = 0;
	head -> tip = NULL;
	return (strip);
}

int	list_rm(t_head **head)
{
	int	len;

	if ((!head) || (!(*head)))
		return (-1);
	len = head -> len;
	del_info(*head);
	del_tail(*head);
	del_func(*head);
	free(*head);
	*head = NULL
	return (len);
}

static void	del_info(t_head *head)
{
	if (!head)
		return ;
	if (!(head -> info))
		return ;
	head -> del -> del_info(head -> info);
	head -> info = NULL;
}

static void	del_tail(t_head *head)
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
		head -> del -> del_content(head -> tail -> content);
		head -> tail = ptr;
	}
	head -> tip = NULL;
	head - > len = 0;
}

static void	del_func(t_head *head)
{
	if (!head)
		return ;
	if (head -> speci)
	{
		head -> del -> speci(head -> specifunc);
		head -> specifunc = NULL;
	}
	if (head -> basicfunc)
	{
		free(head -> basicfunc);
		head -> basicfunc = NULL;
	}
	if (head -> del)
	{
		free(head -> del);
		head -> del = NULL;
	}
}
