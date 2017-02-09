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

	arr_init(&array, 2, (t_arr_elm){sizeof(char), 0, 0, 0});
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
### How to use this Dynamic Array Library

_I am currently in the process of writing this section. for now, please take a look at ```examples.c``` for examples on how to use the library_
