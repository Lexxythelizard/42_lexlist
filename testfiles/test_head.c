// --- icludes ---

#include "../lexlist.h"
#include <stdio.h>
#include <stdlib.h>

// --- DOC ---

/*
	    TODO:
			- test		lexlist__append()			:	WORKS	VALGRIND PROOF
			- test		lexlist__get()				:	WORKS	VALGRIND PROOF
			- test		lexlist__init()				:	WORKS	VALGRIND PROOF
			- test		lexlist__insert()			:	WORKS	VALGRIND PROOF
			- test		lexlist__pop_idx()			:	
			- test		lexlist__pop_()				:	
			- test		lexlist__del()				:	
			- test		lexlist__rm()				:	
			- test		lexlist__strip()			:	
			- test		lexlist__del_simple()		:	
			- test		lexlist__rm_simple()		:	
			- test		lexlist__strop_simple()		:	

*/

// --- prototype ---

char	*lxy_strdup(const char *s);
void	lxy_print_head(t_head *head);
void	lxy_print_tip(t_head *head);
void	lxy_print_tail(t_head *head);
void	lxy_print_node(t_node *node);

// --- run ---

int	main(int argc, char **argv)
{
	t_head	*head0;
	//t_head	*head1;
	void	*temp0;
	char	*inp0;
	char	*inp1;
	char	*inp2;
	char	*inp3;

	if (argc < 5)
		return (0);
	inp0 = lxy_strdup(argv[1]);
	inp1 = lxy_strdup(argv[2]);
	inp2 = lxy_strdup(argv[3]);
	inp3 = lxy_strdup(argv[4]);
	if ((!inp0) || (!inp1) || (!inp2) || (!inp3))
	{
		if (inp0)
			free(inp0);
		if (inp1)
			free(inp1);
		if (inp2)
			free(inp2);
		if (inp3)
			free(inp3);
		return (1);
	}
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	printf("test 0: lexlist__init():\n\n");
	head0 = lexlist__init(inp0);
	lxy_print_head(head0);

	printf("------------------------------------------------------\n");
	printf("test 1: lexlist__append():\n");
	printf("idx added: %d\n\n", lexlist__append(head0, inp1));
	lxy_print_head(head0);
	lxy_print_node(head0 -> tail);
	printf("idx added: %d\n\n", lexlist__append(head0, inp2));
	lxy_print_head(head0);
	lxy_print_tail(head0);

	printf("------------------------------------------------------\n");
	printf("test 2: lexlist__get():\n");
	temp0 = lexlist__get(head0, 1);
	printf("lexlist__get(head0, 1); --> %s\n", (char*)(temp0));
	temp0 = lexlist__get(head0, 0);
	printf("lexlist__get(head0, 0); --> %s\n", (char*)(temp0));
	temp0 = lexlist__get(head0, 1);
	printf("lexlist__get(head0, 1); --> %s\n", (char*)(temp0));
	temp0 = lexlist__get(head0, 4);
	printf("lexlist__get(head0, 4); --> %s\n", (char*)(temp0));
	printf("\ntest 2: list remains unchanged:\n");
	lxy_print_head(head0);
	lxy_print_tail(head0);

	printf("------------------------------------------------------\n");
	printf("test 3: lexlist__insert():\n");
	lexlist__insert(head0, inp3, 1);
	printf("lexlist__insert(head, \"%s\", 1):\n", (char*)(inp3));
	lxy_print_head(head0);
	lxy_print_tail(head0);

	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	free(inp0);
	free(inp1);
	free(inp2);
	free(inp3);
	free(head0 -> tail -> next -> next);
	free(head0 -> tail -> next);
	free(head0 -> tail);
	free(head0);
	return (0);
}

// --- define ---

char	*lxy_strdup(const char *s)
{
	char	*dup;
	int		len;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	len = 0;
	while (s[len++])
		dup[(len - 1)] = s[(len - 1)];
	dup[(len - 1)] = 0;
	return (dup);
}

void	lxy_print_head(t_head *head)
{
	if (!head)
	{
		printf("head: %p\n\n", head);
		return ;
	}
	printf("head:\n");
	printf("info: %s\nlen: %d\ntail: %p\ntip: %p\n",
	(char*)(head -> info),
		head -> len,
		head -> tail,
		head -> tip);
	printf("tail == tip:\t");
	if (head -> tail == head -> tip)
		printf("TRUE\n\n");
	else
		printf("FALSE\n\n");
}

void	lxy_print_tip(t_head *head)
{
	if (!head)
	{
		printf("head: %p\n\n", head);
		return ;
	}
	if (!(head -> tip))
	{
		printf("tip: %p\n\n", head -> tip);
		return ;
	}
	lxy_print_node(head -> tip);
}

void	lxy_print_tail(t_head *head)
{
	t_node	*ptr;

	if (!head)
	{
		printf("head: %p\n\n", head);
		return ;
	}
	ptr = head -> tail;
	while (ptr)
	{
		lxy_print_node(ptr);
		ptr = ptr -> next;
	}
	printf("node: %p\n\n", ptr);
}

void	lxy_print_node(t_node *node)
{
	if (!node)
	{
		printf("node: %p\n\n", node);
		return ;
	}
	printf("node:\n");
	printf("idx: %d\ncontent: %s\nnext:%p\n\n",
		node -> idx,
		(char*)(node -> content),
		node -> next);
}
