/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:04:44 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/12 16:57:42 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_strlen(const char *s);
char	ft_atoi(char **nptr, int *res);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(const t_list *lst);
char	parse(char **argv, t_list **a);
void	sort(t_list **a);
void	push(t_list **from, t_list **to, const char is_b, char **res);
void	reverse_rotate(t_list **lst, char **res);
void	rotate(t_list **lst, const char is_b, char **res);
void	fill_b(t_list **a, t_list **b, char **res);
void	refill_a(t_list **a, t_list **b, char **res);
void	stradd(char **base, char *add);

#endif
