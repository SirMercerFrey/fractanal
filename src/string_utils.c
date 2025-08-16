#include "fractol.h"

int	ft_strlen(char *str)
{
	char	*end;

	end = str;
	while (*end)
		++end;
	return (end - str);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1)
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

int	is_valid_double(char *s)
{
	int		has_dot;

	has_dot = 0;
	if (NULL == s || !*s)
		return (0);
	if (*s == '-' || *s == '+')
		++s;
	if ((*s < '0' || *s > '9') && *s != '.')
		return (0);
	while (*s)
	{
		if (*s == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (*s < '0' && *s > '9')
			return (0);
	++s;
	}
	return (1);
}

double	atodbl(char *s)
{
	double	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign *= -1;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
