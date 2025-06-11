/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:51:56 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/11 13:03:38 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void	search_contact(PhoneBook *PhoneBookInstance);

static std::string get_contact_info(std::string contact_info)
{
	std::string entry;

	std::getline(std::cin, entry);
	while(entry.empty())
	{
		std::cout << "\x1b[38;5;208m""The entry can't be empty""\033[0m" << std::endl;
		std::cout << std::endl << contact_info << std::endl;
		std::getline(std::cin, entry);
	}
	return (entry);
}

static void	add_contact(PhoneBook *PhoneBookInstance)
{
	static int	contacts;

	std::cout << "Please entrer contact information" << std::endl;

	if (contacts >= 8)
	{
		for(int i = 0; i < 7; i++)
			std::swap(PhoneBookInstance->contact[i], PhoneBookInstance->contact[i + 1]);
		contacts = 7;
	}

	PhoneBookInstance->contact[contacts].conigured = 1;
	std::cout << std::endl << "First name" << std::endl;
	PhoneBookInstance->contact[contacts].frist_name = get_contact_info("First name");

	std::cout << std::endl << "Last name" << std::endl;
	PhoneBookInstance->contact[contacts].last_name = get_contact_info("Last name");

	std::cout << std::endl << "Nickname" << std::endl;
	PhoneBookInstance->contact[contacts].nickname = get_contact_info("Nickname");

	std::cout << std::endl << "Phone number" << std::endl;
	PhoneBookInstance->contact[contacts].phone_number = get_contact_info("Phone number");

	std::cout << std::endl << "Darkest secret" << std::endl;
	PhoneBookInstance->contact[contacts].darkest_secret = get_contact_info("Darkest secret");

	contacts++;
	std::cout << std::endl;
}

int main(void)
{
	std::string entry;
	PhoneBook	PhoneBookInstance;

	while(1)
	{
		std::getline(std::cin, entry);
		if (entry == "ADD")
		{
			std::cout << std::endl;
			add_contact(&PhoneBookInstance);
		}
		if (entry == "SEARCH")
		{
			std::cout << std::endl;
			search_contact(&PhoneBookInstance);
		}
		if (entry == "EXIT")
			break;
	}

	return (0);
}
