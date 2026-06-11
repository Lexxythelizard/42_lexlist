/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:59:32 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/10 18:34:47 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METHODS_H
# define METHODS_H

// --- include ---

# include "lists.h"

// --- DOC ---

/*
	...you comment here...
*/

// --- prototype ---

/*following six functions need to get implemented (not in headless)*/
int		list_append(t_head *head, void *content);
void	*list_by_idx(t_head *head, int idx);
int		list_insert(t_head *head, void *content, int idx);
void	*list_pop_by_index(t_head *head, int idx);
void	*list_pop(t_head *head);

// --- end ---

#endif
