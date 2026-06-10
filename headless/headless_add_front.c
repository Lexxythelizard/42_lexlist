// --- icludes ---

#include "lists.h"
#include "core_list.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

t_node	*headless_add_front(t_node **node, t_node *new);

// --- define ---

t_node	*headless_add_front(t_node **node, t_node *new)
{
	if ((!node) || (!new))
		return (NULL);
	new -> next = *node;
	*node = new;
	return (new);
}

