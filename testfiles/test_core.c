// --- icludes ---

#include "../core/list_core.h"
#include <stdio.h>

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

char	*lxy_strdup(const char *s);

// --- run ---

int	main(int argc, char **argv)
{
	t_node	*node0;
	t_node	*node1;
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
	node0 = init_new_node(inp0);
	node1 = init_empty_node();
	if ((!node0) || (!node1))
	{
		if (node0)
			free(node0);
		if (node1)
			free(node1);
		return (1);
	}
	node0 -> next = init_node(node1, inp1, (node0 -> idx + 1));
	printf("testone: node 0:\n idx: %d\tcontent: %s\n",
		node0 -> idx, (char*)(node0 -> content));
	printf("testone: node 1:\n idx: %d\tcontent: %s\n",
		node0 -> next -> idx, (char*)(node0 -> next -> content));
	printf("delete testnode 1\n");
	del_node(node1, &free);
	printf("deleted node 1:\n idx: %d\tcontent: %s\n",
		node0 -> next -> idx, (char*)(node0 -> next -> content));
	free(node0 -> next);
	printf("delete testnode 1\n");
	rm_node(node0, &free);
	node0 = NULL;
	printf("deleted node 0: %p\n", node0);
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
