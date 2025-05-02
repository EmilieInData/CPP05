/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/02 17:37:07 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential_42P", 25, 5), _target("Default")
{
	std::cout << PURPLE << ">> PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential_42P", 25, 5), _target(target)
{
	std::cout << PURPLE << ">> PresidentialPardonForm target constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other) : AForm(other)
{
	std::cout << PURPLE << ">> PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << PURPLE << ">> PresidentialPardonForm destructor called" << RESET << std::endl;
}

void	PresidentialPardonForm::formExecute() const

{
	std::cout << MEGA << " " << GREEN << _target << BLUE
			  << " has been pardoned by Zaphod Beeblebrox."
			  << RESET << std::endl;
	return;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
	if (this != &other)
		AForm::operator=(other);
	else
		std::cout << ERROR << PINK
				  << "pay attention, you're trying to assign an PresidentialPardonForm class to itself"
				  << RESET << std::endl;
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, PresidentialPardonForm const& b)
{
	std::string tmp;
	
	if (b.getSigned() == true)
		tmp = "signed";
	else
		tmp = "not signed";
	o << BLUE << b.getName() << " PresidentialPardonForm is " << GREEN << tmp << BLUE
	  << ", it can be signed by a Bureaucrat with grade " << GREEN
	  << b.getGradeSign() << BLUE <<  " and be executed with grade "
	  << GREEN << b.getGradeExecute() << RESET << std::endl;
	return (o);
}
