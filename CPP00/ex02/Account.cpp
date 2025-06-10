/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:56:20 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/09 23:48:41 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "\x1b[32;1m" << "Constructor called" << "\033[0m" << std::endl;
	return;
}

Account::~Account()
{
	std::cout << "\x1b[31;1m" << "Destructor called" << "\033[0m" << std::endl;
	return;
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		return (true);
	}
	return (false);
}

int	Account::checkAmount(void) const
{
	return Account::_amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "ammount" << this->_amount << ";";
	std::cout << "deposit:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	std::cout << getNbAccounts << std::endl;
	std::cout << getTotalAmount << std::endl;
	std::cout << getNbDeposits << std::endl;
	std::cout << getNbWithdrawals << std::endl;
}