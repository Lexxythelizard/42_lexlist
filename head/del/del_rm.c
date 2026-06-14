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

#include "../../struct/lists.h"
#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
*/

// --- define ---

/*	...comment...*/

int	lexlist__rm(
		t_head **self,
		void (*rm_info)(void*),
		void (*rm_content)(void*))
{
	int	len;

	if ((!self) || (!(*self)))
		return (-1);
	len = lexlist__del(*self, rm_info, rm_content);
	*self = NULL;
	return (len);
}
