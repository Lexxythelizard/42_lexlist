/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_rm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/18 17:23:36 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
lexlist__rm() takes a pointer to pointer to head and two function pointers:
- rm_info is mean to delete (frees the head -> info)
- rm_content is mean to delete (frees the content of each element)
by parsing them with *self to lexlist__del it:
rm_content gets parsed to del_tail which removes 
every element of head -> tail iteratively

use lexlist__rm_simple() for easy freable content and info variables

*/

// --- define ---

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
