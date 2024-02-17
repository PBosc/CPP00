#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->contact_count = 0;
}

void Phonebook::add_contact(void)
{
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phone_number = "";
	std::string darkest_secret = "";
	std::cout << "Enter the first name: ";
	if (!safe_getline(&first_name))
		std::exit(1);
	std::cout << "Enter the last name: ";
	if (!safe_getline(&last_name))
		std::exit(1);
	std::cout << "Enter the nickname: ";
	if (!safe_getline(&nickname))
		std::exit(1);
	std::cout << "Enter the phone number: ";
	if (!safe_getline(&phone_number))
		std::exit(1);
	std::cout << "Enter the darkest secret: ";
	if (!safe_getline(&darkest_secret))
		std::exit(1);
	if (this->contact_count < 8)
	{
		this->contacts[this->contact_count] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
		this->oldest_contact = this->contact_count;
		this->contact_count++;
	}
	else
	{
		this->contacts[this->oldest_contact] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
		this->oldest_contact = (this->oldest_contact + 1) % 8;
	}
}

std::string	Phonebook::trunc(const std::string& str, size_t width)
{
	std::string truncated_str = str;

	if (truncated_str.length() > width)
	{
		truncated_str = truncated_str.substr(0, width - 1) + '.';
	}
    return (truncated_str);
}

void	Phonebook::search_contact(void)
{
	int i;
	std::string index;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (i = 0; i < this->contact_count; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << trunc((this->contacts[i].get_first_name()), 10) << "|";
		std::cout << std::setw(10) << trunc((this->contacts[i].get_last_name()), 10) << "|";
		std::cout << std::setw(10) << trunc((this->contacts[i].get_nickname()), 10) << std::endl;
	}
	std::cout << "Enter the index of the contact you want to see: ";
	if (!safe_getline(&index))
		std::exit(1);
	if (index.length() == 1 && index[0] >= '0' && index[0] <= this->contact_count - 1 + '0')
	{
		i = index[0] - '0';
		std::cout << "First name: " << this->contacts[i].get_first_name() << std::endl;
		std::cout << "Last name: " << this->contacts[i].get_last_name() << std::endl;
		std::cout << "Nickname: " << this->contacts[i].get_nickname() << std::endl;
		std::cout << "Phone number: " << this->contacts[i].get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << this->contacts[i].get_darkest_secret() << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
}