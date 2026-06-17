/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_headless.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:15:32 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/16 18:23:06 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include <stdio.h>
#include <stdlib.h>
#include "../lexlist.h"

// --- DOC ---

/*
	TODO:
		- test	headless_init_new_list		:	WORKS	VALGRIND PROOF
		- test	headless_add_back			:	WORKS   VALGRIND PROOF
		- test	headless_add_front			:	WORKS   VALGRIND PROOF
		- test	headless_last				:	WORKS   VALGRIND PROOF
		- test	headless_by_idx				:	WORKS   VALGRIND PROOF
		- test	headless_pop_by_index		:	WORKS   VALGRIND PROOF
		- test	headless_pop				:	WORKS   VALGRIND PROOF
		- test	headless_clear_node/simple	:	WORKS   VALGRIND PROOF
		- test	headless_clear_list/simple	:	WORKS   VALGRIND PROOF
		- test	headless_cut				:	WORKS   VALGRIND PROOF
		- test	headless_reindex			:	WORKS   VALGRIND PROOF
		- test	headless_count				:	WORKS   VALGRIND PROOF
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
	t_node	*temp0;

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

	printf("------------------------------------------------\n");
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

	printf("------------------------------------------------\n");
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

	printf("------------------------------------------------\n");
	printf("test 3: test node 3:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test3 -> idx, (char*)(test3 -> content),
		test3 -> next);

	printf("------------------------------------------------\n");
	printf("test 4: now test headless_count:\n");
	printf("len from test node 0: %d\n", headless_count(test0));
	printf("len from test node 3: %d\n\n", headless_count(test3));
	
	printf("------------------------------------------------\n");
	printf("test 5: now test headless_reindex(test0):\n");
	printf("output of func: %d\n\n", headless_reindex(test0));
	
	printf("------------------------------------------------\n");
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

	printf("------------------------------------------------\n");
	printf("test 7: test headless_last and headless_get_by_index():\n");
	temp0 = headless_last(test0);
	printf("test 7: test headless_last(test0):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		temp0 -> idx, (char*)(temp0 -> content),
		temp0 -> next);
	temp0 = headless_by_idx(test0, 1);
	printf("test 7: test headless_by_idx(test0, 1):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		temp0 -> idx, (char*)(temp0 -> content),
		temp0 -> next);
	temp0 = headless_by_idx(test3, 8);
	printf("test 7: test headless_by_idx(test3, 8):\n");
	printf("ptr: %p\n\n", temp0);

	printf("------------------------------------------------\n");
	printf("test 8: test headless cut:\n");
	temp0 = headless_cut(&test0, 1);
	printf("test 8: temp0 = headless_cut(&test0, 1)):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		temp0 -> idx, (char*)(temp0 -> content),
		temp0 -> next);
	printf("append temp to test3 by using headless_add_back() and reindex\n");
	headless_add_back(&test3, temp0);
	headless_reindex(test3);
	printf("test 8: test node 3:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test3 -> idx, (char*)(test3 -> content),
		test3 -> next);
	printf("test 8: test node 2 (test3 -> next):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test3 -> next -> idx, (char*)(test3 -> next -> content),
		test3 -> next -> next);
	printf("test 8: test node 1 (test2 -> next):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test3 -> next -> next -> idx,
		(char*)(test3 -> next -> next -> content),
		test3 -> next -> next);
	printf("and now test0 should be one node");
	printf("test 8: test node 0:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> idx, (char*)(test0 -> content),
		test0 -> next);

	printf("------------------------------------------------\n");
	printf("test 9: test headless_clear_node_simple(test0):\n");
	headless_clear_node_simple(&test0);
	printf("test 9: test node 0:\n");
	printf("pointer: %p\n\n", test0);

	printf("------------------------------------------------\n");
	printf("test 10: headless_pop and headless_pop_by idx:\n");
	temp0 = headless_pop_by_index(&test3, 1);
	headless_add_back(&test0, temp0);

	printf("test 10_a: node: temp0:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		temp0 -> idx, (char*)(temp0 -> content),
		temp0 -> next);

	printf("popped sec element of sec list:\n");
	printf("temp0 = headless_pop_by_idx(&test3, 1)\n");
	printf("and added it to the back of first list\n");
	printf("headless_add_back(&test0)\n\n");
	temp0 = headless_pop(&test3);
	headless_add_back(&test0, temp0);

	printf("test 10_b: node: temp0:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		temp0 -> idx, (char*)(temp0 -> content),
		temp0 -> next);

	printf("popped last element of sec list:\n");
	printf("temp0 = headless_pop(&test3)\n");
	printf("and added it to the back of first list\n");
	printf("headless_add_back(&test0, temp0)\n\n");
	printf("now lets check the lists\n");
	printf("test 10: node: test3:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test3 -> idx, (char*)(test3 -> content),
		test3 -> next);
	printf("test 10: node 0:\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> idx, (char*)(test0 -> content),
		test0 -> next);
	printf("test 10: test node 1 (test0 -> next):\n");
	printf("idx: %d\ninfo: %s\nnext: %p\n\n",
		test0 -> next -> idx, (char*)(test0 -> next -> content),
		test0 -> next -> next);

	printf("------------------------------------------------\n");
	printf("test 11: finally test headless_clear_list_simple():\n");
	headless_clear_list_simple(&test0);
	printf("called headless_clear_list(&test0):\n");
	headless_clear_node_simple(&test3);
	printf("test 11: test node 1 (test0):\n");
	printf("ptr: %p\n\n", test0);

	printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	//lxy_free_four(inp0, inp1, NULL, inp3);
	//lxy_free_four_el(test0 -> next -> next, test0 -> next, test0, test3);
	//lxy_free_four_el(test3 -> next -> next, test3 -> next, test3, test0);
	//lxy_free_four_el(test0 -> next, test0, test3, NULL);
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
