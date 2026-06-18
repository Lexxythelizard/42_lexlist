README.md

*This project has been created as little side project of the 42 curriculum by lenivorb aka Lexxythelizard.*

# Lexlists

## Description

`Lexlists` is a custom C library inspired by the liked list part of the very first project `libft`.

Since I got inspired by Python lists, I wanted to embrace a little OoP and 
create my own library

Lists containing a head, keeping tracks of the lenght, storing the information about the list and pointing to the first element of list (`.tail`)

 --> **...under construction...**


## Instructions

Include this library in your files

```C
#include "[path to dir]/lexlist.h"
```

later you should compile your files with 

```bash
cc [your flags] [your files] -L [path to library] -l lexlist -o [your Program name]
```

But not yet...

	**...under construction...**

## Resources

*The following resources were useful while working on this project:*

### Documentation

**man pages**
- ...
- ...

**makefile**
- GNU make: 

**common webpages**
- Geeks for Geeks : https://www.geeksforgeeks.org/c/c-programming-language/
- stackoverflow : https://stackoverflow.com/questions

### Tools

- cc for compilation
- make for build automation
- ar for creating the static library
- valgrind for memory checking
- custom test files for comparing original and ft_ behavior

### AI usage

AI assistance was used for:
- not yet: but definitly for chasing typos, cause I#m so clumsy ;)


---

## Structs

### overview

- `t_node`
- `t_head`
- `t_basicfunc`

### define

**t_node**

`t_node` is basically a simple linked list node which can point to any content type 
and to the next node, additional it could be indexed

```C
typedef struct s_node
{
	int		idx;
	void	*content;
	t_node	*next;
}			t_node;

```

**t_head**

`t_head` is the head which keeps track of the lenght, stores the info about the list 
and points to the first node of a list (member `.tail` / `head -> tail`)
the member `.tip` / `head -> tip` allways pointing to the last element of tail
--> the tip of tail :)

```C
typedef struct s_head
{
	int			len;
	void		*info;
	t_node		*tail;
	t_node		*tip;
}				t_node;

```


---

## Functions - overview

### Part 1: headless functions

- `headless_init_new_list`
- `headless_add_back`
- `headless_add_front`
- `headless_last`
- `headless_by_idx`
- `headless_pop_by_index`
- `headless_pop` 
- `headless_clear_node`
- `headless_clear_node_simple`
- `headless_clear_list`
- `headless_clear_list_simple`
- `headless_cut`
- `headless_reindex`
- `headless_count`

### Part 2: lexlist functions

- `lexlist__append`
- `lexlist__get`
- `lexlist__init`
- `lexlist__insert`
- `lexlist__pop_idx`
- `lexlist__pop`
- `lexlist__del`
- `lexlist__rm`
- `lexlist__strip`
- `lexlist__del_simple`
- `lexlist__rm_simple`
- `lexlist__strop_simple`


---

## Funcions in detail

### headless functions:

Use the list without the head and without OoP just very basic :)

##### will be updated soon

**headless_init_new_list**
- Param 1:	`void`		`content`
- Return:	`t_node`	`*new_list`
- NOTE:		the only headless function which \
			takes a pointer to content to create (allocate) a new node. \
			use it to create a pointer to a new node

**headless_add_back**
- Param 1:	`t_node` 	`**node`
- Param 2:	`t_node` 	`*new`
- Return:	---
- NOTE:		adds node to the end of the list, \
			makes *node new if *node was NULL (list was empty)

**headless_add_front**
- Param 1:	`t_node` 	`**node`
- Param 2:	`t_node` 	`*new`
- Return:	`t_node` 	`*new_first node`
- NOTE:		makws new the new first node and append the list as new -> next \
			be carefull and make sure to parse the first node of the list

**headless_by_idx**
- Param 1:	`t_node`	`*node`
- Param 2:	`int` 		`idx`
- Return:	`t_node` 	`*searched_node` / `NULL` if not found
- NOTE:		returns a pointer to the node with idx \
			node remains in list

**headless_last**
- Param 1:	`t_node`	`*node`
- Return:	`t_node` 	`*last_node` / `NULL` if list empty
- NOTE:		simple and safe funtion, could be called on any node in the list

**headless_pop_by_index**
- Param 1:	`t_node`	`**node`
- Param 2:	`int` 		`idx`
- Return:	`t_node` 	`*searched_node` / `NULL` if not found
- NOTE:		returns a pointer to the node with idx \
			node pops removed from list, list stays intakt ue to reconnection: \
			popped | prev -> next = popped -> next;

**headless_pop**
- Param 1:	`t_node`	`**node`
- Return:	`t_node` 	`*last_node` / `NULL` if list empty 
- NOTE:		simple and safe funtion, could be called on any node in the list, \ 
			popps the last node of the list and removing it from the list \
			popped | prev -> next = NULL;

**headless_clear_node**
- Param 1:	`t_node`	`**node`
- Param 2:	`void` 		`(*del_content)(void*)`
- Return:	`int` 		`idx of removed node`
- NOTE:		calling `del_content` on `(*node)->content` to free and delete content \
			for easy freeable content, like str just use `headless_clear_node_simple` \
			be carefull: it baicaly deleting one node and its content \
			without reconnecting the list: could brake list

**headless_clear_node_simple**
- Param 1:	`t_node`	`**node`
- Return:	`int` 		`idx of removed node`
- NOTE:		calling `del_content` on `(*node)->content` to free and delete  \
			easy freeable content, like str. \
			be carefull: it baicaly deleting one node and its content \
			without reconnecting the list: could brake list

**headless_clear_list**
- Param 1:	`t_node`	`**node`
- Param 2:	`void` 		`(*del_content)(void*)`
- Return:	`int` 		`idx of removed node`
- NOTE:		calling `clear_node` iterativly on any node until the end \
			parsing `del_content` every time. \
			use `headless_clear_list_simple` for easy freeable content like str.

**headless_clear_list_simple**
- Param 1:	`t_node`	`**node`
- Return:	`int` 		`idx of removed node`
- NOTE:		calling `clear_node` iterativly on any node until the end \
			parsing `del_content` every time. \
			use it only for easy freeable content like str.

**headless_cut**
- Param 1:	`t_node`	`**node`
- Param 2:	`int`		`idx`
- Return:	`t_node`	`cut` first node pf cut of list \
- NOTE:		cuts the list at idx incl and node add idx \
			sets `(headless_get_by_idx(*node, (idx - 1)))-> next = NULL;` \
			`headless_cut([node 0], 3)` | stays {node 0, node 1, node 2} | \
			cut {node 3, node 4, ..., node n}

**headless_reindex**
- Param 1:	`t_node` 	`*first`
- Return:	`int`		`reindexed` number of reindexed elements
- NOTE:		reindexing every node in ascending order, make sure to call it add the head \
			Use it after you popped one element or aafter you called `headles_add_front`

**headless_count**
- Param 1:	`t_node`	`*node`
- Return:	`int`		`count`
- NOTE:		could be used at any node to count the elements until the end \
			make sure to parse the first node if you wanna kn ow the whole lenght


### lexlistfunction:

##### will be updated soon

**lexlist__append**
- Param 1:	`t_head`	`*self`
- Param 2:	`void`		`*content`
- Return:	`int`		`idx` index of appended element
- NOTE:		the original ...
			appends a new element (node) at the end of the list (tail) \
			assigns idx to new element and updates `head -> tip` automaticly \
			`new_element = {idx: old len, content: <content> next: NULL}` \
			allocates memory for `new_element`

**lexlist__get**
- Param 1:	`t_head`	`*self`
- Param 2:	`int`		`idx`
- Return:	`void`		`*content` / `NULL` if element not found
- NOTE:		returns pointer to content of element \
			list remains unchanged

**lexlist__init**
- Param 1:	`void`		`*info`
- Return:	`t_head`	`*new_head` pointer to new head
- NOTE:		inits a new head and assigning info \
			`new_head = {len: 0, info: <info> tail: NULL, tip: NULL}` \
			allocates memory for `new_head`

**lexlist__insert**
- Param 1:	`t_head`	`*self`
- Param 2:	`void`		`*content`
- Param 3:	`int`		`idx`
- Return:	`int`		`self -> len` the new len
- NOTE:		inserts a new element in list at idx if 0 <= idx <= self -> len \
			reindex the `self -> tail` and updates `self -> tip` automaticly \
			allocates memory for `new_element`

**lexlist__**
- Param 1:	`[type]` `[name]`
- Return:	`[type]` `[name]`
- NOTE:		the original ...
			be carefull; usefull to delete sensitiv data
			(no) NULL guard - ...
			...

**lexlist__**
- Param 1:	`[type]` `[name]`
- Return:	`[type]` `[name]`
- NOTE:		the original ...
			be carefull; usefull to delete sensitiv data
			(no) NULL guard - ...
			...

**lexlist__**
- Param 1:	`[type]` `[name]`
- Return:	`[type]` `[name]`
- NOTE:		the original ...
			be carefull; usefull to delete sensitiv data
			(no) NULL guard - ...
			...

**lexlist__**
- Param 1:	`[type]` `[name]`
- Return:	`[type]` `[name]`
- NOTE:		the original ...
			be carefull; usefull to delete sensitiv data
			(no) NULL guard - ...
			...

**...**


---

## Author
Lexxythelizard 
 
42 Berlin login: lenivorb 

private Github:	https://www.github.com/Lexxythelizard

