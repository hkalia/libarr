# libarr
A Dynamic Array Library in C

This library follow the 42 norminette standard and uses only the libc functions `malloc` and `free` from the `stdlib.h` header

**Disclaimer:** This library has only been tested on 42 computers

#### Contents:
* [What is a Dynamic Array?](#what-is-a-dynamic-array)
* [Why use a Dynamic Array?](#why-use-a-dynamic-array)
* [How to use this Dynamic Array Library](#how-to-use-this-dynamic-array-library)

### What is a Dynamic Array?
An array is a collection of elements.  
If you do not understand how arrays work in C, go learn that first.  
In C, you can get an array through two basic methods. The first method is declaring it on the stack like so:
``` C
int   array[50];
```
The second method is declaring a pointer then calling `malloc`:
``` C
int   *array;

array = malloc(sizeof(int) * 50);
```
Both of these methods have one issue. Once you have created an array using either of the two above shown methods, the array will be of size 50. What if you need to insert more than 50 elements into the array? What if you don't know how much space you need? This is where a dynamic array comes in handy. A dynamic array is an array that allows you to add a variable amount of elements increasing the size automatically when required. (this is my definition, you can read more about the idea [here](https://en.wikipedia.org/wiki/Dynamic_array).)

### Why use a Dynamic Array?
This can be best illustrated via example. Take the following piece of code that reads a line from the standard input:  
(_At 42, we are not allowed to use the `realloc` function_)
```C
```

### How to use this Dynamic Array Library

```c
typedef struct	s_elm
{
	size_t	sze;
	int8_t	(*zero)(void *elm);
	int8_t	(*dup)(void *dst, const void *src);
	void	(*dtr)(void *elm);
}				t_arr_elm;

typedef struct	s_arr
{
	uint8_t		*ptr;
	t_arr_elm	elm;
	size_t		len;
	size_t		cap;
}				t_arr;

int8_t			arr_init(t_arr *src, size_t cap, t_arr_elm elm);
int8_t			arr_reserve(t_arr *src, size_t sze);
int8_t			arr_resize(t_arr *src, size_t sze);
void			arr_dtr(t_arr *src);
int8_t			arr_insert(t_arr *dst, size_t idx, const void *src);
int8_t			arr_insertm(t_arr *dst, size_t idx, const void *src
							, size_t src_len);
int8_t			arr_insertarr(t_arr *dst, size_t idx, t_arr *src);
int8_t			arr_append(t_arr *dst, const void *src);
int8_t			arr_appendm(t_arr *dst, const void *src, size_t src_len);
int8_t			arr_appendarr(t_arr *dst, t_arr *src);
void			arr_swap(t_arr *src, size_t i, size_t j);
void			arr_reverse(t_arr *src);
void			arr_qsort(t_arr *src, int (*cmp)(const void *, const void *
							, size_t));
void			arr_qsort_r(t_arr *src, void *thunk, int (*cmp)(const void *
							, const void *, size_t, void *));
int8_t			arr_remove(t_arr *src, size_t idx);
int8_t			arr_removem(t_arr *src, size_t idx, size_t len);
char			*arr_tostr(t_arr *src);```
