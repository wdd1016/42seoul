/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:09:09 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/13 20:09:04 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int	ft_isalnum(int c);
int	ft_isalpha(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *ptr, int value, size_t len);

#endif