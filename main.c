#include "includes/libftasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>



#undef SIZE
#define SIZE 100

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

int check_strcat(void)
{
    char dest[64] = "hello";


   strcat(dest , "world");
   printf ("%s\n", dest);
   ft_strcat(dest, "TOTO");
   printf("%s\n", dest);

    return (0);
}

void check_memset (void)
{
    /**
    ** -------------------------------------------------------------------------
    ** ft_memset
    ** -------------------------------------------------------------------------
    **/

    // char *mems;
    char    mems[4];

    // mems = (char*)malloc(sizeof(char)* 4);

    ft_bzero(mems, 4);
    printf("str[0] = %d\n", mems[0]);
    printf("str[1] = %d\n", mems[1]);
    printf("str[2] = %d\n", mems[2]);
    printf("str[3] = %d\n", mems[3]);
    printf("--- memseting with 'a' ---\n");
    ft_memset(mems, 'a', 4);
    printf("str[0] = %c (%d)\n", mems[0], mems[0]);
    printf("str[1] = %c (%d)\n", mems[1], mems[1]);
    printf("str[2] = %c (%d)\n", mems[2], mems[2]);
    printf("str[3] = %c (%d)\n", mems[3], mems[3]);
}


void    check_strdupbis(void)
{
    char *str;
    char *new;

    str = "COUCOU fskjdlfkjsdfksdjfs\n";
    new = NULL;
    new = strdup(str);
    printf("%s -- %p - %p\n", new, (void*)new, (void*)str);
    new = NULL;
    new = ft_strdup(str);
    printf("%s -- %p - %p\n", new, (void*)new, (void*)str);
}
void check_memcpy (void)
{
    /**
    ** -------------------------------------------------------------------------
    ** ft_memset
    ** -------------------------------------------------------------------------
    **/
    char    mems[4];
    char    memsdest[4];

    ft_bzero(memsdest, 3);
    printf("str[0] = %d\n", mems[0]);
    printf("str[1] = %d\n", mems[1]);
    printf("str[2] = %d\n", mems[2]);
    printf("str[3] = %d\n", mems[3]);
    printf("--- memseting with 'a' ---\n");
    ft_memset(mems, 'b', 4);

    printf("TRUE memcpy\n");
    memcpy(memsdest, mems, 4);
    printf("str[0] = %c (%d) || dst[0] = %c (%d)\n", mems[0], mems[0], memsdest[0], memsdest[0]);
    printf("str[1] = %c (%d) || dst[1] = %c (%d)\n", mems[1], mems[1], memsdest[1], memsdest[1]);
    printf("str[2] = %c (%d) || dst[2] = %c (%d)\n", mems[2], mems[2], memsdest[2], memsdest[2]);
    printf("str[3] = %c (%d) || dst[3] = %c (%d)\n", mems[3], mems[3], memsdest[3], memsdest[3]);
    
    printf("MY memcpy\n");
    ft_memcpy(memsdest, mems, 4);
    printf("str[0] = %c (%d) || dst[0] = %c (%d)\n", mems[0], mems[0], memsdest[0], memsdest[0]);
    printf("str[1] = %c (%d) || dst[1] = %c (%d)\n", mems[1], mems[1], memsdest[1], memsdest[1]);
    printf("str[2] = %c (%d) || dst[2] = %c (%d)\n", mems[2], mems[2], memsdest[2], memsdest[2]);
    printf("str[3] = %c (%d) || dst[3] = %c (%d)\n", mems[3], mems[3], memsdest[3], memsdest[3]);
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
    printf("\n\nft_memset : \n");
    check_memset();
    printf("\n\nft_memcpy : \n");
    check_memcpy();
    printf("\n\nft_strdup : \n");
    check_strdupbis();
    printf("\n\nft_strcat : \n");
    ret = check_strcat();
    printf("finish\n");
    ft_cat(1);
    // ft_test("NOTHING");
    return (0);
}