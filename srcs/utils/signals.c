/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:46:24 by adiouane          #+#    #+#             */
/*   Updated: 2024/02/02 00:51:31 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handlear(int signal)
{
	(void)signal;
	if (g_data.signal_heredoc == 0)
	{
		g_data.exit_status = 1;
		if (g_data.breaker == 0)
			ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		g_data.breaker = 1;
		g_data.exit_status = 1;
		ft_putstr_fd("\n", 1);
		close(0);
	}
}

void	signal_init(void)
{
	signal(SIGINT, handlear);
	signal(SIGQUIT, SIG_IGN);
}
