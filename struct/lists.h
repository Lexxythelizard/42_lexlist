/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:52:46 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 14:21:59 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

// --- DOC ---

/*
	...you comment here...
*/

// --- Prototypes ---

struct	s_node;
struct	s_head;

// --- struct ---

// list nodes

typedef struct s_node
{
	int		idx;
	void	*content;
	t_node	*next;
}			t_node;

// head

typedef struct s_head
{
	int		len;
	void	*info;
	void	*del_content;
	void	*del_info;
	void	*specifunc;
	s_node	*tail;
	s_node	*tip;
}			t_head;

// --- end ---

#endif
