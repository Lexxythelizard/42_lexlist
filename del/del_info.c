/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:33:34 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 16:38:10 by lenivorb         ###   ########.fr       */
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

void	del_info(t_head *head);

// --- define ---

void	del_info(t_head *head)
{
	if (!head)
		return ;
	if (!(head -> info))
		return ;
	head -> del -> del_info(head -> info);
	head -> info = NULL;
}
