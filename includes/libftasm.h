#ifndef LIBFTASM_H
# define LIBFTASM_H
# include <strings.h>

void	ft_bzero(void *s, size_t n);
int 	ft_isalpha(int c);
int 	ft_isdigit(int c);
int 	ft_isalnum(int c);
int 	ft_isascii(int c);
int 	ft_isprint(int c);
int 	ft_toupper(int c);
int 	ft_tolower(int c);
int 	ft_puts(const char *s);
int 	ft_test(const char *s);
size_t	ft_strlen(const char *s);
char 	*ft_strcat(char *dest, const char *src);
void 	*ft_memset(void *s, int c, size_t n);
void 	*ft_memcpy(void *dest, const void *src, size_t n);
char 	*ft_strdup(const char *s);
void 	*ft_cat(int fd);


// Bonus
void 	ft_putchar(char c);
void 	ft_putchar_fd(char c, int fd);
void 	ft_puts_fd(char *str, int fd);
char		ft_str_search(char *str, char find);

#endif




// ARG : rdi, rsi, rcx


// registre ::

// rax
// rdi
// rsi
// rcx
// rdx



//strcat :: rdi = DEST / rsi = SRC