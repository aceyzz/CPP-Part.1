/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvi <xvi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:45:51 by cedmulle          #+#    #+#             */
/*   Updated: 2024/02/13 12:11:25 by xvi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.hpp"

void	cleanInput(string& input)
{
	size_t start = input.find_first_not_of(" \t");
	if (start != string::npos)
		input.erase(0, start);
	
	size_t end = input.find_last_not_of(" \t");
	if (end != string::npos && end < input.length())
		input.erase(end + 1);
}

bool	is_digit(string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '0')
			return (false);
	}
	return (true);
}

bool	isEmptyLine(string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n' && input[i] != '\r' && input[i] != '\v' && input[i] != '\f')
			return (false);
	}
	return (true);
}

void	validateInput(const string& prompt, string& input, const string& errMsg)
{
	while (1 && !std::cin.eof())
	{
		std::cout << GRY << prompt << RST;
		std::getline(std::cin, input);
		cleanInput(input);
		if (input.length() > 0 && !isEmptyLine(input))
				break;
		else
			std::cout << D_YEL << errMsg << RST << std::endl;
	}
}

void	validateInputNbr(const string& prompt, string& input, const string& errMsg)
{
	while (1 && !std::cin.eof())
	{
		std::cout << GRY << prompt << RST;
		std::getline(std::cin, input);
		cleanInput(input);
		if (input.length() > 0 && is_digit(input))
			break;
		else
			std::cout << D_YEL << errMsg << RST << std::endl;
	}
}

void	shiftContact(PhoneBook *phonebook, int index)
{
	if (index > 7)
		index = 7;
	for (int i = index; i > 0; i--)
	{
		string	first = phonebook->getValue(i - 1, FIRST_NAME);
		string	last = phonebook->getValue(i - 1, LAST_NAME);
		string	nick = phonebook->getValue(i - 1, NICK_NAME);
		string	phone = phonebook->getValue(i - 1, PHONE_NBR);
		string	secret = phonebook->getValue(i - 1, SECRET);
		phonebook->createContact(i, first, last, nick, phone, secret);
	}
}

void addContact(PhoneBook* phonebook, int index)
{
	string	first;
	string	last;
	string	nick;
	string	phone;
	string	secret;

	validateInput("First Name: ", first, "Invalid First Name");
	validateInput("Last Name: ", last, "Invalid Last Name");
	validateInput("Nick Name: ", nick, "Invalid Nick Name");
	validateInputNbr("Phone Number: ", phone, "Invalid Phone Number");
	validateInput("Darkest Secret: ", secret, "Invalid Darkest Secret");
	if (index > 0)
		shiftContact(phonebook, index);
	phonebook->createContact(0, first, last, nick, phone, secret);
}

void printContacts(PhoneBook* phonebook, int index)
{
	Contact contact;
	string value;

	std::cout << GRY;
	for (int i = 0; i < 66; i++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout <<"| N° |  FIRST NAME  |   LAST NAME  |   NICK NAME  |   PHONE N°   |" << std::endl;
	for (int i = 0; i < 66; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		contact = phonebook->getContact(i);
		std::cout << "| " RST << i + 1 << GRY "  |";
		for (int j = 1; j < 5; j++)
		{
			value = phonebook->getValue(i, j);
			if (value.length() >= 12)
			{
				value.resize(12);
				value.replace(9, 3, "...");
			}
			std::cout << " " RST;
			std::cout.width(12);
			std::cout << std::left << value << GRY " |";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < 66; i++)
		std::cout << "-";
	std::cout << RST << std::endl << std::endl;
}

void searchContact(PhoneBook *phonebook)
{
	string input;
	bool found = false;

	while (1 && !std::cin.eof())
	{
		std::cout << GRY "Enter a keyword to search: " RST;
		std::getline(std::cin, input);
		cleanInput(input);
		if (input.empty())
		{
			std::cout << D_YEL "Enter a valid keyword to search" RST << std::endl;
			continue;
		}
		break;
	}
	std::cout << "Search results:" << std::endl;
	std::cout << GRY;
	for (int i = 0; i < 66; i++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << "| N° |  FIRST NAME  |   LAST NAME  |   NICK NAME  |   PHONE N°   |" << std::endl;
	for (int i = 0; i < 66; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		Contact contact = phonebook->getContact(i);
		bool contactFound = false;

		for (int j = 1; j < 5; j++)
		{
			string value = phonebook->getValue(i, j);
			if (value.find(input) != string::npos)
			{
				contactFound = true;
				break;
			}
		}
		if (contactFound)
		{
			found = true;
			std::cout << "| " RST << i + 1 << GRY "  |";
			for (int j = 1; j < 5; j++)
			{
				string value = phonebook->getValue(i, j);
				if (value.length() >= 12)
				{
					value.resize(12);
					value.replace(9, 3, "...");
				}
				std::cout << " " RST;
				std::cout.width(12);
				std::cout << std::left << value << GRY " |";
			}
			std::cout << std::endl;
		}
	}
	if (!found)
		std::cout << D_YEL " No contacts found matching the keyword (waring: case sensitive)" RST << std::endl;
	std::cout << GRY;
	for (int i = 0; i < 66; i++)
		std::cout << "-";
	std::cout << RST << std::endl << std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	string		input;
	int			index = 0;

	std::cout << "\033[2J\033[3J\033[H";
	while (!std::cin.eof())
	{
		std::cout << GRY "Type you command (ADD/SEARCH/PRINT/EXIT)..." RST << std::endl;
		std::getline(std::cin, input);
		cleanInput(input);
		if (input == "EXIT")
			break ;
		else if (input == "PRINT")
			printContacts(&phonebook, index);
		else if (input == "ADD")
			addContact(&phonebook, index++);
		else if (input == "SEARCH")
			searchContact(&phonebook);
		else if (!std::cin.eof())
			std::cout << D_YEL "Invalid Command (waring: case sensitive)" RST << std::endl;
	}
	std::cout << MAG "Bye bye ♥" RST << std::endl;
	return (0);
}
