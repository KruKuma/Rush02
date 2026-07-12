/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_group.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:20:00 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/12 02:20:00 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_digit(t_dict *tab, char c, int *is_first);
int	print_two(t_dict *tab, char a, char b, int *is_first);
int	print_key(t_dict *tab, char *key, int *is_first);

int ft_group_is_zero(char *group)
{
    return (group[0] == '0' && group[1] == '0' && group[2] == '0');
}

void ft_fill_group(char *group, char *nb, int group_len)
{
    group[0] = '0';
    group[1] = '0';
    group[2] = '0';
    if (group_len == 1)
        group[2] = nb[0];
    else if (group_len == 2)
    {
        group[1] = nb[0];
        group[2] = nb[1];
    }
    else if (group_len == 3)
    {
        group[0] = nb[0];
        group[1] = nb[1];
        group[2] = nb[2];
    }
}

int ft_print_hundreds(t_dict *tab, char group[4], int *is_first)
{
    if (group[0] != '0')
        return (1);
    if (group[1] != '0')
    {
        if (!ft_print_two(tab, group[1], '0', is_first))
            return (0);
    }
    if (group[2] != '0')
    {
        if (!ft_print_two(tab, group[2], '0', is_first))
            return (0);
    }
    return (1);
}

int ft_print_group(t_dict *tab, char *group, int *is_first)
{
    if (!ft_print_hundreds(tab, group, is_first))
        return (0);
    if (!ft_print_tens(tab, group[1], group[2], is_first))
        return (0);
    return (1);
}