/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:45:51 by cedmulle          #+#    #+#             */
/*   Updated: 2024/02/11 15:33:15 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tools.hpp"

void cleanInput(string& input)
{
	size_t start = input.find_first_not_of(" \t");
	if (start != string::npos)
		input.erase(0, start);
	
	size_t end = input.find_last_not_of(" \t");
	if (end != string::npos && end < input.length())
		input.erase(end + 1);
}

int	main(void)
{
	PhoneBook	phonebook;
	string		input;
	int			index;

	while (!std::cin.eof())
	{
		std::cout << GRY "Type you command (ADD/SEARCH/EXIT)\n> " RST;
		std::getline(std::cin, input);
		cleanInput(input);
		if (input == "EXIT")
			break ;
		// else if (input == "ADD")
		// 	addContact(&phonebook, index);//TODO
		// else if (input == "SEARCH")
		// 	searchContact(&phonebook, index);//TODO
		else
			std::cout << D_YEL "Invalid Command (waring: case sensitive)\n" RST;
	}
	std::cout << MAG "Bye bye ♥" RST << std::endl;
	return (0);
}
