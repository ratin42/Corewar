/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:16:47 by saouas            #+#    #+#             */
/*   Updated: 2019/07/25 02:04:59 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1

size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_itoa(int nb);
char			**ft_strsplit(char const *s, char c);
char			*ft_strtrim(char const *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strnew(size_t size);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strjoin_free(char const *s1, char const *s2, int string);
char			*ft_strdjoin(char *s1, char *s2);
char			*ft_strfreedup(char *s1);
char			*ft_litoa(long long int nb);
char			*ft_realloc(char *ptr, long long int newsize);
long long int	ft_atoi_base(char *str, char *base);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_isblank(int c);
int				ft_str_is_alpha(char *str);
int				ft_str_is_printable(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_uppercase(char *str);
int				get_next_line(const int fd, char **line);
int				ft_abs(int nbr);
int				get_nb(char c, char *base);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(int nb);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_memdel(void	**ap);
void			*ft_memalloc(size_t size);
void			ft_print_words_tables(char **tab);
void			ft_reverse_str(char *str, int len);
char			*ft_convert_base_finale(char *nbr, char *base_to);

#endif
