/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/05 14:10:36 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << PURPLE << ">> Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(Intern const& other)
{
	(void) other;
	std::cout << PURPLE << ">> Intern copy constructor called" << RESET << std::endl;
}

Intern::~Intern()
{
	std::cout << PURPLE << ">> Intern destructor called" << RESET << std::endl;
}

Intern& Intern::operator=(Intern const& other)
{
	if (this == &other)
		std::cout << ERROR << PINK
				  << "pay attention, you're trying to assign an Intern class to itself"
				  << RESET << std::endl;
	return (*this);
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	int	i = 0;
	std::string array[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};
	for (size_t j = 0; j < formName.length(); j++)
		formName[j] = std::tolower(formName[j]);
	for (; i < 3; i++)
	{
		if (formName == array[i])
			break;
	}
	AForm* form = NULL;
	switch(i)
	{
		case 0:
			form = new ShrubberyCreationForm(formTarget);
			break;
		case 1:
			form = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			form = new PresidentialPardonForm(formTarget);
			break;
		default:
			std::cout << MEGA << PINK << " The form \"" << formTarget <<"\" doesn't exist"
					  << RESET << std::endl;
	}
	return form;
}
