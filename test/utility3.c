#include "main.h"

/**
 * printInteger - Print an integer value to screen.
 * @pcc: Printed Character Counter - a pointer to a counter of the
 *		number of printed characters.
 * @args: Arguments list pointer.
 * Return: Returns void;
 */
void printInteger(int *pcc, va_list args)
{
	unsigned int mag = 1000000000;
	short sign;
	int value;

	value = va_arg(args, int);
	sign = (value < 0) ? -1 : 1;
	value *= sign;
	while ((value / mag) == 0 && value != 0)
		mag /= 10;
	if (sign == -1)
	{
		_putchar('-');
		*pcc = *pcc + 1;
	}
	while (mag != 0)
	{
		_putchar('0' + (value / mag));
		*pcc = *pcc + 1;
		value = value % mag;
		mag /= 10;
	}
}
