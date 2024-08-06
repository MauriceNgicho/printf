#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * 
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_char - prints a char
 * @args: argument list
 * 
 * Return: number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (_putchar(c));
}

/**
 * print_string - prints a string
 * @args: argument list
 * 
 * Return: number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int i = 0;

    if (!str)
        str = "(null)";
    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }
    return (i);
}

/**
 * print_percent - prints a percent symbol
 * @args: argument list
 * 
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
    (void)args;
    return (_putchar('%'));
}

/**
 * print_int - prints an integer
 * @args: argument list
 * 
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    char buffer[50];
    int i = 0, count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }
    while (n / 10)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }
    buffer[i] = (n % 10) + '0';
    while (i >= 0)
    {
        count += _putchar(buffer[i--]);
    }
    return (count);
}
