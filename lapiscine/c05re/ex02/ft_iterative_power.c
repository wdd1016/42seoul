/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:58:51 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/11 22:08:37 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	exp;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	exp = 1;
	while (power > 0)
	{
		exp *= nb;
		power--;
	}
	return (exp);
}
