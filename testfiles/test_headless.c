/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_headless.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:15:32 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/15 18:50:30 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include <stdio.h>
#include <stdlib.h>
#include "../lexlist.h"

// --- DOC ---

/*
	TODO:
		- test	headless_init_new_list		:	WORKS
		- test	headless_add_back			:	WORKS
		- test	headless_add_front			:	WORKS
		- test	headless_last				:	---
		- test	headless_pop_by_index		:	---
		- test	headless_pop				:	---
		- test	headless_clear_node/simple	:	---
		- test	headless_clear_list/simple	:	---
		- test	headless_cut				:	---
		- test	headless_reindex			:	WORKS
		- test	headless_count				:	WORKS
*/

// --- prototype ---

char	*lxy_strdup(const char *s);
int		lxy_free_four(char *s0, char *s1, char *s2, char *s3);
int		lxy_free_four_el(void *s0, void *s1, void *s2, void *s3);

// --- run ---

int	main(int argc, char **argv)
{
	char	*inp0;
	char	*inp1;
	char	*inp2;
	char	*inp3;
	t_node	*test0;
	t_node	*test1;
	t_node	*test2;
	t_node	*test3;

	if (argc < 5)
	{
		printf("need 4 args to test\n");
		return (0);
	}
	inp0 = lxy_strdup(argv[1]);
	inp1 = lxy_strdup(argv[2]);
	inp2 = lxy_strdup(argv[3]);
	inp3 = lxy_strdup(argv[4]);
	test0 = NULL;
	test1 = NULL;
	test2 = NULL;
	test3 = NULL;
	if ((!inp0) || (!inp1) || (!inp2) || (!inp3))
		return (lxy_free_four(inp0, inp1, inp2, inp3));
	test0 = headless_init_new_list(inp0);
	test1 = headless_init_new_list(inp1);
	test2 = headless_init_new_list(inp2);
	if ((!test0) || (!test1) || (!test2))
	{
		lxy_free_four(inp0, inp1, inp2, inp3);
		return (lxy_free_four_el(test0, test1, test2, test3));
	}
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("test 0: test node 0:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> idx, (char*)(test0 -> content),
		test0 -> next);
	printf("add test1 to the back: list_add_back()\n");
	headless_add_back(&test0, test1);
	printf("test 1: test node 0:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> idx, (char*)(test0 -> content),
		test0 -> next);
	printf("test 1: test node 1 (test0 -> next):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> next -> idx, (char*)(test0 -> next -> content),
		test0 -> next -> next);
	printf("add test2 to the front\n");
	headless_add_front(&test0, test2);
	printf("now test2 beomes the new test0, lets test it:\n");
	printf("test 2: test node 0:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> idx, (char*)(test0 -> content),
		test0 -> next);
	printf("test 2: test node 1 (test0 -> next):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> next -> idx, (char*)(test0 -> next -> content),
		test0 -> next -> next);
	printf("test 2: test node 2 (test1 -> next):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> next -> next -> idx,
		(char*)(test0 -> next -> next -> content),
		test0 -> next -> next);
	printf("now call list_add_back on a null pointer list\n");
	headless_add_back(&test3, headless_init_new_list(inp3));
	printf("test 3: test node 3:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test3 -> idx, (char*)(test3 -> content),
		test3 -> next);
	printf("test 4: now test headless_count:\n");
	printf("len from test node 0: %d\n", headless_count(test0));
	printf("len from test node 3: %d\n\n", headless_count(test3));
	
	printf("test 5: now test headless_reindex(test0):\n");
	printf("output of func: %d\n\n", headless_reindex(test0));
	
	printf("test 6: now review the results of the reindexed list:\n");
	printf("test 6: test node 0:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> idx, (char*)(test0 -> content),
		test0 -> next);
	printf("test 6: test node 1 (test0 -> next):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> next -> idx, (char*)(test0 -> next -> content),
		test0 -> next -> next);
	printf("test 6: test node 2 (test1 -> next):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> next -> next -> idx,
		(char*)(test0 -> next -> next -> content),
		test0 -> next -> next);

	printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	lxy_free_four(inp0, inp1, inp2, inp3);
	lxy_free_four_el(test0 -> next -> next, test0 -> next, test0, test3);
	return (0);
}

// --- define ---

char	*lxy_strdup(const char *s)
{
	int		i;
	char	*dup;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i++])
		dup[(i - 1)] = s[(i - 1)];
	dup[(i - 1)] = 0;
	return (dup);
}

int	lxy_free_four(char *s0, char *s1, char *s2, char *s3)
{
	if (s0)
		free(s0);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	return (1);
}

int	lxy_free_four_el(void *s0, void *s1, void *s2, void *s3)
{
	if (s0)
		free(s0);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	return (1);
}
