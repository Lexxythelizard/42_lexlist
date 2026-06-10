/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:52:46 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/08 15:55:37 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

// --- DOC ---

/*
	...you comment here...
*/

// --- Prototypes ---

struct	s_node;
struct	s_head;
struct	s_basic_func;

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
	int				len;
	void			*info;
	s_basic_func	*basicfunc;
	s_del_func		*del;
	void			*specifunc;
	s_node			*tail;
}					t_head;

// basic func

typedef struct s_basic_func
{
	void	*(*append)(s_node**, void*);
	void	*(*by_index)(s_node*, int);
	void	*(*last)(s_node*);
	void	*(*pop)(s_node**);
}			t_basicfunc;

typedef struct s_del_func
{
	void	*(del_info)(void*),
	void	*(del_content)(void*),
}			t_delfunf

// --- end ---

#endif
