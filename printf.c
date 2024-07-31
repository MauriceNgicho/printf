#include "main.h"
#include <stddef.h>

/**
 * print_string - Prints a string to stdout
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(const char *str)
{
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

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
 * specifiers_format - Handles format specifiers
 * @format: Pointer to the format string
 * @args: Variable argument list
 *
 * Return: The number of characters printed
 */
int specifiers_format(const char **format, va_list args)
{
	int count = 0;

	switch (**format)
	{
		case 'c':
			count += print_char(va_arg(args, int));
			break;
		case 's':
			count += print_string(va_arg(args, char *));
			break;
		case '%':
			count += print_char('%');
			break;
		case 'd':
		case 'i':
			count += print_char(va_arg(args, int));
			break;
		default:
			count += print_char('%');
			count += print_char(**format);

			break;
	}
	return (count);
}
/**
 * _printf - Produces output according to a format
 * @format: A character string composed of zero or more directives
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += specifiers_format(&format, args);
		}
		else
		{
			count += print_char(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
