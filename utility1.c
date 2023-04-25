#include "main.h"
/**
 * getArgC - Get Argument Count. Gets the number of arguments
 *		required by formated string.
 * @str: String format
 * Return: returns the number of place holders.
 */
int getArgC(char *str)
{
	int count;

	for (count = 0; *str != '\0'; str++)
	{
		if (*str == '%')
		{
			if (*(str + 1) != '%')
				count++;
			else
				continue;
		}
	}
	return (count);
}

/**
 * _putchar - Prints a character byte.
 * @c: Character byte to be printed.
 * Return: Fileid.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * runESSubroutine - Runs the Escape Sequence Subroutine.
 *		Executes code that handles '\[character]' routines.
 * @format: format string.
 * @fi: Format Index - a pointer to the index of the character in
 *		the format string which is being worked on.
 * @pcc: Printed Character Counter - a pointer to a counter of the
 *		number of printed characters.
 * Return: Returns void;
 */
void runESSubroutine(char *format, int *fi, int *pcc)
{
	char escapeChar;

	escapeChar = format[*fi];
	*fi = *fi + 1;
	_putchar(escapeChar);
	*pcc = *pcc + 1;
}

/**
 * runFSSubroutine - Runs the Format Specifier Subroutine.
 *		Executes code that handles '%[character]' routines.
 * @format: format string.
 * @fi: Format Index - a pointer to the index of the character in the
 *		format string which is being worked on.
 * @pcc: Printed Character Counter - a pointer to a counter of the
 *		number of printed characters.
 * @args: Arguments list pointer.
 * Return: Returns void;
 */
void runFSSubroutine(char *format, int *fi, int *pcc, va_list args)
{
	char specifier;
	*fi = *fi + 1;
	specifier = format[*fi];
	switch (specifier)
	{
		case '\0':
			*fi = *fi - 1;
			*pcc = -1;
			break;
		case '\\':
			*fi = *fi - 1;
			*pcc = -1;
			break;
		case '%':
			printPercentage(pcc);
			break;
		case 'c':
			printCharacter(pcc, args);
			break;
		case 's':
			printString(pcc, args);
			break;
		case 'd':
			printInteger(pcc, args);
			break;
		case 'i':
			printInteger(pcc, args);
			break;
		case 'b':
			printBinary(pcc, args);
			break;
		default:
			printDefault(format, fi, pcc);
			break;
	}
}

/**
 * _printf - Print a string to the screen in the format specified.
 * @format: format string
 * Return: The number of characters printed to screen.
 */
int _printf(char *format, ...)
{
	va_list args;
	int fi, pcc;

	if (*format)
	{
		pcc = 0;
		va_start(args, format);
		for (fi = 0; *(format + fi) != '\0'; fi++)
		{
			if (format[fi] == '%')
			{
				runFSSubroutine(format, &fi, &pcc, args);
			}
			else if (format[fi] == '\\')
			{
				runESSubroutine(format, &fi, &pcc);
			}
			else
			{
				_putchar(format[fi]);
				if (pcc != -1)
					pcc++;
			}

		}
		va_end(args);
		return (pcc);
	}
	return (-1);
}
