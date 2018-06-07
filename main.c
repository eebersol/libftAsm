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


void check_bzero(void)
{
    char *ptr 	= NULL;
    int i 		= 50;
 
    ptr 		= (char *)malloc(sizeof(char) * i);
    ft_bzero(ptr, i);
    while (--i >= 0)
    {
        if (ptr[i] == 0)
            is_ok(1);
        else
            is_ok(0);
    }    
	return;
}

void check_isalpha(void)
{
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_isalpha(test) == isalpha(test))
			is_ok(1);
		else
			is_ok(0);
		test++;
	}
	return;
}

void check_isdigit(void)
{
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_isdigit(test) == isdigit(test))
			is_ok(1);
		else
			is_ok(0);
		test++;
	}
	return;
}

void check_isalnum(void)
{
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_isalnum(test) == isalnum(test))
			is_ok(1);
		else
			is_ok(0);
		test++;
	}
	return;
}

void check_isascii(void)
{
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_isascii(test) == isascii(test))
			is_ok(1);
		else
			is_ok(0);
		test++;
	}
	return;
}

void check_isspace(void)
{
	int test;

	test = 0;
	while (test != '~')
	{
		if (ft_isspace(test) == isspace(test))
			is_ok(1);
		else
			is_ok(0);

		test++;
	}
	return;
}

void check_isprint(void)
{
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_isprint(test) == isprint(test))
			is_ok(1);
		else
			is_ok(0);
		test++;
	}
	return;
}

void check_toupper(void)
{
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_toupper(test) == toupper(test))
			is_ok(1);
		else
			is_ok(0);
		test++;
	}
	return;
}

void check_tolower(void)
{   
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_tolower(test) == tolower(test))
			is_ok(1);
		else
			is_ok(0);
		test++;
	}
	return;
}

void check_islower(void)
{
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_islower(test) == islower(test))
			is_ok(1);
		else
			is_ok(0);
		test++;
	}
	return;
}

void check_isupper(void)
{
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_isupper(test) == isupper(test))
			is_ok(1);
		else
			is_ok(0);
		test++;
	}
	return;

}

void check_strlen(char *str)
{
    if (ft_strlen(str) == strlen(str))
        is_ok(1);
    else
        is_ok(0);

    return ;
}

void check_puts(char* str)
{
    ft_puts(str);
    puts(str);

    return;
}

void check_strcat(void)
{
    char dest[64] = "hello";
    char dest_true[64] = "hello";


   strcat(dest , "world");
   printf ("%s\n", dest);
   ft_strcat(dest_true, "world");
   printf("%s\n", dest_true);
   return;
}

void check_memset (void)
{
    /**
    ** -------------------------------------------------------------------------
    ** ft_memset
    ** -------------------------------------------------------------------------
    **/
    char    mems[4];

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


void    check_strdup(void)
{
	/**
	** -------------------------------------------------------------------------
	** ft_strdup.s
	** -------------------------------------------------------------------------
	**/
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
	** ft_memset.s
	** -------------------------------------------------------------------------
	**/
	char	mems[4];
	char	memsdest[4];

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

void	check_putchar (void)
{
	/**
	** -------------------------------------------------------------------------
	** ft_putchar.s
	** -------------------------------------------------------------------------
	**/
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_isprint(test) == isprint(test))
			ft_putchar(test);
		test++;
	}
	return;
}

void    check_putchar_fd (int fd)
{
    /**
    ** -------------------------------------------------------------------------
    ** ft_putchar.s
    ** -------------------------------------------------------------------------
    **/
	int test;

	test = '!';
	while (test != '~')
	{
		if (ft_isprint(test) == isprint(test))
			ft_putchar_fd(test, fd);
		test++;
	}
	return;
}

void    check_puts_fd (char *str, int fd)
{
    /**
    ** -------------------------------------------------------------------------
    ** ft_putchar.s
    ** -------------------------------------------------------------------------
    **/
    ft_puts_fd(str, fd);
}


int main(void)
{
    
    printf("Start testing :");
    printf("\nft_bzero : ");
    check_bzero();
    printf("\nft_isalpha : ");
    check_isalpha();
    printf("\n\nft_isgit : ");
    check_isdigit();
    printf("\n\nft_isalnum : ");
    check_isalnum();
    printf("\n\nft_isascii : ");
    check_isascii();
    printf("\n\nft_isprint : ");
    check_isprint();
    printf("\n\nft_toupper : ");
    check_toupper();
    printf("\n\nft_tolower : ");
    check_tolower();
    printf("\n\n[BONUS] - ft_islower : \n");
    check_islower();
    printf("\n\n[BONUS] - ft_isupper : \n");
    check_isupper();
    printf("\n\n[BONUS] - ft_isspace : ");
    check_isspace();
    printf("\n\nft_strlen : ");
    check_strlen("Aaaaa");
    check_strlen("Bbb");
    check_strlen("cccc");
    check_strlen("");
    check_strlen("*dasd");
    check_strlen("-");
    check_strlen("/");
    check_strlen("0");
    check_strlen("0");
    check_strlen("0");
    printf("\n\nft_puts :\n\n");
    check_puts("Aaaaa");
    check_puts("Bbbbb");
    check_puts("Ccccc");
    printf("\n\nft_memset : \n");
    check_memset();
    printf("\n\nft_memcpy : \n");
    check_memcpy();
    printf("\n\nft_strdup : \n");
    check_strdup();
    printf("\n\nft_strcat : \n");
    check_strcat();
    // ft_cat(1);
    printf("\n\nBonus : \n");
    printf("\n\nft_putchar : \n");
    check_putchar();
    printf("\n\n[BONUS] - ft_putchar_fd : \n");
    check_putchar_fd(1);
    printf("\n\n[BONUS] - ft_puts_fd : \n");
    check_puts_fd("COUCOU", 0);
    check_puts_fd("", 1);
    check_puts_fd("COUCOU", 2);
    return (0);
}