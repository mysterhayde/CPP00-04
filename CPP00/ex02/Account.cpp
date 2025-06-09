/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:56:20 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/09 22:56:53 by hdougoud         ###   ########.fr       */
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

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	std::cout << getNbAccounts << std::endl;
	std::cout << getTotalAmount << std::endl;
	std::cout << getNbDeposits << std::endl;
	std::cout << getNbWithdrawals << std::endl;
}