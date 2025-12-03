/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:51:55 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/24 21:44:17 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp_lst;
	int		i;

	tmp_lst = lst;
	i = 0;
	while (tmp_lst)
	{
		tmp_lst = tmp_lst->next;
		i++;
	}
	return (i);
}
