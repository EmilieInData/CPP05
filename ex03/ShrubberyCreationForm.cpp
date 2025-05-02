/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/02 17:43:17 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery_42", 145, 137), _target("Default")
{
	std::cout << PURPLE << ">> ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery_42", 145, 137), _target(target)
{
	std::cout << PURPLE << ">> ShrubberyCreationForm target constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other) : AForm(other)
{
	std::cout << PURPLE << ">> ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << PURPLE << ">> ShrubberyCreationForm destructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
	if (this != &other)
		AForm::operator=(other);
	else
		std::cout << ERROR << PINK
				  << "pay attention, you're trying to assign an ShrubberyCreationForm class to itself"
				  << RESET << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::formExecute() const

{
	std::ofstream file ((_target + "_shrubbery").c_str());
	if (!file)
	{
		throw FileError();
		return ;
	}
	file << TREE << std::endl << TREE << std::endl;
	file.close();
	return;
}

std::ostream&	operator<<(std::ostream& o, ShrubberyCreationForm const& b)
{
	std::string tmp;
	
	if (b.getSigned() == true)
		tmp = "signed";
	else
		tmp = "not signed";
	o << BLUE << b.getName() << " ShrubberyCreationForm is " << GREEN << tmp << BLUE
	  << ", it can be signed by a Bureaucrat with grade " << GREEN
	  << b.getGradeSign() << BLUE <<  " and be executed with grade "
	  << GREEN << b.getGradeExecute() << RESET << std::endl;
	return (o);
}
