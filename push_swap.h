/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:04:44 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/05 17:39:18 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd, int *ret);
void	ft_putnbr_fd(long n, int fd, int *ret, char sign);
void	ft_putchar_fd(char c, int fd, int *ret);
char	ft_atoi(char **nptr, int *res);
int		ft_printf(const char *format, ...);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(const t_list *lst);
char	parse(char **argv, t_list **a);
void	sort(t_list *a);

#endif
