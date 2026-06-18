/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:03:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/15 17:12:31 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "../../core/list_core.h"
#include "../../lexlist.h"

// --- DOC ---

/*
lexlist__init() takes a void pointer to info, allocates and 
inits a new head {len: 0, info: <info> tail: NULL, tip: NULL}
returns pointer to new head
*/

// --- define ---

t_head	*lexlist__init(void *info)
{
	return (init_new_head(info));
}
