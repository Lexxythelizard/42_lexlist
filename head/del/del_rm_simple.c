/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_rm_simple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/18 17:40:43 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
lexlist__del_simple() takes a pointer to pointer to head and 
basically calls lexlist__rm and parses it 
self and two time a function pointer to free()
use it for easi freable content and info variables
*/

// --- define ---

int	lexlist__rm_simple(t_head **self)
{
	return (lexlist__rm(self, &free, &free));
}
