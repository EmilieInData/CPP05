/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/04/30 16:02:50 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << PURPLE << ">> AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string value, int gs, int ge): _name(value), _signed(false), _gradeSign(gs), _gradeExecute(ge)
{
	std::cout << PURPLE << ">> AForm values constructor called" << RESET << std::endl;
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	else if (gs > 150 || ge > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const& other) : _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	*this = other;
	std::cout << PURPLE << ">> AForm copy constructor called" << RESET << std::endl;
}

AForm::~AForm()
{
	std::cout << PURPLE << ">> AForm destructor called" << RESET << std::endl;
}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return _signed;
}

unsigned int	AForm::getGradeSign() const
{
	return _gradeSign;
}

unsigned int	AForm::getGradeExecute() const
{
	return _gradeExecute;
}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
	return;
}

AForm& AForm::operator=(AForm const& other)
{
	if (this != &other)
	{	
		this->_name	= other._name;
		this->_signed = other._signed;
	}
	else
		std::cout << ERROR << PINK
				  << "pay attention, you're trying to assign an AForm class to itself"
				  << RESET << std::endl;
	return (*this);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return PINK MEGA " Grade too high, maximum 1 (to 150)" RESET;
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return PINK MEGA " Grade too low, minimum 150 (to 1)" RESET;
}

std::ostream&	operator<<(std::ostream& o, AForm const& b)
{
	std::string tmp;
	
	if (b.getSigned() == true)
		tmp = "signed";
	else
		tmp = "not signed";
	o << BLUE << b.getName() << " Aform is " << GREEN << tmp << BLUE
	  << ", it can be signed by a Bureaucrat with grade " << GREEN
	  << b.getGradeSign() << BLUE <<  " and be executed with grade "
	  << GREEN << b.getGradeExecute() << RESET << std::endl;
	return (o);
}
