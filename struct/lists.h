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
	s_node			*tip;
}					t_head;

// basic func

typedef struct s_basic_func
{
	int		*(*append)(s_head*, void*);
	void	*(*get)(s_head*, int);
	int		(*insert)(t_head*, void*, int);
	void	*(pop_idx)(s_head*, int);
	void	*(*pop)(s_head*);
}			t_basicfunc;

typedef struct s_del_func
{
	void	*(del_info)(void*);
	void	*(del_content)(void*);
}			t_delfunc;

// --- end ---

#endif
