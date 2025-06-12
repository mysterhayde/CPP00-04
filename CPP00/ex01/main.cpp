/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:51:56 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/13 01:23:18 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	int			i;
	std::string	entry;
	PhoneBook	PhoneBookInstance;
	
	i = 0;
	std::cout << std::endl;
	while(1)
	{
		std::cout << "Menu selection : you can ";
		std::cout << "\x1b[32m" << "ADD" << "\033[0m" << ", ",
		std::cout << "\x1b[34m" << "SEARCH" << "\033[0m" << " or ";
		std::cout << "\x1b[38;5;208m" << "EXIT" << "\033[0m" << std::endl;
		std::getline(std::cin, entry);
		
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "\x1b[38;5;208m" << "EOF detected exiting programm" << "\033[0m" << std::endl;
			std::cout << std::endl;
			break;
		}
		if (entry == "ADD")
		{
			std::cout << std::endl;
			PhoneBookInstance.add_contact_list();
		}
		if (entry == "SEARCH")
		{
			std::cout << std::endl;
			PhoneBookInstance.search_contact();
		}
		if (entry == "EXIT")
		{
			std::cout << std::endl << "\x1b[38;5;208m";
			std::cout << "Exit program" << std::endl << std::endl;
			break;
		}
	}

	return (0);
}
