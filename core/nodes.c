/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 20:26:46 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/05 21:14:19 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "element_lists.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

t_node	*init_empty(void);
t_node	*init_node(t_node *node, void *content, int idx);
t_node	*init_new_list(void *content);
t_node	*del_node(t_node *node, void (*rm_content)(void*));
int		rm_node(t_node *node, void (*rm_content)(void*));

// --- func ---

/*
init_empty() inits an empty node 
	{idx: -1, conten: NULL, next: NULL}
and returns a pointer to the empty node
*/

t_node	*init_empty(void)
{
	t_node	*new;

	new = malloc(24);
	if (!new)
		return (NULL);
	new -> idx = -1;
	new -> content = NULL;
	new -> next = NULL;
}

/*
init_node() takes an empty node and initializes,
needs pointer to content and indx
returns a pointer to the initalized node
*/

t_node	*init_node(t_node *node, void *content, int idx)
{
	if ((!(node)) || (!(content)))
		return (NULL);
	if ((node -> content) || (node -> idx))
		return (NULL);
	node -> idx = idx;
	node -> content = content;
	return (node);
}

/*
init_new_list() inits a new list 
by calling init_empty() and init_node()
takes pointer to content and set node -> idx = 0
returns a pointer to the node of new list
*/

t_node	*init_new_list(void *content)
{
	t_node	*new;

	if (!(content))
		return (NULL);
	new = init_empty();
	return (init_node(new, content, 0));
}

/*
del_node() resets a node to empty node
by removing its content
NOTE:
	make sure to parse a customize funktion to delete 
	and - if mandatory free - the content
RETURN:
	pointer to node
*/

t_node	del_node(t_node *node, void (*rm_content)(void*))
{
	if ((!(node)) || (!(rm_content)))
		return (-1);
	if (!((node) -> content))
		return (-1);
	rm_content(node -> content);
	node -> content = NULL;
	node -> idx = (-1);
}

/*
rm_node() removes and frees the node 
calls del node and frees the node
NOTE:
	make sure to parse a customize funktion to delete 
	and - if mandatory free - the content
	Handle with care could interupt list
RETURN:
	int: idx if succes -1 if error
*/

int	rm_node(t_node *node, void (*rm_content)(void*))
{
	int	idx;

	if ((!(node)) || (!(rm_content)))
		return (-1);
	if (!((node) -> content))
		return (-1);
	idx = node -> idx;
	del_node(node, rm_content);
	free(node);
	return (idx);
}
