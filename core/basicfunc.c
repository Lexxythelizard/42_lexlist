/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:00:06 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/08 11:00:11 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "list.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

t_basicfunc	*init_empty_basicfunc(void);
t_basicfunc	*init_basicfunc(t_basicfunc *new,
				void *(*append)(t_node**, void*),
				void *(*by_index)(s_node*, int),
				void *(*last)(s_node*),
				void *(*pop)(s_basic_func**));
t_basicfunc	*init_new_basicfunc(
				void *(*append)(t_node**, void*),
				void *(*by_index)(s_node*, int),
				void *(*last)(s_node*),
				void *(*pop)(s_basic_func**));
t_basicfumc	*del_basicfunc(t_basicfunc *basicfunc);
int			rm_basicfunc(t_basicfunc **basicfunc);

// --- define ---

t_basicfunc	*init_empty_basicfunc(void)
{
	t_basicfunc	new;

	new = malloc(32);
	return (del_basicfunc(new));
}

/*	...you comment... */

t_basicfunc	*init_basicfunc(t_basicfunc *new,
	void *(*append)(t_node**, void*),
	void *(*by_index)(s_node*, int),
	void *(*last)(s_node*),
	void *(*pop)(s_basic_func**))
{
	if (!(new))
		return (NULL);
	if ((!append) && (!by_index) && (!last) && (!pop))
		return (NULL);
	new -> append = append;
	new -> by_index = by_index;
	new -> last = last;
	new -> pop = pop;
	return (new);
}

/*	...you comment... */

t_basicfunc	*init_new_basicfunc(
	void *(*append)(t_node**, void*),
	void *(*by_index)(s_node*, int),
	void *(*last)(s_node*),
	void *(*pop)(s_basic_func**))
{
	t_basicfunc	new;

	new = init_empty_basicfunc();
	return (init_basicfunc(new, append, by_index, last, pop));
}

/*	...you comment... */

t_basicfumc	*del_basicfunc(t_basicfunc *basicfunc)
{
	if (!(basicfunc))
		return (NULL);
	new -> append = NULL;
	new -> by_index = NULL;
	new -> last = NULL;
	new -> pop = NULL;
	return (basicfunc);
}

/*	...you comment... */

int	rm_basicfunc(t_basicfunc **basicfunc)
{
	if (!basicfunc)
		return (-1);
	if (!(*basicfunc))
		return (1);
	free(*basicfunc);
	*basicfunc = NULL;
	return (0);
}
