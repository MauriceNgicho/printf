#include "main.h"


/**
 * num_of_char - Prints a string to stdout
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int num_of_char(const char *str)
{
	int count = 0;


	while (*str)

	{
		count += num_of_char(*str);
		str++;
	}
	return (count);
}


/**
 * prnt_char - Writes a character to stdout.
 * @c: The character to write to stdout.
 *
 * Return: On success, the number of bytes written (1).
 */

int prnt_char(char c)
{
	return (write(1, &c, 1));
}


/**
 * _printf - Produces output according to format used
 * @format: A character string composed of zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte
 * used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int p;

	va_start(args, format);

	for (p = 0; format[p] != '\0'; p++)
	{
		if (format[p] == '%')
		{
			i++;
			if (format[p] == 'c')
			{
				count += num_of_char(va_arg(args, int));
			}
			else if (format[p] == 's')
			{
				count += num_of_char(va_arg(args, char *));
			}
			else if (format[p] == '%')
			{
				count += num_of_char('%');
			}
			else
			{
				count += num_of_char('%');
				count += num_of_char(format[p]);
			}
		}
		else
		{
			count += num_of_char(format[p]);
		}
	}


	va_end(args);
	return (count);
}
