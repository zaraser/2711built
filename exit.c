/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:23:06 by zserobia          #+#    #+#             */
/*   Updated: 2024/11/23 14:23:08 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_all_digits(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')  // Проверяем знак числа.
		i++;
	if (!str[i])  // Если после знака число отсутствует.
		return (0);
	while (str[i])  // Проверяем каждый символ.
	{
		if (!isdigit(str[i]))  // Если символ не цифра.
			return (0);
		i++;
	}
	return (1);  // Строка состоит только из цифр.
}

int	mini_exit(t_simple_cmds *simple_cmd, t_shell *shell)
{
	int	exit_code;

	exit_code = 0;  // Инициализация exit_code.
	if (!simple_cmd->str[1])  // Если аргумент отсутствует.
	{
		printf("exit\n");
	}
	if (simple_cmd->str[2])  // Если аргументов больше одного.
	{
		printf("exit\nbash: exit: too many arguments\n");
		return (1);  // Возвращаем код ошибки 1, программа продолжает работу.
	}
	if (!is_all_digits(simple_cmd->str[1]))  // Если аргумент не является числом.
	{
		printf("exit\nbash: exit: %s: numeric argument required\n", simple_cmd->str[1]);
		exit_code = 2;
	}
	// Конвертируем строку в число и приводим к диапазону 0-255.
	exit_code = ft_atoi(simple_cmd->str[1]) % 256;
	if (exit_code < 0)
		exit_code = 256 + exit_code;
	ft_free_tous(&shell);  // Освобождаем ресурсы.
	exit(exit_code);  // Выход с рассчитанным кодом.
}




/*if (strcmp(simple_cmd->str[0], "exit") == 0) {
    return mini_exit(simple_cmd, shell);  // Завершаем программу, вызываем exit
}
*/
