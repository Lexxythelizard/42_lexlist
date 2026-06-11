/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:27:59 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 16:29:57 by lenivorb         ###   ########.fr       */
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

t_head	*init_lexlist(void);

// --- define ---

t_head	*init_lexlist(void)
{
	t_head	*new;

	new = init_new_head(info, list_assign_basicfunc());
	if (!new)
		return (NULL);
	return (new);
}
