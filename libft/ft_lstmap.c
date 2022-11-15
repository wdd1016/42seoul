/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:02:07 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/16 07:51:36 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*new_const;

	if (!lst)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	new_const = new;
	while (lst->next)
	{
		del(lst->content);
		temp = lst->next;
		free(lst);
		lst = temp;
		temp = ft_lstnew(f(lst->content));
		if (!temp)
			return (0);
		new->next = temp;
		new = temp;
	}
	return (new_const);
}
/*
int main(void)
{
	t_list *l = lstnew(strdup(" 1 2 3 "));
 	t_list *ret;

}
*/