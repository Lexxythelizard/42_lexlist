/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_strip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 16:48:47 by lenivorb         ###   ########.fr       */
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

void	*del_strip(t_head *head);

// --- define ---

void	*del_strip(t_head *head)
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
