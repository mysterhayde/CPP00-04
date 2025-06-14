/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:05:26 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/13 01:16:28 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();
		bool	add_contact(void);
		void	show_contact_info(int color) const;
		bool	show_preview_contact(int i) const;
	private:
		int			_configured = 0;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		std::string _get_color(int i) const;
		std::string	_get_contact_info(std::string contact_info);
		void		_print_preview_layout(std::string str) const;
};

#endif