/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:02:07 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/19 21:23:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_clear_zero(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	void	*temp_c;

	if (!lst)
		return (0);
	new = 0;
	while (lst)
	{
		temp_c = f(lst->content);
		if (!temp_c)
			return (ft_clear_zero(&new, del));
		temp = ft_lstnew(temp_c);
		if (!temp)
		{
			del(temp_c);
			return (ft_clear_zero(&new, del));
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int main(void)
{
ft_lstmap(<list: {node: "one"}->{node: "two"}->{node:
"three"}->{node: "four"}->{node: "five"}->(null)>, [s => strlen(s)], [x =>
free(x)]);
}
*/