#ifndef LIBFTASM_H
# define LIBFTASM_H
# include <strings.h>

void	ft_bzero(void *s, size_t n);
char 	*ft_strcat(char *dest, const char *src);
int 	ft_isalpha(int c);
int 	ft_isdigit(int c);
int 	ft_isalnum(int c);
int 	ft_isascii(int c);
int 	ft_isprint(int c);
int 	ft_toupper(int c);
int 	ft_tolower(int c);
int 	ft_puts(const char *s);
size_t	ft_strlen(const char *s);
char 	*ft_strcat(char *dest, const char *src);
void 	*ft_memset (void *s, int c, size_t n);


#endif


