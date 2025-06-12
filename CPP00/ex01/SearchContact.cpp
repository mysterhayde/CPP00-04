/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SearchContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:03:05 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:12 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"


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
