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
	while (test != 127)
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
	while (test != 127)
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
	while (test != 127)
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
	while (test != 127)
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
	while (test != 127)
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
	while (test <= 127)
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
	while (test != 127)
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
	while (test != 127)
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
	while (test != 127)
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
	while (test != 127)
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

void check_puts()
{
	int             ret;
	int             puts_ret1;
	int             puts_ret2;
	int             out;
	int             p[2];
	char    buf[10000];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	puts_ret1 = ft_puts("aaa");
	puts_ret2 = ft_puts(NULL);
	dup2(out, 1);
	ret = read(p[0], buf, 10000);
	buf[ret] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	if (puts_ret1 > 0)
		is_ok(1);
	else
		is_ok(0);
	if (puts_ret2 > 0)
		is_ok(1);
	else
		is_ok(0);
	if (strcmp(buf, "aaa\n(null)\n") == 0)
		is_ok(1);
	else
		is_ok(0);
	printf("True ret : %d - %d - %d ---- My ret : %d - %d - %d\n", puts("A"), puts("\0"), puts(NULL), ft_puts("A"), ft_puts("ABC"), ft_puts(NULL));
}

void check_strcat(void)
{
	char    buf[9];

	bzero(buf, 9);
	
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	ft_strcat(buf, "");
	if (strcmp(buf, "Bonjour.") == 0)
		is_ok(1);
	else
	{
		printf("buf : [%s]\n", buf);
		is_ok(0);
	}
	if (buf == ft_strcat(buf, ""))
		is_ok(1);
	else
	{
		printf("buf : [%s]\n", buf);
		is_ok(0);
	}
}

void check_memset (void)
{
    /**
    ** -------------------------------------------------------------------------
    ** ft_memset
    ** -------------------------------------------------------------------------
    **/
	char    b1[100], b2[100];

	ft_memset(b1, 42, 100);
	memset(b2, 42, 100);
	if (memset(b1, 99, 0) == ft_memset(b1, 99, 0))
		is_ok(1);
	else
		is_ok(0);
	if (memcmp(b1, b2, 100) == 0)
		is_ok(1);
	else
		is_ok(0);
	b1[0] = 1;
	ft_memset(b1, 0, 0);
	if (b1[0] == 1)
		is_ok(1);
	else
		is_ok(0);
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
    int i;

    i = 0;
    str = NULL;
    new = NULL;
    // str = "COUCOU fskjdlfkjsdfksdjfs\n";
    // new = NULL;
    // new = strdup(str);
    // printf("%s -- %p - %p\n", new, (void*)new, (void*)str);
    // new = NULL;
    // new = ft_strdup(str);
    // printf("%s -- %p - %p\n", new, (void*)new, (void*)str);
    // str = NULL;
    // new = NULL;
    while (i++ < 200)
    {
    	str = ft_strdup("0");
    	new = strdup("0");
    	//printf("str : %s\n new ; %s\n", str, new);
    	str = ft_strdup(" Montpellier, first mentioned in a document of 985, was founded under a local feudal dynasty, the Guilhem, who combined two hamlets and built a castle and walls around the united settlement. The two surviving towers of the city walls, the Tour des Pins and the Tour de la Babotte, were built later, around the year 1200.");
    	new = strdup(" Montpellier, first mentioned in a document of 985, was founded under a local feudal dynasty, the Guilhem, who combined two hamlets and built a castle and walls around the united settlement. The two surviving towers of the city walls, the Tour des Pins and the Tour de la Babotte, were built later, around the year 1200.");
    	//printf("str : %s\n new ; %s\n", str, new);
    	if (strcmp(str, new) == 0)
    		is_ok(1);
    	else
    		is_ok(2);
    }
}

void check_memcpy (void)
{
	/**
	** -------------------------------------------------------------------------
	** ft_memset.s
	** -------------------------------------------------------------------------
	**/
	char    b1[100], b2[100];
	char    a1[100];
	char *a2;
	int i;

	i = 0;

	memset(b1, 33, 100);
	memset(b2, 63, 100);
	memset(a1, 33, 100);
	a2 = "Je suis ici";

	ft_memcpy(b1, b2, 100);
	if (memcmp(b1, b2, 100) == 0)
		is_ok(1);
	else
		is_ok(0);
	if (ft_memcpy(b1, b2, 0) != b1)
		is_ok(1);
	else
		is_ok(0);

	ft_memcpy(a1, a2, 30);
	while (i++ < 11)
	{
		printf("a1 : %c a2 = %c\n", a1[i], a2[i]);
	}

	



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
	while (test != 127)
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
	while (test != 127)
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

void check_strcat2(void)
{
	char 	*dest;
	char 	*dest_bis;

	dest 		= (char*)malloc(sizeof(char)* 20);
	dest_bis 		= (char*)malloc(sizeof(char)* 20);
	ft_strcat(dest, "0");
	strcat(dest_bis, "0");

	printf("\nDest :%s\n", dest);
	printf("Dest_bis :%s\n", dest_bis);

	return ;
}


int main(void)
{
    
    printf("Start testing :");
    // printf("\nft_bzero : ");
    // check_bzero();
    // printf("\nft_isalpha : ");
    // check_isalpha();
    // printf("\n\nft_isgit : ");
    // check_isdigit();
    // printf("\n\nft_isalnum : ");
    // check_isalnum();
    // printf("\n\nft_isascii : ");
    // check_isascii();
    // printf("\n\nft_isprint : ");
    // check_isprint();
    // printf("\n\nft_toupper : ");
    // check_toupper();
    // printf("\n\nft_tolower : ");
    // check_tolower();
    // printf("\n\n[BONUS] - ft_islower : ");
    // check_islower();
    // printf("\n\n[BONUS] - ft_isupper : ");
    // check_isupper();
    // printf("\n\n[BONUS] - ft_isspace : ");
    // check_isspace();
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
    // printf("\n\nft_puts : ");
    // check_puts();
    // printf("\n\nft_memset : ");
    // check_memset();
    printf("\n\nft_memcpy : ");
    check_memcpy();
    printf("\n\nft_strdup : \n");
    check_strdup();
    printf("\n\nft_strcat : ");
    check_strcat();
    check_strcat2();
    // ft_cat(1);
<<<<<<< HEAD
    printf("\n\nBonus : \n");
    printf("\n\nft_putchar : \n");
    check_putchar();
    printf("\n\n[BONUS] - ft_putchar_fd : \n");
    check_putchar_fd(1);
    printf("\n\n[BONUS] - ft_puts_fd : \n");
    check_puts_fd("COUCOU", 0);
    check_puts_fd("", 1);
    check_puts_fd("COUCOU", 2);
=======
    // printf("\n\nBonus : \n");
    // printf("\n\nft_putchar : \n");
    // check_putchar();
    // printf("\n\n[BONUS] - ft_putchar_fd : \n");
    // check_putchar_fd(1);
    // printf("\n\n[BONUS] - ft_puts_fd : \n");
    // check_puts_fd("COUCOU", 0);
    // check_puts_fd("", 1);
    // check_puts_fd("COUCOU", 2);
>>>>>>> 04f33421197542c7223f736fb05698546a69715d
    return (0);
}