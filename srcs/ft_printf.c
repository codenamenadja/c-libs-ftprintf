/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 10:27:36 by jihhan            #+#    #+#             */
/*   Updated: 2020/07/27 19:12:53 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "includes/ft_additionals.h"


int ft_printf(const char *fmt, ...)
{
    va_list ap; 
    char buf[BUFSIZ];
    char *str;
    int i;
    char key;

    va_start(ap, fmt);
    i = 0;
    while (*(fmt + i) != '\0')
    {
        if(*(fmt + i) == '%')
        {
            switch(*(fmt + (i + 1)))
            {
                case 'c':
                    key = (int)(va_arg(ap, int));
                    strncat(buf, &key, 1);
                    break;
                case 's':
                    strcat(buf,(char *)(va_arg(ap, char *)));
                    break;
                case 'd':
                    str = ft_itoa((int)va_arg(ap, int));
                    break;
                case 'i':
                    str = ft_itoa((int)va_arg(ap, int));
                    break;
                case 'u':
                    str = ft_utoa((unsigned int)va_arg(ap, int));
                    break;
                case 'p':
                    strncat(buf, "0x\0", 2);
                    str = ft_ltox((long)va_arg(ap, void *));
                    break;
                case 'x':
                    str = ft_ltox((long)va_arg(ap, long));
                    break;
                case 'X':
                    str = ft_ltox((long)va_arg(ap, long));
                    key = 0;
                    while (*(str + key))
                    {
                        *(str + key) = 
                            (*(str + key) >= 'a') ? 
                            toupper(*(str + key)) : *(str + key);
                        key++;
                    }
                    break;
                default:
                    strncat(buf, (fmt+i), 2);
                    break;
            }
            i += 2;
            if(str != NULL)
            {
                strcat(buf, str);
                free(str);
            }
        }   else
        {
            strncat(buf, fmt+i, 1);
            i++;
        }
                
    }
    va_end(ap);
    strncat(buf, "\0", 1);
    i = strlen(buf);
    write(STDOUT_FILENO, buf, i);
    memset(buf, 0, i);
    return (i);
}

