/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:51:56 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/06 00:08:11 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static int convert_entry(PhoneBook *PhoneBookInstance)
{
	int	selection;
	std::string	entry;

	std::cout << "Select the contact you want to visualize" << std::endl;
	std::getline(std::cin, entry);
	try
	{
		selection = (std::stoi(entry) - 1);
		if (selection < 0 || selection > 7 || !PhoneBookInstance->contact[selection].conigured)
		{
			std::cout << "Invalid input" << std::endl;
			return (-1);
		}
	}
	catch(std::logic_error)
	{
		std::cout << "Invalid argument " << entry << " is invalid entry" << std::endl;
		return (-1);
	}
	return (selection);
}

static std::string	print_preview(std::string str)
{
	int			size;

	size = str.length();
	if (size > 10)
	{
		str.resize(9);
		str.push_back('.');
	}
	else
		str.resize(10, ' ');
	return (str);
}

static void	search_contact(PhoneBook *PhoneBookInstance)
{
	for (int i = 0; PhoneBookInstance->contact[i].conigured; i++)
	{
		std::cout << i + 1 << "         " << '|'
		<< print_preview(PhoneBookInstance->contact[i].frist_name) << '|'
		<< print_preview(PhoneBookInstance->contact[i].last_name) << '|'
		<< print_preview(PhoneBookInstance->contact[i].nickname) << std::endl;
	}

	int selection = convert_entry(PhoneBookInstance);
	if (selection == -1)
		return ;
	
	std::cout << std::endl;
	std::cout << PhoneBookInstance->contact[selection].frist_name << std::endl
		<< PhoneBookInstance->contact[selection].last_name << std::endl
		<< PhoneBookInstance->contact[selection].nickname << std::endl
		<< PhoneBookInstance->contact[selection].phone_number << std::endl
		<< PhoneBookInstance->contact[selection].darkest_secret << std::endl << std::endl;
}

static void	add_contact(PhoneBook *PhoneBookInstance)
{
	std::string	entry;
	static int	contacts;

	std::cout << "Please entrer contact information" << std::endl;

	if (contacts >= 8)
	{
		for(int i = 8; i < 1; i--)
			std::swap(PhoneBookInstance->contact[i], PhoneBookInstance->contact[i - 1]);
		contacts = 8;
	}

	PhoneBookInstance->contact[contacts].conigured = 1;
	std::cout << std::endl << "First name" << std::endl;
	std::getline(std::cin, entry);
	PhoneBookInstance->contact[contacts].frist_name = entry;

	std::cout << std::endl << "Last name" << std::endl;
	std::getline(std::cin, entry);
	PhoneBookInstance->contact[contacts].last_name = entry;

	std::cout << std::endl << "Nickname" << std::endl;
	std::getline(std::cin, entry);
	PhoneBookInstance->contact[contacts].nickname = entry;

	std::cout << std::endl << "Phone number" << std::endl;
	std::getline(std::cin, entry);
	PhoneBookInstance->contact[contacts].phone_number = entry;

	std::cout << std::endl << "Darkest secret" << std::endl;
	std::getline(std::cin, entry);
	PhoneBookInstance->contact[contacts].darkest_secret = entry;

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
