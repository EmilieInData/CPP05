/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/04/30 20:03:52 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target(NULL)
{
	std::cout << PURPLE << ">> PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), _target(target)
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

const char*	PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return PINK MEGA " Grade too high, maximum 1 (to 150)" RESET;
}

const char*	PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return PINK MEGA " Grade too low, minimum 150 (to 1)" RESET;
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

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	
}