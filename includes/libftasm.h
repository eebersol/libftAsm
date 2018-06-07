/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftasm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:44:53 by eebersol          #+#    #+#             */
/*   Updated: 2018/05/24 15:49:20 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_H
# define LIBFTASM_H
# include <string.h>
/*
** PART1 :
*/
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *dest, const char *src);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *s);
/*
** PART2 :
*/
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void 	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
/*
** PART3 :
*/
void	*ft_cat(int fd);
/*
** BONUS :
*/
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_puts_fd(char *str, int fd);
char	ft_str_search(char *str, char find);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isspace(int c);

#endif