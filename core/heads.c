/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:27:43 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 16:30:27 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../struct/lists.h"
#include "list_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

t_head	*init_empty_head(void);
t_head	*init_head(t_head *new, void *info);
t_head	*init_new_head(void *info);
t_head	*del_head(t_head *head, void (*del_info)(void*));
int		rm_head(t_head *head, void (*del_info)(void*));

// --- define ---

/*	...you comment... */

t_head	*init_empty_head(void)
{
	t_head	*new;

	new = malloc(32);
	if (!(new))
		return (NULL);
	new -> len = (-1);
	new -> info = NULL;
	new -> tail = NULL;
	new -> tip = NULL;
	return (new);
}

/*	...you comment... */

t_head	*init_head(t_head *new, void *info)
{
	if ((!(new)) || (!(info)))
		return (NULL);
	new -> info = info;
	new -> len = 0;
	return (new);
}

/*	...you comment... */

t_head	*init_new_head(void *info)
{
	t_head	*new;

	if (!(info))
		return (NULL);
	new = init_empty_head();
	return (init_head(new, info));
}

/*	...you comment... */

t_head	*del_head(t_head *head, void (*del_info)(void*))
{
	if ((!head) || (!del_info))
		return (NULL);
	if (head -> info)
		del_info(head -> info);
	head -> info = NULL;
	head -> len = (-1);
	return (head);
}

/*	...you comment... */

int	rm_head(t_head *head, void (*del_info)(void*))
{
	int	len;

	if (!head)
		return (-1);
	len = head -> len;
	del_head(head, del_info);
	head -> tail = NULL;
	return (len);
}
