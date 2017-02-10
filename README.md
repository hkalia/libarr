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
This can be best illustrated via example. Take the following piece of code that reads a line from the standard input and then prints it out:
``` C
int		main(void)
{
	char	*array;
	size_t	i;
	int		c;

	array = malloc(sizeof(char) * 50);
	i = 0;
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			array[i] = '\0';
			break ;
		}
		else
			array[i] = c;
		++i;
	}
	printf("%s\n", array);
	free(array);
	return (0);
}
```
The above program will most likely seg fault if the user inputs more than 50 characters on one line. To counter this we need to add two things. A variable that holds the current capacity of the array and a check to see if `i` is higher than that variable.
``` C
int		main(void)
{
	size_t	capacity;
	char	*array;
	size_t	i;
	int		c;

	capacity = 50;
	array = malloc(sizeof(char) * capacity);
	i = 0;
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			array[i] = '\0';
			break ;
		}
		else
			array[i] = c;
		++i;
		if (i >= capacity)
		{
			capacity *= 2;
			array = realloc(array, capacity);
			if (array == 0)
			{
				perror("realloc");
				free(array);
				return (-1);
			}
		}
	}
	printf("%s\n", array);
	free(array);
	return (0);
}
```
This program solves the issue, but you must keep in mind that at 42 we are not allowed to use `realloc`. Here is an implementation without using `realloc`.
``` C
int		main(void)
{
	size_t	capacity;
	char	*array;
	char	*tmp;
	size_t	i;
	size_t	j;
	int		c;

	capacity = 50;
	array = malloc(sizeof(char) * capacity);
	i = 0;
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			array[i] = '\0';
			break ;
		}
		else
			array[i] = c;
		++i;
		if (i >= capacity)
		{
			tmp = malloc(sizeof(char) * (capacity * 2));
			if (tmp == 0)
			{
				perror("malloc");
				free(array);
				return (-1);
			}
			j = 0;
			while (j < capacity)
			{
				tmp[j] = array[j];
				++j;
			}
			free(array);
			array = tmp;
			capacity *= 2;
		}
	}
	printf("%s\n", array);
	free(array);
	return (0);
}
```
As you can see this program has grown quite a bit. here is the same program, but utilizing my dynamic array library.
``` C
int		main(void)
{
	t_arr	array;
	int		c;

	arr_init(&array, 50, (t_arr_elm){sizeof(char), 0, 0, 0});
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
			break ;
		arr_append(&array, &c);
	}
	printf("%s\n", arr_tostr(&array));
	arr_dtr(&array);
	return (0);
}
```
I add some error checking to ensure everything exits properly.
``` C
int		main(void)
{
	t_arr	array;
	int		c;

	GRD(arr_init(&array, 50, (t_arr_elm){sizeof(char), 0, 0, 0}) == -1, -1);
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
			break ;
		GRD2(arr_append(&array, &c) == -1, perror("append"), arr_dtr(&array), -1);
	}
	printf("%s\n", arr_tostr(&array));
	arr_dtr(&array);
	return (0);
}
```
As you can see having a dynamic array can make your code cleaner, easier to read and understand, and make coding easier in general.
### How to use this Dynamic Array Library

_I am currently in the process of writing this section. for now, please take a look at ```examples.c``` for examples on how to use the library_

I will use the following example to explain the basics of how my dynamic array library works:
``` C
int		main(void)
{
	t_arr	str;

	arr_init(&str, 1, (t_arr_elm){sizeof(char), 0, 0, 0});
	arr_appendm(&str, "Hello World!", 13);
	printf("%s\n", str.ptr);
	arr_dtr(&str);
	return (0);
}
```
The above program will print `Hello World!` to the screen. Let's go through the code.
``` C
t_arr	str;
```
This first line declares the array, you can replace `str` with whatever name you would like.  
Then the function `arr_init` is called, it is defined as follows:
``` C
int8_t			arr_init(t_arr *src, size_t cap, t_arr_elm elm);
```
The `arr_init` must be called to initialize the array, if it isn't called, there will be problems. The function sets up the array and does the first allocation. If any of the parameters are equal to 0 the function will return -1. if the allocation fails the function will also return -1. This function makes a call to `malloc(cap * elm.sze)`.  
The first parameter `t_arr *src` takes the address of the array that you would like to perform this function on. All of the functions in this library have the same first parameter (there are small exceptions).  
The second parameter is a `size_t` which represents how big you want your first allocation to be. For example, if you are expecting at least 100 characters, you should pass 100 instead of 1. In this example, for demonstration's sake, I passed 1.  
The third parameter takes the following struct:
``` C
typedef struct	s_elm
{
	size_t	sze;
	int8_t	(*zero)(void *elm);
	int8_t	(*dup)(void *dst, const void *src);
	void	(*dtr)(void *elm);
}				t_arr_elm;
```
In this struct `sze` represents the `sizeof()` whatever data type you are dealing with. In this example we are dealing with the `char` datatype, so we pass `sizeof(char)`. The following `zero`, `dup`, and `dtr` are function pointers. We will get into these later, so for now we pass 0.  
Our final result is the following line:
``` C
arr_init(&str, 1, (t_arr_elm){sizeof(char), 0, 0, 0});
```
However this is not correct. Since this function calls `malloc` it can fail and error out, so we need to do some error checking.  
This library also provides a set of macros to make this easier. They are defined as follows.
``` C
# ifndef GRDS
#  define GRD(a, b) do{if(a){return(b);}}while(0)
#  define GRD1(a, b, c) do{if(a){b;return(c);}}while(0)
#  define GRD2(a, b, c, d) do{if(a){b;c;return(d);}}while(0)
#  define GRD3(a, b, c, d, e) do{if(a){b;c;d;return(e);}}while(0)
#  define GRD4(a, b, c, d, e, f) do{if(a){b;c;d;e;return(f);}}while(0)
#  define GRD5(a, b, c, d, e, f, g) do{if(a){b;c;d;e;f;return(g);}}while(0)
#  define GRD6(a, b, c, d, e, f, g, h) do{if(a){b;c;d;e;f;g;return(h);}}while(0)
# endif
```
These are not required, if you want to, you can remove them. If you decide to use them, here is how you woud use them.
``` C
GRD(arr_init(&str, 1, (t_arr_elm){sizeof(char), 0, 0, 0}) == -1, -1);
```
So, if `arr_init` returns -1, return -1 as well.  
Now we want to add `Hello World!` to our initialized array. We can use the `arr_append` function for this. Here is a table giving a quick overview of all the different functions and what they do.

| Function                                                                                                | Description                                                                     |
| ------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| int8_t	arr_init(t_arr *src, size_t cap, t_arr_elm elm);                                              | Initializes and allocates the array                                             |
| int8_t	arr_reserve(t_arr *src, size_t sze);                                                          | Reserve `sze` amount of space in `src` allocating more if necessary             |
| int8_t	arr_resize(t_arr *src, size_t sze);                                                           | Resize `src` to `sze` elements allocating or removing as necessary              |
| void		arr_dtr(t_arr *src);                                                                          | Frees and resets the array. `arr_init` must be called again                     |
| int8_t	arr_insert(t_arr *dst, size_t idx, const void *src);                                          | Inserts `src` at index `idx` in array `dst`                                     |
| int8_t	arr_insertm(t_arr *dst, size_t idx, const void *src, size_t src_len);                         | Takes `src_len` elements from `src` and inserts into array `dst` at index `idx` |
| int8_t	arr_insertarr(t_arr *dst, size_t idx, t_arr *src);                                            | Inserts array 'src' into array 'dst' at index 'i'                               |
| int8_t	arr_append(t_arr *dst, const void *src);                                                      | Appends `src` to array `dst`                                                    |
| int8_t	arr_appendm(t_arr *dst, const void *src, size_t src_len);                                     | Appends `src_len` elements from `src` into array 'dst'                          |
| int8_t	arr_appendarr(t_arr *dst, t_arr *src);                                                        | Appends array `src` to array `dst`                                              |
| void		arr_swap(t_arr *src, size_t i, size_t j);                                                     | Swaps elements at index `i` and index `j`                                       |
| void		arr_reverse(t_arr *src);                                                                      | Reverses the array, (first element becomes last)                                |
| void		arr_qsort(t_arr *src, int (*cmp)(const void *, const void *, size_t));                        | Sorts array according to `cmp`                                                  |
| void		arr_qsort_r(t_arr *src, void *thunk, int (*cmp)(const void *, const void *, size_t, void *)); | Sorts array according to `cmp` passing `thunk` unchanged                        |
| int8_t	arr_remove(t_arr *src, size_t idx);                                                           | Removes element at index `idx` from array `src`                                 |
| int8_t	arr_removem(t_arr *src, size_t idx, size_t len);                                              | Removes `len` elements starting at index `idx` from array `src`                 |
| char		*arr_tostr(t_arr *src);                                                                       | Converts `src` into a valid C string by appending a null character              |
