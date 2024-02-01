/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:34:41 by omanar            #+#    #+#             */
/*   Updated: 2024/02/02 00:24:08 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_data	g_data;

int	main(int ac, char **av, char **env)
{
	char	*line;

	(void)av;
	if (ac != 1)
		return (0);
	initialization(env);
	while (42)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		if (line[0] != '\0')
			add_history(line);
		if (parsing(line))
		{
			free(line);
			clean();
			continue ;
		}
		execution();
		free(line);
	}
	cleaning();
	return (0);
}
