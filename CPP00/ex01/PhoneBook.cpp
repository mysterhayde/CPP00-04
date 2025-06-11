/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:35:14 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/11 16:55:08 by hdougoud         ###   ########.fr       */
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
	std::cout << "current index :" << _contact_idx << std::endl;
	_contacts[_contact_idx].add_contact();
	_contact_idx++;
}