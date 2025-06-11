/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SearchContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:03:05 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/11 16:43:00 by hdougoud         ###   ########.fr       */
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

void	search_contact(PhoneBook *PhoneBookInstance)
{
	for (int i = 0; PhoneBookInstance->_contacts[i]._configured && i <= 7; i++)
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