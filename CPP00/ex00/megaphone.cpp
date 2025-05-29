/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:38:00 by hdougoud          #+#    #+#             */
/*   Updated: 2025/05/29 16:28:52 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	capitalize(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i + 1]; i++)
	{
		capitalize(argv[i]);
		std::cout << argv[i] << " ";
	}
	capitalize(argv[argc - 1]);
	std::cout << argv[argc - 1] << std::endl;
}