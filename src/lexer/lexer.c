/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:47:46 by susui             #+#    #+#             */
/*   Updated: 2022/11/29 17:13:59 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	save_args(t_shell *shell, t_command *commands, char *input)
{
	size_t	i;
	size_t	j;
	char	*start;

	i = 0;
	j = 0;
	start = input;
	while (input[i])
	{
		if ((input[i] == ' ' && input[i - 1] != ' ')
			|| (input[i] != '\"' && input[i] != '\'' && input[i + 1] == '$')
			|| input[i + 1] == '\0')
			commands->argv[j++] = extract_arg(shell, input, &start, &i);
		else if (input[i] == '\"' || input[i] == '\'')
		{
			commands->argv[j++] = store_quoted_arg(shell, input, &i, input[i]);
			start = input + ++i;
		}
		if (ft_strchr("<>", input[i++]))
			break ;
	}
	commands->argv[j] = NULL;
}

void	ft_format(t_shell *shell, t_command *commands, char *argv)
{
	size_t	arg_cnt;
	char	*input_trimmed;

	input_trimmed = ft_strtrim(argv, " ");
	if (input_trimmed == NULL)
		exit_session(shell, 1, "Memory error\nexit");
	arg_cnt = count_args(input_trimmed);
	commands->argv = ft_calloc(arg_cnt, sizeof(char *));
	if (commands->argv == NULL)
		exit_session(shell, 1, "Memory error\nexit");
	save_args(shell, commands, input_trimmed);
	free(input_trimmed);
}

int	lexer(t_shell *shell)
{
	char	**argv;
	size_t	i;

	i = 0;
	shell->cmd = ft_calloc(1, sizeof(t_cmd));
	if (shell->cmd == NULL)
		exit_session(shell, 1, "error");
	shell->cmd->cmd_cnt = count_cmds(shell->input);
	argv = split_by_pipe(shell, shell->input, shell->cmd->cmd_cnt);
	shell->cmd->commands = ft_calloc(shell->cmd->cmd_cnt, sizeof(t_command));
	if (shell->cmd->commands == NULL)
		exit_session(shell, 1, "error");
	while (argv[i])
	{
		ft_format(shell, &shell->cmd->commands[i], argv[i]);
		free(argv[i]);
		i++;
	}
	free(argv);
	return (0);
}
