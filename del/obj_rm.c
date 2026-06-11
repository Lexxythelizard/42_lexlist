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

int	obj_rm(t_head *head);

// --- define ---

int	obj_rm(t_head **head)
{
	int	len;

	if ((!head) || (!(*head)))
		return (-1);
	len = head -> len;
	// call del info
	// call del tail
	// call del specifunc
	// call del basicfunc
	// call del del
	// rm object
	return (len);
}
