/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_del_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/18 17:39:43 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
lexlist__del_simple() basically calls lexlist__del and parses it 
self and two time a function pointer to free()
use it for easi freable content and info variables
*/

// --- define ---

int	lexlist__del_simple(t_head *self)
{
	return (lexlist__del(self, &free, &free));
}
