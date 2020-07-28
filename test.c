#include "includes/ft_printf.h"
#include "unistd.h"
int main()
{
    int res;

    res = ft_printf("str: '%s', num:'%d', hex:'%x' or '%X'\n", "sample", 255, 255, 255);
    ft_printf("res : %d\n", res);

}
