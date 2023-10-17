#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Additional arguments based on format specifiers
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format) {
        if (*format != '%') {
            write(1, format, 1);
            count++;
        } else {
            format++; // Move past '%'
            if (*format == 'c') {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            } else if (*format == 's') {
                char *str = va_arg(args, char *);
                int i = 0;
                while (str[i]) {
                    write(1, &str[i], 1);
                    i++;
                    count++;
                }
            } else if (*format == '%') {
                write(1, "%", 1);
                count++;
            } else {
                write(1, "%", 1);
                write(1, format, 1);
                count += 2;
            }
        }
        format++;
    }

    va_end(args);
    return count;
}

