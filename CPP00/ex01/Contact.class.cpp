/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:37:44 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/05 13:10:38 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
