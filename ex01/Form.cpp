/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/02 16:58:30 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << PURPLE << ">> Form default constructor called" << RESET << std::endl;
}

Form::Form(std::string value, int gs, int ge): _name(value), _signed(false), _gradeSign(gs), _gradeExecute(ge)
{
	std::cout << PURPLE << ">> Form values constructor called" << RESET << std::endl;
	if (gs < 1 || ge < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gs > 150 || ge > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(Form const& other) : _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	*this = other;
	std::cout << PURPLE << ">> Form copy constructor called" << RESET << std::endl;
}

Form::~Form()
{
	std::cout << PURPLE << ">> Form destructor called" << RESET << std::endl;
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return _signed;
}

unsigned int	Form::getGradeSign() const
{
	return _gradeSign;
}

unsigned int	Form::getGradeExecute() const
{
	return _gradeExecute;
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
	return;
}

Form& Form::operator=(Form const& other)
{
	if (this != &other)
	{	
		this->_name	= other._name;
		this->_signed = other._signed;
	}
	else
		std::cout << ERROR << PINK
				  << "pay attention, you're trying to assign an Form class to itself"
				  << RESET << std::endl;
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, Form const& b)
{
	std::string tmp;
	
	if (b.getSigned() == true)
		tmp = "signed";
	else
		tmp = "not signed";
	o << BLUE << b.getName() << " form is " << GREEN << tmp << BLUE
	  << ", it can be signed by a Bureaucrat with grade " << GREEN
	  << b.getGradeSign() << BLUE <<  " and be executed with grade "
	  << GREEN << b.getGradeExecute() << RESET << std::endl;
	return (o);
}
