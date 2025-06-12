/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:35:14 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/12 14:23:56 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _contact_idx(0)
{
	std::cout << "\x1b[32;1m" << "Constructor called" << "\033[0m" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "\x1b[31;1m" << "Destructor called" << "\033[0m" << std::endl;
	return;
}

void	PhoneBook::add_contact_list()
{
	if (_contact_idx == 8)
	{
		for(int i = 0; i < 7; i++)
			std::swap(_contacts[i], _contacts[i + 1]);
		_contact_idx = 7;
	}
	
	_contacts[_contact_idx].add_contact();
	_contact_idx++;
}

void	PhoneBook::search_contact() const
{
	int	selection;
	std::string	entry;

	for (int i = 0; _contacts[i].show_preview_contact(i) && i < 7; i++)
		;

	std::cout << std::endl;
	std::cout << "Select the contact you want to visualize" << std::endl;
	std::getline(std::cin, entry);
	try
	{
		selection = (std::stoi(entry) - 1);
		if (selection < 0 || selection > 7 || selection >= _contact_idx)
		{
			std::cout << "Invalid input" << std::endl;
			return;
		}
	}
	catch(std::logic_error)
	{
		std::cout << "Invalid argument " << entry << " is invalid entry" << std::endl;
		return;
	}
	
	_contacts[selection].show_contact_info();
}
