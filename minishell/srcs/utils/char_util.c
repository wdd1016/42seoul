#include "minishell.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || \
	c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || \
	(c >= 'a' && c <= 'z'));
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
