#include "main.h"

/**
 * print_string - Prints a string to stdout
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(const char *str)
{
	int count = 0;

	while (*str)
	{
		count += print_char(*str);
		str++;
	}
	return (count);
}

/**
 * print_char - Writes a character to stdout
 * @c: The character to write to stdout
 *
 * Return: On success, the number of bytes written (1)
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_int - Prints an integer to stdout
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_int(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += print_char('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_int(num / 10);
	}
	count += print_char((num % 10) + '0');

	return (count);
}

/**
 * handle_format - Handles the format specifiers in the format string
 * @format: The format string
 * @args: The argument list
 *
 * Return: The number of characters printed
 */
int handle_format(const char *format, va_list args)
{
	int count = 0, i;

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				count += print_char(va_arg(args, int));
			}
			else if (format[i] == 's')
			{
				count += print_string(va_arg(args, char *));
			}
			else if (format[i] == '%')
			{
				count += print_char('%');
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				count += print_int(va_arg(args, int));
			}
			else
			{
				count += print_char('%');
				count += print_char(format[i]);
			}
		}
		else
		{
			count += print_char(format[i]);
		}
	}
	return (count);
}

/**
 * _printf - Produces output according to a format
 * @format: A character string composed of zero or more directives
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = handle_format(format, args);
	va_end(args);

	return (count);
}
