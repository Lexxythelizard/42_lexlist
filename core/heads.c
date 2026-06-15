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

#include "list_core.h"

// --- DOC ---

/*
	This files contains the 'hidden' functions 
	to interact with the struct t_head
	includes 
	- "../core/list_core.h"
		- "../struct/lists.h"
	following functions are used in library functions, but will not be
	directly available in "lexlist" library
*/

// --- prototype ---

t_head	*init_empty_head(void);
t_head	*init_head(t_head *new, void *info);
t_head	*init_new_head(void *info);
t_head	*del_head(t_head *head, void (*del_info)(void*));
int		rm_head(t_head *head, void (*del_info)(void*));

// --- define ---

/*
init_empty_head() inits an empty head 
    {len: -1, info: NULL, tail: NULL, tip: NULL}
and returns a pointer to the empty head
*/

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

/*
init_head() takes an empty head and initialiyes its len and info
takes pointer to info and set len to 0;
returns a pointer to the initialized head
*/

t_head	*init_head(t_head *new, void *info)
{
	if ((!(new)) || (!(info)))
		return (NULL);
	new -> info = info;
	new -> len = 0;
	return (new);
}

/*
init_new_head() inits a new head meant to be 
an empty list
by calling init_empty_head() and init_head()
takes pointer to info and set head -> len = 0
returns a pointer to the new list
*/

t_head	*init_new_head(void *info)
{
	t_head	*new;

	if (!(info))
		return (NULL);
	new = init_empty_head();
	return (init_head(new, info));
}

/*
del_head() resets a head to empty head
by removing its info and setting len to -1
NOTE:
    - make sure to parse a customize funktion to delete 
      and - if mandatory free - the head
	- Neither frees tail and tip nor set it to NULL
RETURN:
    pointer to node
*/

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

/*
rm_head() removes and frees the head 
calls del_head and frees the head
NOTE:
    - make sure to parse a customize funktion to delete 
      and - if mandatory free - the info
    - Handle with care not frees the tail
	  list elements could get lost
RETURN:
    int: len if succes -1 if error
*/

int	rm_head(t_head *head, void (*del_info)(void*))
{
	int	len;

	if (!head)
		return (-1);
	len = head -> len;
	del_head(head, del_info);
	head -> tail = NULL;
	head -> tip = NULL;
	free(head);
	return (len);
}
