/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:20:48 by cedmulle          #+#    #+#             */
/*   Updated: 2024/02/11 15:13:46 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.hpp"

PhoneBook::PhoneBook()
{
	// std::cout << "Constructor: PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "Destructor: PhoneBook" << std::endl;
}

Contact	PhoneBook::getContact(int index)
{
	return (book[index]);
}

string	PhoneBook::getValue(int index, int value)
{
	if (value == FIRST_NAME || value == LAST_NAME || value == NICK_NAME
		|| value == PHONE_NBR || value == SECRET)
		return (book[index].getValue(value));
	std::cout << YEL "Error: book[index].getValue (cpp)" RST << std::endl;
	return (NULL);
}

void	PhoneBook::createContact(int index, string firstName, string lastName,
								string nickName, string phoneNumber, string secret)
{
	book[index].setValue(FIRST_NAME, firstName);
	book[index].setValue(LAST_NAME, lastName);
	book[index].setValue(NICK_NAME, nickName);
	book[index].setValue(PHONE_NBR, phoneNumber);
	book[index].setValue(SECRET, secret);
}
