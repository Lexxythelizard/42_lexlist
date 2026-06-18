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
			- test		lexlist__pop_idx()			:	WORKS	VALGRIND PROOF
			- test		lexlist__pop_()				:	WORKS	VALGRIND PROOF
			- test		lexlist__del()				:	WORKS	VALGRIND PROOF
			- test		lexlist__rm()				:	WORKS	VALGRIND PROOF
			- test		lexlist__strip()			:	WORKS	VALGRIND PROOF
			- test		lexlist__del_simple()		:	WORKS	VALGRIND PROOF
			- test		lexlist__rm_simple()		:	WORKS	VALGRIND PROOF
			- test		lexlist__strip_simple()		:	WORKS	VALGRIND PROOF

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
	t_head	*head1;
	void	*temp0;
	void	**contents;
	char	*inp0;
	char	*inp1;
	char	*inp2;
	char	*inp3;
	int		i;

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
	printf("check tip: head0 -> tip:\n");
	lxy_print_node(head0 -> tip);

	printf("------------------------------------------------------\n");
	printf("test 4: lexlist__pop_idx():\n");
	printf("lexlist__pop_idx(head0, 1);\n");
	temp0 = lexlist__pop_idx(head0, 1);
	printf("popped content: %s\n\n", (char*)(temp0));
	printf("check tip: head0 and tail:\n");
	lxy_print_head(head0);
	lxy_print_tail(head0);
	printf("check tip: head0 -> tip:\n");
	lxy_print_node(head0 -> tip);
	head1 = lexlist__init(temp0);
	printf("popped content assigned as info of head1");
	lxy_print_head(head1);

	printf("------------------------------------------------------\n");
	printf("test 5: lexlist__pop():\n");
	printf("temp0 = lexlist__pop(head0);\n");
	temp0 = lexlist__pop(head0);
	printf("lexlist__append(head1, \"%s\");\n", (char*)(temp0));
	lexlist__append(head1, temp0);
	printf("temp0 = lexlist__pop(head0);\n");
	temp0 = lexlist__pop(head0);
	printf("lexlist__append(head1, \"%s\");\n", (char*)(temp0));
	lexlist__append(head1, temp0);
	printf("print list head0 and head1 inkl tail\n\n");
	lxy_print_head(head0);
	lxy_print_tail(head0);
	lxy_print_head(head1);
	lxy_print_tail(head1);

	printf("------------------------------------------------------\n");
	printf("test 6: lexlist__del():\n");
	printf("move the elements back and filling head1 with %s\n",
		(char*)(head1 -> info));	
	temp0 = lexlist__pop(head1);
	lexlist__append(head0, temp0);
	temp0 = lexlist__pop(head1);
	lexlist__append(head0, temp0);
	lexlist__append(head1, lxy_strdup((char*)(head1 -> info)));
	lexlist__append(head1, lxy_strdup((char*)(head1 -> info)));
	printf("print list head0 and head1 inkl tail\n\n");
	lxy_print_head(head0);
	lxy_print_tail(head0);
	lxy_print_head(head1);
	lxy_print_tail(head1);
	printf("now calling lexlist__del_simple(head1 -> tail -> next);\n\n");
	lexlist__rm_simple(&head1);
	lxy_print_head(head1);

	printf("------------------------------------------------------\n");
	printf("test 7: lexlist__strip():\n");
	printf("contents = lexlist_strip_simple(head0);\n");
	contents = lexlist__strip_simple(&head0);
	i = 0;
	printf("display contents\n");
	while (contents[i])
	{
		printf("contents %d: %s\n", i, (char*)(contents[i]));
		i++;
	}
	i = 0;
	printf("free contents\n");
	while (contents[i])
	{
		free(contents[i]);
		i++;
	}
	free(contents);

	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
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
