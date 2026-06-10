// --- icludes ---

#include "lists.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

t_head	*init_head(t_head *new, void *info, void *basicfunc);
t_head	*init_head(t_head *new, void *info, void *basicfunc);
t_head	*init_new_head(void *info, void *basicfunc);
t_head	*del_head(t_head *head, void (*del_info)(void*));
int		rm_head(t_head *head, void (*del_info)(void*));

// --- define ---

/*	...you comment... */

t_head	*init_empty_head(void)
{
	t_head	new;

	new = malloc(40);
	if (!(new))
		return (NULL);
	new -> len = (-1);
	new -> info = NULL;
	new -> basicfunc = NULL;
	new -> specifunc = NULL;
	new -> tail = NULL;
	return (new);
}

/*	...you comment... */

t_head	*init_head(t_head *new, void *info, void *basicfunc)
{
	if ((!(new)) || (!(info)) || (!(basicfunc)))
		return (NULL);
	new -> info = info;
	new -> basicfunc = func;
	new -> len = 0;
	return (new);
}

/*	...you comment... */

t_head	*init_new_head(void *info, void *basicfunc)
{
	t_head	new;

	if ((!(info)) || (!(basic_func)))
		return (NULL);
	new = init_empty_head();
	return (init_head(new, info, basicfunc));
}

/*	...you comment... */

t_head	*del_head(t_head *head, void (*del_info)(void*))
{
	if ((!head) || (!del_info))
		return (NULL);
	if (head -> info)
		del_info(head -> info);
	head -> info = NULL;
	head -> basicfunc = NULL;
	head -> specifunc = NULL;
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
