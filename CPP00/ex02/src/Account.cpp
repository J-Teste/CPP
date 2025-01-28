/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:30:46 by hakgyver          #+#    #+#             */
/*   Updated: 2025/01/28 14:24:05 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Account.hpp"
#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
			  << ";amount:" << this->_amount 
			  << ";created" 
			  << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "] ";
}

Account::Account(void)
{
	return;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed"
			  << std::endl;
}


int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() 
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits() 
			  << ";withdrawals:" << Account::getNbWithdrawals()
			  << std::endl;
}


void Account::makeDeposit(int deposit)
{
	int p_amout = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
			  << ";p_amount:" << p_amout 
			  << ";deposit:" << deposit 
			  << ";amount:" << this->_amount 
			  << ";nb_deposits:" << this->_nbDeposits 
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amout = this->_amount;
	this->_amount -= withdrawal;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
			  << ";p_amount:" << p_amout;
	if (this->checkAmount() == 1)
	{
		this->_amount = p_amout;
		std::cout << ";withdrawal:refused" << std::endl;
		return(false);
	}
	else
	{
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal
				  << ";amount:" << this->_amount
				  << ";nb_withdrawals:" << this->_nbWithdrawals
				  << std::endl;
		return(true);
	}
}

int Account::checkAmount(void) const
{
	if (this->_amount < 0)
		return (1);
	return (0);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:"
			  << this->_accountIndex
			  << ";amount:"
			  << this->_amount
			  << ";deposits:" 
			  << this->_nbDeposits 
			  << ";withdrawals:" 
			  << this->_nbWithdrawals 
			  << std::endl;
}
