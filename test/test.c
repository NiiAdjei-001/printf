#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int i, _i;
	
	printf("########## TEST ##########\n");
	printf("Test Count:\n");
	i = printf("printf - %c",'c');
	printf("\n");
	_i = _printf("printf - %c",'c');
	printf("\n");
	printf("i = [%d] _i = [%d]\n", i, _i);
	printf("\nTest _printf with String specifier\n");
	_printf("printf(dog): %s", "dog");
	printf("\n\nTest _printf with Character specifier\n");
	_printf("printf(N): %c", 'N');
	printf("\n\nTest _printf with no specifier\n");
	_printf("printf(The fat pig): The fat pig");
	printf("\n\nTest _printf with Percentage specifier\n");
	_printf("printf(%): %%");
	printf("\n\nTest _printf with Unregisted specfier\n");
	_printf("printf(%r): %r");
	printf("\n\nTest _printf with Integer specfier\n");
	_printf("printf(d): %d, %d, %d, %d, %d", 10, 200, 300, 4567, -90054);
	printf("\n");
	_printf("printf(i): %i, %i, %i, %i, %i", 10, 200, 300, 4567, -90054);
	printf("\n");
	_i = _printf("Goat Works Test%");
	printf("%d\n", _i);
	_printf("Testing binary of 20 = %b",20);
	_putchar('\n');
	return (0);
}
