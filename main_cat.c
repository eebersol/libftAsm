
#include <fcntl.h>
#include <stdio.h>

void ft_cat(int fd);

int main(int ac, char **av)
{
	(void)ac;
	// ft_cat(0);
	// printf("1\n");
	// ft_cat(open("main.c", O_RDONLY));
	// printf("2\n");
	ft_cat(open(av[0], O_RDONLY));
	// ft_cat(-42);
	return(0);
}