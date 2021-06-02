/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:12:42 by daoren            #+#    #+#             */
/*   Updated: 2021/06/02 18:15:15 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int		is_in_str(char *str, char c)
{
	int i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int		ft_stringify(t_printf_data *pf_var)
{
	if (pf_var->current_char == 's')
		return (convert_s(pf_var));
	else if (pf_var->current_char == 'c')
		return (convert_c(pf_var));
	else if (pf_var->current_char == 'd')
		return (convert_di(pf_var));
	else if (pf_var->current_char == 'p')
		return (convert_p(pf_var));
	else if (pf_var->current_char == 'i')
		return (convert_di(pf_var));
	else if (pf_var->current_char == 'u')
		return (convert_u(pf_var));
	else if (pf_var->current_char == 'x')
		return (convert_x(pf_var));
	else if (pf_var->current_char == 'X')
		return (convert_upperx(pf_var));
	else if (pf_var->current_char == '%')
		return (convert_percent(pf_var));
	return (1);
}