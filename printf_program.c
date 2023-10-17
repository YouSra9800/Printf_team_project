#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Print formatted text to stdout
 * @format: The format string
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...) {
    va_list args;
    int count = 0;  // To keep track of characters printed.

    va_start(args, format);

    while (*format) {
        if (*format != '%') {
            putchar(*format);
            count++;
        } else {
            format++;  // Move to the next character after '%'
            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);  // char promotes to int in varargs
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        format++;  // Move to the next character in the format string.
    }

    va_end(args);
    return count;
}

