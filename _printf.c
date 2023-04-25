#include "main.h"

/**
 * _printf - implementation of printf function
 * @format: string of format specifiers and literals
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				printed_chars += _putchar('%');
			}
			else if (*format == 'c')
			{
				printed_chars += _putchar(va_arg(args, int));
			}
			else if (*format == 's')
			{
				printed_chars += _puts(va_arg(args, char *));
			}
			else if (*format == 'd' || *format == 'i')
			{
				printed_chars += print_number(va_arg(args, int));
			}
			else if (*format == 'u')
			{
				printed_chars += print_unsigned(va_arg(args, unsigned int));
			}
			else if (*format == 'o')
			{
				printed_chars += print_octal(va_arg(args, unsigned int));
			}
			else if (*format == 'x' || *format == 'X')
			{
				printed_chars += print_hex(va_arg(args, unsigned int), (*format == 'X'));
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				printed_chars += 2;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}

