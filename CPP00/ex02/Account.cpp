/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:56:20 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/09 19:18:16 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

Account::Account(int initial_deposit)
{
	std::cout << "\x1b[32;1m" << "Constructor called" << "\033[0m" << std::endl;
	return;
}

Account::~Account()
{
	std::cout << "\x1b[31;1m" << "Destructor called" << "\033[0m" << std::endl;
	return;
}

int	getNbAccounts(void)
{
	
}

int	getTotalAmount(void)
{
	
}

int	getNbDeposits(void)
{
	
}

int	getNbWithdrawals(void)
{
	
}

void	displayAccountsInfos(void)
{
	
}