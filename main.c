#include "includes/libftasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

void    is_ok(int ok)
{
	ok ? printf("\033[0;32m\033[1m.\033[0m") : printf("\033[0;31m\033[1mF\033[0m");
}

int	check_is(int ret, int (*mine)(int c), int c, int (*real)(int c))
{    
    if (mine(c) == real(c) || (mine(c) == 1 && real(c) != 0))
        is_ok(1);
    else
    {        
        is_ok(0);
        printf("([%i] %i != %i)", c, mine(c),  real(c));
        ret++;
    }
    return (ret);
}

int iter_check_is(char *title, char *str, int ret, int (*mine)(int c), int (*real)(int c))
{
    int i = 0;

    printf("\n\n%s\n", title);
    for (i = 0 ; i < (int)strlen(str) ; i++)
        ret = check_is(ret, mine, str[i], real);
    return (ret);
}

int check_bzero(int ret)
{
    char *ptr 	= NULL;
    int i 		= 50;

    printf("\n\nft_bzero : \n");    
    ptr 		= (char *)malloc(sizeof(char) * i);
    ft_bzero(ptr, i);
    while (--i >= 0)
    {
        if (ptr[i] == 0)
            is_ok(1);
        else
        {
            is_ok(0);
            ret++;
        }
    }    
    return (ret);
}

int check_isalpha(int ret)
{
	ret = 3;
    printf("\n\nft_strcat : \n");    
   ret		= ft_isalpha(ret);
   if (ret == 0)
		printf("ret :nop\n");
	else
		printf("ret :ok\n");
    return (ret);
}

int main(void)
{
    int ret = 0;
    printf("Start testing :");
    ret = check_bzero(ret);
    ret = check_isalpha('|');
    ret = check_isalpha('a');
    printf("\n\nfailed == %i\n", ret);
    return (ret && ret > 0 ? 2 : 0);
}