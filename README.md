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
cc [your flags] [your files] -L [path to library] -l ft -o [your Program name]
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
and points to the first node of a list (member `.tail`)
Also it got pointers to a struct called basicfunctions, which contains the basic functions to call (*under construction*) 
`.specifunc` is meant to contain a pointer to a set of specified functions you want to use in your list

```C
typedef struct s_head
{
	int			len;
	void		*info;
	s_basicfunc	*info;
	s_del_func	*info;
	void		*specifunc;
	t_node		*tail;
}				t_node;

```

**t_basicfunc**

`t_basicfunc` is still under construction

---
---

## Functions - overview

### Part 1: headless functions

- ...
- ... follows ... 
- ...

### Part 2: lexlist functions

- ...
- ... follows ... 
- ...

---

## Funcions in detail

### headless functions:

Use the list without the head and without OoP just very basic :)

##### will be updated soon

**ft_func name**
- Params:	`[type]` `[name]`
- Return:	`[type]` `[name]`
- NOTE:		the original ...
			be carefull; usefull to delete sensitiv data
			(no) NULL guard - ...
			...

**...**

### lexlistfunction:

##### will be updated soon

**ft_func name**
- Params:	`[type]` `[name]`
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

