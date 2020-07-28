#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef __FT_ADDITIONALS__H
# define __FT_ADDITIONALS__H
char        *ft_substr(char const *s, unsigned int start, size_t len);
char        *ft_strjoin(char const *s1, char const *s2);
char        *ft_strtrim(char const *s1, char const *set);
char        **ft_split(char const *s, char c);
char        *ft_itoa(int n);
char        *ft_ltox(long n);
char        *ft_utoa(unsigned long n);
char        *ft_strmapi(char const *s, char (*f)(unsigned int, char));
#endif
