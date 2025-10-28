/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:37:50 by jquinde-          #+#    #+#             */
/*   Updated: 2025/10/27 12:06:34 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h> 
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

/***  General  ***/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *ntpr);


/***  Strings  ***/

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_strendswith(char *str, const char *suffix);
ssize_t	ft_strlenuntil(char *str, int ch);
int		ft_strcontains_ch(char *str, int ch);
ssize_t	ft_strindexof(char *str, int ch);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, char *src, size_t len);
void	ft_strappend(char **str, char *value);
void	ft_strclean(char **str);


/* Memory */

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_arrstrclean(char ***arr_str, size_t len);


/***  Lists  ***/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
///Same behaviour as ft_lstnew. In case of node allocation fail frees content
t_list	*ft_lstnew_s(void *content);
void    ft_lstreverse(t_list **lst);


/***   I/O   ***/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# define READ_SUCCESS 1
# define READ_EMPTY 0
# define READ_FAIL -1
# define READ_FAIL_MALLOC -2
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_raw_rreadtext(int fd, t_list **head);
/***
 * Reads all the file and copies it to the given buffer. Buffer doesn't need to be initilized.
 * Returns a status code.
 */
int		ft_readtext(int fd, char **buffer);
/***
 * Reads all the file and copies it to the given list in reverse. Each node is a line without '\n'. Head doesn't need to be initilized.
 * Returns a status code.
 */
int		ft_rreadlines(int fd, t_list **head);
/***
 * Reads all the file and copies it to the given list. Each node is a line without '\n'. Head doesn't need to be initilized.
 * Returns a status code.
 */
int		ft_readlines(int fd, t_list **head);


/*  Matrix  */

typedef struct s_matrx
{
	char	**data;
	size_t	width;
	size_t	height;
}			t_matrx;

t_matrx matrix_new(size_t height, size_t width);
void    matrix_print(t_matrx matrix);
void	matrix_clean(t_matrx *matrix);


/***  Queue  ***/

typedef struct s_queue
{
	t_list *head;
	t_list *tail;
}				t_queue;


t_queue queue_new (void);
int queue_empty (t_queue queue);
void queue_put (t_queue *queue, void *x);
void *queue_get (t_queue *stk);
void queue_free (t_queue *queue);

#endif
