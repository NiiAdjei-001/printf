#include "main.h"

/**
 * printCharacter - Print a character byte to screen.
 * @pcc: Printed Character Counter - a pointer to a counter of the
 *		number of printed characters.
 * @args: Arguments list pointer.
 * Return: Returns void;
 */
void printCharacter(int *pcc, va_list args)
{
	_putchar(va_arg(args, int));
	if (*pcc != -1)
		*pcc = *pcc + 1;
}

/**
 * printString - Print a string of bytes to screen.
 * @pcc: Printed Character Counter - a pointer to a counter of the
 *		number of printed characters.
 * @args: Arguments list pointer.
 * Return: Returns void;
 */
void printString(int *pcc, va_list args)
{
	char *sval;

	sval = va_args(args, char*);
	if (sval == null)
		*pcc = -1;
	else
	{
		for (; *sval; sval++)
		{
			_putchar(*sval);
			if (*pcc != -1)
				*pcc = *pcc + 1;
		}
	}
}

/**
 * printPercentage - Print a '%' character.
 * @pcc: Printed Character Counter - a pointer to a counter of the
 *		number of printed characters.
 * Return: Returns void;
 */
void printPercentage(int *pcc)
{
	_putchar('%');
	if (*pcc != -1)
		*pcc = *pcc + 1;
}

/**
 * printDefault - Handles default printing situation.
 * @format: format string.
 * @fi: Format Index - a pointer to the index of the character in the
 *		format string which is being worked on.
 * @pcc: Printed Character Counter - a pointer to a counter of the
 *		number of printed characters.
 * Return: Returns void;
 */
void printDefault(char *format, int *fi, int *pcc)
{
	_putchar('%');
	_putchar(format[*fi]);
	if (*pcc != -1)
		*pcc = *pcc + 2;
}

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
		if (*pcc != -1)
			*pcc = *pcc + 1;
	}
	while (mag != 0)
	{
		_putchar('0' + (value / mag));
		if (*pcc != -1)
			*pcc = *pcc + 1;
		value = value % mag;
		mag /= 10;
	}
}
