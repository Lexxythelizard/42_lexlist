/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:44:42 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/10 18:24:26 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "lists.h"
#include "lexlists.h"
#include "core_list.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

int	list_append(t_head *head, void *content);

// --- define ---

int	list_append(t_head *head, void *content)
{
	int		i;
	t_node	*new;

	if ((!head) || (!content))
		return (-1);
	new = init_new_node(content, head -> len);
	if (!new)
		return (-1);
	if (head -> len)
		head -> tip -> next = new;
	else
		head -> tail = new;
	head -> tip = new;
	head -> len++;
	return (head -> len - 1);
}
