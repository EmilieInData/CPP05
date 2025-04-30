/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/04/30 19:42:45 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << PURPLE << ">> Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string value, int i): _name(value)
{
	std::cout << PURPLE << ">> Bureaucrat values constructor called" << RESET << std::endl;
	if (i < 1)
		throw GradeTooHighException();
	else if (i > 150)
		throw GradeTooLowException();
	_grade = i;
}

Bureaucrat::Bureaucrat(Bureaucrat const& other): _name(other._name), _grade(other._grade)
{
	std::cout << PURPLE << ">> Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << PURPLE << ">> Bureaucrat destructor called" << RESET << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::gradeIncrement()
{
	if (_grade < 2)
		throw GradeTooHighException();
	_grade -= 1;
}

void	Bureaucrat::gradeDecrement()
{
	if (_grade > 149)
		throw GradeTooLowException();
	_grade += 1;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
	if (this != &other)
		this->_grade = other._grade;
	else
		std::cout << ERROR << PINK
				  << "pay attention, you're trying to assign an Bureaucrat class to itself"
				  << RESET << std::endl;
	return (*this);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return PINK MEGA " Grade too high, maximum 1 (to 150)" RESET;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return PINK MEGA " Grade too low, minimum 150 (to 1)" RESET;
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& b)
{
	o << BLUE << b.getName() << ", bureaucrat grade "
	  << GREEN << b.getGrade() << RESET << "." << std::endl;
	return (o);
}
