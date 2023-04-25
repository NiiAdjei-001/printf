#include "main.h"

/**
 * printBinary - Print binary format of an integer value to screen.
 * @pcc: Printed Character Counter - a pointer to a counter of the
 *		number of printed characters.
 * @args: Arguments list pointer.
 * Return: Returns void;
 */
void printBinary(int *pcc, va_list args)
{
	unsigned int mag = 1;
	unsigned int binary = 0;
	int value;

	value = va_arg(args, int);
	if (value < 0)
		*pcc = -1;
	else
	{
		while (value != 0)
		{
			binary += (value % 2) * mag;
			mag *= 10;
			value /= 2;
		}
		mag /= 10;
		while (mag != 0)
		{
			_putchar('0' + (binary / mag));
			if (*pcc != -1)
				*pcc = *pcc + 1;
			binary %= mag;
			mag /= 10;
		}
	}
}
