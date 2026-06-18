/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_strip_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/18 17:42:08 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
lexlist__strip_simple() takes a pointer to pointer to head and
basically calls lexlist__strip and parses it 
self and a function pointer to free()
use it for easi freable info variables
*/

// --- define ---

void	**lexlist__strip_simple(t_head **self)
{
	return (lexlist__strip(self, &free));
}
