/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:37:44 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/13 01:17:31 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(void) : _configured(0)
{
	std::cout << "\x1b[32;1m" << "Constructor called" << "\033[0m" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "\x1b[31;1m" << "Destructor called" << "\033[0m" << std::endl;
	return;
}

bool	Contact::add_contact(void)
{
	static int	contacts;

	std::cout << "Please entrer contact information" << std::endl;

	this->_configured = 1;
	std::cout << std::endl << "First name" << std::endl;
	this->_first_name = _get_contact_info("First name");
	if (std::cin.eof()) return false;

	std::cout << std::endl << "Last name" << std::endl;
	this->_last_name = _get_contact_info("Last name");
	if (std::cin.eof()) return false;

	std::cout << std::endl << "Nickname" << std::endl;
	this->_nickname = _get_contact_info("Nickname");
	if (std::cin.eof()) return false;

	std::cout << std::endl << "Phone number" << std::endl;
	this->_phone_number = _get_contact_info("Phone number");
	if (std::cin.eof()) return false;

	std::cout << std::endl << "Darkest secret" << std::endl;
	this->_darkest_secret = _get_contact_info("Darkest secret");
	if (std::cin.eof()) return false;

	contacts++;
	std::cout << std::endl;
	return (true);
}


void	Contact::show_contact_info(int color) const
{
	std::cout << _get_color(color) << std::endl;
	std::cout << this->_first_name << std::endl;
	std::cout << this->_last_name << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << this->_phone_number << std::endl;
	std::cout << this->_darkest_secret << std::endl;
	std::cout << "\033[0m" << std::endl;
}

bool	Contact::show_preview_contact(int i) const
{

	if (!this->_configured)
		return(false);

		std::string	color = _get_color(i);
		std::string reset = "\x1b[0m";

	std::cout << color << i + 1 << std::setfill(' ') << std::setw(13);
	std::cout << reset << '|' << color;
	_print_preview_layout(this->_first_name);
	std::cout << reset << '|' << color;
	_print_preview_layout(this->_last_name);
	std::cout << reset << '|' << color;
	_print_preview_layout(this->_nickname);
	std::cout << reset << std::endl;
	return (true);
}

std::string Contact::_get_color(int i) const
{
	switch(i)
	{
		case 0: return("\x1b[38;2;0;0;255m");
		case 1: return("\x1b[38;2;21;0;249m");
		case 2: return("\x1b[38;2;42;0;242m");
		case 3: return("\x1b[38;2;63;0;236m");
		case 4: return("\x1b[38;2;85;0;230m");
		case 5: return("\x1b[38;2;106;0;224m");
		case 6: return("\x1b[38;2;127;0;217m");
		case 7: return("\x1b[38;2;148;0;211m");
	}
	return ("\x1b[0m");
}

void	Contact::_print_preview_layout(std::string str) const
{
	int	lenght;

	lenght = str.length();
	if (lenght < 10)
		std::cout << str << std::setfill(' ') << std::setw(10 - lenght) << ' ';
	else if (lenght == 10)
		std::cout << str;
	else
	{
		str.resize(9);
		str.push_back('.');
		std::cout << str;
	}
}

std::string Contact::_get_contact_info(std::string contact_info)
{
	std::string entry;

	std::getline(std::cin, entry);
	if (std::cin.eof())
		return ("null");
	while(entry.empty())
	{
		std::cout << "\x1b[38;5;208m""The entry can't be empty""\033[0m" << std::endl;
		std::cout << std::endl << contact_info << std::endl;
		std::getline(std::cin, entry);
	}
	return (entry);
}