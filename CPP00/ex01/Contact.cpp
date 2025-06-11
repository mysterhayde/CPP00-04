/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:37:44 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/11 23:47:17 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "\x1b[32;1m" << "Constructor called" << "\033[0m" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "\x1b[31;1m" << "Destructor called" << "\033[0m" << std::endl;
	return;
}

void	Contact::add_contact(void)
{
	static int	contacts;

	std::cout << "Please entrer contact information" << std::endl;

	this->_configured = 1;
	std::cout << std::endl << "First name" << std::endl;
	this->_frist_name = _get_contact_info("First name");

	std::cout << std::endl << "Last name" << std::endl;
	this->_last_name = _get_contact_info("Last name");

	std::cout << std::endl << "Nickname" << std::endl;
	this->_nickname = _get_contact_info("Nickname");

	std::cout << std::endl << "Phone number" << std::endl;
	this->_phone_number = _get_contact_info("Phone number");

	std::cout << std::endl << "Darkest secret" << std::endl;
	this->_darkest_secret = _get_contact_info("Darkest secret");

	contacts++;
	std::cout << std::endl;
}

std::string Contact::_get_contact_info(std::string contact_info)
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

void	Contact::show_contact_info() const
{
	std::cout << std::endl;
	std::cout << this->_frist_name << std::endl;
	std::cout << this->_last_name << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << this->_phone_number << std::endl;
	std::cout << this->_darkest_secret << std::endl;
	std::cout << std::endl;
}

bool	Contact::show_preview_contact() const
{
	if (!this->_configured)
		return (false);

	//									USE IOMANIP FUNCTIONS
	std::cout << "Preview contact" << std::endl;
	return (true);
}

