#include <minirt.h>

struct s_aux
{
	int		sign;
	int		has_frac;
	int		frac_pow;
};

static void	start_aux(struct s_aux *aux)
{
	aux->has_frac = 0;
	aux->frac_pow = 1;
}

static int	has_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	return (sign);
}

float	ft_atof(const char *str)
{
	float			result;
	struct s_aux	aux;

	result = 0.0;
	start_aux(&aux);
	aux.sign = has_sign((char **)&str);
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		aux.has_frac = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		aux.frac_pow *= 10;
		str++;
	}
	result = aux.sign * result / aux.frac_pow;
	return (result);
}

