// --- icludes ---

#include "../core/list_core.h"
#include <stdio.h>

// --- DOC ---

/*
	    TODO:
			- test      init_empty_head()   :   WORKS       VALGRIND PROOF
			- test      init_head()         :   WORKS       VALGRIND PROOF
			- test      init_new_head()     :   WORKS       VALGRIND PROOF
			- test      del_head()          :   WORKS       VALGRIND PROOF
			- test      rm_head()           :   WORKS       VALGRIND PROOF

*/

// --- prototype ---

char	*lxy_strdup(const char *s);

// --- run ---

int	main(int argc, char **argv)
{
	t_head	*head0;
	t_head	*head1;
	char	*inp0;
	char	*inp1;

	if (argc < 3)
		return (0);
	inp0 = lxy_strdup(argv[1]);
	inp1 = lxy_strdup(argv[2]);
	if ((!inp0) || (!inp1))
	{
		if (inp0)
			free(inp0);
		if (inp1)
			free(inp1);
		return (1);
	} 
	head0 = init_new_head(inp0);
	head1 = init_empty_head();
	if ((!head0) || (!head1))
	{
		if (head0)
			free(head0);
		if (head1)
			free(head1);
		return (1);
	}
	printf("test one: head 0:\n len: %d\tinfo: %s\n",
		head0 -> len, (char*)(head0 -> info));
	printf("tail: %s\ttip: %s\n",
		(char*)(head0 -> tail), (char*)(head0 -> tip));
	printf("test one: head 1:\n len: %d\tinfo: %s\n",
		head1 -> len, (char*)(head1 -> info));
	printf("tail: %s\ttip: %s\n",
		(char*)(head1 -> tail), (char*)(head1 -> tip));
	printf("init testhead 1 with inp1\n");
	init_head(head1, inp1);
	printf("test two: head 1:\n len: %d\tinfo: %s\n",
		head1 -> len, (char*)(head1 -> info));
	printf("tail: %s\ttip: %s\n",
		(char*)(head1 -> tail), (char*)(head1 -> tip));
	printf("delete testhead 1\n");
	del_head(head1, &free);
	printf("test three: head 1:\n len: %d\tinfo: %s\n",
		head1 -> len, (char*)(head1 -> info));
	printf("tail: %s\ttip: %s\n",
		(char*)(head1 -> tail), (char*)(head1 -> tip));
	printf("free testhead 1\n");
	free(head1);
	printf("remove testhead 0\n");
	rm_head(head0, &free);
	printf("set bot to NULL\n");
	head0 = NULL;
	head1 = NULL;
	printf("both heads are now\ntesthead 0: %p\ntesthead 1: %p\n;",
		head0, head1);
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
