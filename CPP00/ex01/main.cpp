/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:51:56 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/11 16:47:42 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	int			i;
	std::string	entry;
	PhoneBook	PhoneBookInstance;

	i = 0;
	while(1)
	{
		std::cout << "Menu selection : you can, ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, entry);
		if (entry == "ADD")
		{
			std::cout << std::endl;
			PhoneBookInstance.add_contact_list();
		}
		if (entry == "SEARCH")
		{
			std::cout << std::endl;
			//search_contact(&PhoneBookInstance);
		}
		if (entry == "EXIT")
			break;
	}

	return (0);
}
