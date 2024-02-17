#include <iostream>
#include "Phonebook.hpp"

bool	safe_getline(std::string *str)
{
	if (!std::getline(std::cin, *str))
	{
		if (std::cin.eof())
		{
			std::cout << "EOF. End of program." << std::endl;
			return (false);
		}
		else
		{
			std::cout << "Input error occurred. End of program" << std::endl;
			return (false);
		}
	}
	return (true);
}

int main(void)
{
	Phonebook phonebook = Phonebook();
	std::string command;
	while (1)
	{
		std::string command;
		std::cout << "Enter a command: ADD, SEARCH, or EXIT:" << std::endl;
		if (!safe_getline(&command))
			break;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
