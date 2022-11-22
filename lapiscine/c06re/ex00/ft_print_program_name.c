/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:42:35 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/12 15:57:30 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc > 0)
	{
		while (*argv[0])
		{
			write(1, argv[0], 1);
			(argv[0])++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
