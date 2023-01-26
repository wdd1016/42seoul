/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_play_command_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:05:31 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/26 19:59:33 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_play_command(t_stacks *stk)
{
	char	*str;
	size_t	len;
	int		count;

	count = 0;
	while (1)
	{
		str = get_next_line(1);
		if (str == NULL)
			break ;
		len = ft_strlen(str);
		if (len == 3)
			ft_run_2command(stk, str);
		else if (len == 4)
			ft_run_3command(stk, str);
		else
			ft_error_command_str(stk, str);
		count++;
	}
	if (str == NULL && count == 0)
		ft_error_ps(stk);
}

void	ft_run_2command(t_stacks *stk, char *str)
{
	if (str[2] != '\n')
		ft_error_command_str(stk, str);
	if (str[0] == 's')
	{
		if (str[1] == 'a')
			swaporder(stk, stk->a);
		else if (str[1] == 'b')
			swaporder(stk, stk->b);
		else if (str[1] == 's')
			doubleorder(stk, SS);
		else
			ft_error_command_str(stk, str);	
	}
	else if (str[0] == 'p')
	{
		if (str[1] == 'a')
			pushorder(stk, stk->b, stk->a);
	}
}

void	ft_run_3command(t_stacks *stk, char *str)
{

}

void	ft_error_command_str(t_stacks *stk, char *str)
{
	free(str);
	ft_error_ps(stk);
}