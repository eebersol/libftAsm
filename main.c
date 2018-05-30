#include "includes/libftasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>

void    is_ok(int ok)
{
	ok ? printf("\033[0;32m\033[1m.\033[0m") : printf("\033[0;31m\033[1mF\033[0m");
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
   if (ft_isalpha(ret) == isalpha(ret))
		is_ok(1);
	else
		is_ok(0);
    return (ret);
}

int check_isdigit(int ret)
{
   if (ft_isdigit(ret) == isdigit(ret))
        is_ok(1);
    else
        is_ok(0);

    return (ret);
}

int check_isalnum(int ret)
{
   if (ft_isalnum(ret) == isalnum(ret))
        is_ok(1);
    else
        is_ok(0);

    return (ret);
}

int check_isascii(int ret)
{
   if (ft_isascii(ret) == isascii(ret))
        is_ok(1);
    else
        is_ok(0);

    return (ret);
}

int check_isprint(int ret)
{
   if (ft_isprint(ret) == isprint(ret))
        is_ok(1);
    else
        is_ok(0);

    return (ret);
}

int check_toupper(int ret)
{
   if (ft_toupper(ret) == toupper(ret))
        is_ok(1);
    else
        is_ok(0);

    return (ret);
}

int check_tolower(int ret)
{   
    if (ft_tolower(ret) == tolower(ret))
        is_ok(1);
    else
        is_ok(0);

    return (ret);
}

int check_strlen(char* str)
{   
    if (ft_strlen(str) == strlen(str))
        is_ok(1);
    else
        is_ok(0);

    return (strlen(str));
}

int check_puts(char* str)
{
    write(1, "My puts : ", 10);  
    ft_puts(str);
    write(1, "True puts : ", 12);
    puts(str);

    return (strlen(str));
}

int check_strcat(char *str, char *str2)
{
   printf("%s\n", ft_strcat(str, str2));
    // if (strcmp(ft_strcat(str, str2), strcat(str, str2)))
    //     is_ok(1);
    // else
    //     is_ok(0);

    return (strlen(str));
}

int main(void)
{
    int ret = 0;
    printf("Start testing :");
    ret = check_bzero(ret);
    printf("\n\nft_isalpha : \n");
    ret = check_isalpha('a');
    ret = check_isalpha('b');
    ret = check_isalpha('c');
    ret = check_isalpha(1);
    ret = check_isalpha(1);
    ret = check_isalpha(111);
    printf("\n\nft_isgit : \n");
    ret = check_isdigit(1);
    ret = check_isdigit(2);
    ret = check_isdigit(3);
    ret = check_isdigit('a');
    ret = check_isdigit('b');
    ret = check_isdigit('c');
    ret = check_isdigit(40);
    ret = check_isdigit(50);
    ret = check_isdigit(60);
    printf("\n\nft_isalnum : \n");
    ret = check_isalnum(1);
    ret = check_isalnum(2);
    ret = check_isalnum(3);
    ret = check_isalnum('*');
    ret = check_isalnum('-');
    ret = check_isalnum('/');
    ret = check_isalnum(400);
    ret = check_isalnum(50);
    ret = check_isalnum(60);
    printf("\n\nft_isascii : \n");
    ret = check_isascii(1);
    ret = check_isascii(2);
    ret = check_isascii(3);
    ret = check_isascii('*');
    ret = check_isascii('-');
    ret = check_isascii('/');
    ret = check_isascii(400000000);
    ret = check_isascii(50);
    ret = check_isascii(60);
    printf("\n\nft_isprint : \n");
    ret = check_isprint(1);
    ret = check_isprint(2);
    ret = check_isprint(3);
    ret = check_isprint('*');
    ret = check_isprint('-');
    ret = check_isprint('/');
    ret = check_isprint(400000000);
    ret = check_isprint(50);
    ret = check_isprint(60);
    printf("\n\nft_toupper : \n");
    ret = check_toupper('a');
    ret = check_toupper('b');
    ret = check_toupper('C');
    ret = check_toupper('*');
    ret = check_toupper('-');
    ret = check_toupper('/');
    ret = check_toupper(400000000);
    ret = check_toupper(50);
    ret = check_toupper(60);
    printf("\n\nft_tolower : \n");
    ret = check_tolower('A');
    ret = check_tolower('B');
    ret = check_tolower('c');
    ret = check_tolower('*');
    ret = check_tolower('-');
    ret = check_tolower('/');
    ret = check_tolower(400000000);
    ret = check_tolower(50);
    ret = check_tolower(60);
    printf("\n\nft_strlen : \n");
    ret = check_strlen("Aaaaa");
    ret = check_strlen("Bbb");
    ret = check_strlen("cccc");
    ret = check_strlen("");
    ret = check_strlen("*dasd");
    ret = check_strlen("-");
    ret = check_strlen("/");
    ret = check_strlen("0");
    ret = check_strlen("0");
    ret = check_strlen("0");
    printf("\n\nft_puts : \n");
    ret = check_puts("Aaaaa");
    ret = check_puts("Bbbbb");
    ret = check_puts("Ccccc");
    printf("\n\nft_strcat : \n");
    ret = check_strcat("123", "456");
    printf("\n\nfailed == %i\n", ret);
    return (ret && ret > 0 ? 2 : 0);
}