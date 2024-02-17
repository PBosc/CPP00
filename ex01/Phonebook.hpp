#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <cstdlib>

class Phonebook {
	private:
		Contact contacts[8];
		int contact_count;
		int	oldest_contact;
	public:
		Phonebook(void);
		void add_contact(void);
		void search_contact(void);
	private:
		std::string	trunc(const std::string& str, size_t width);
};

bool	safe_getline(std::string *str);

#endif