/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/04/29 18:58:08 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << PURPLE << ">> Form default constructor called" << RESET << std::endl;
}

Form::Form(std::string value, int gs, int ge): _name(value), _signed(false), _gradeSign(gs), _gradeExecute(ge)
{
	std::cout << PURPLE << ">> Form values constructor called" << RESET << std::endl;
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	else if (gs > 150 || ge > 150)
		throw GradeTooLowException();
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

const int	Form::getGradeSign() const
{
	return _gradeSign;
}

const int	Form::getGradeExecute() const
{
	return _gradeExecute;
}

// void	Form::gradeIncrement()
// {
// 	if (_grade < 2)
// 		throw GradeTooHighException();
// 	_grade -= 1;
// }

// void	Form::gradeDecrement()
// {
// 	if (_grade > 149)
// 		throw GradeTooLowException();
// 	_grade += 1;
// }

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

const char*	Form::GradeTooHighException::what() const throw()
{
	return PINK MEGA " Grade too high, maximum 1 (to 150)" RESET;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return PINK MEGA " Grade too low, minimum 150 (to 1)" RESET;
}

std::ostream&	operator<<(std::ostream& o, Form const& b)
{
	o << BLUE << b.getName() << ", Form grade "
	  << GREEN << b.getGrade() << RESET << "." << std::endl;
	return (o);
}
