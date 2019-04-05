/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bw_count_bits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:11:58 by apion             #+#    #+#             */
/*   Updated: 2019/04/05 12:14:00 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_bw_count_bits(unsigned int value)
{
	unsigned int	count;

	count = 0;
	while (value)
	{
		value &= value - 1;
		count++;
	}
	return (count);
}
