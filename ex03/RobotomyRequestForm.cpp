/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/02 17:29:04 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy_r2d42", 72, 45), _target("Default")
{
	std::cout << PURPLE << ">> RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy_r2d42", 72, 45), _target(target)
{
	std::cout << PURPLE << ">> RobotomyRequestForm target constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other) : AForm(other)
{
	std::cout << PURPLE << ">> RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << PURPLE << ">> RobotomyRequestForm destructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
	if (this != &other)
		AForm::operator=(other);
	else
		std::cout << ERROR << PINK
				  << "pay attention, you're trying to assign an RobotomyRequestForm class to itself"
				  << RESET << std::endl;
	return (*this);
}

void	RobotomyRequestForm::formExecute() const

{
	static int	flag = 0;
	std::cout << ROBOT << BLUE " BZZZZzzz BBBBZzzzZZz zzzzz.."
			  << RESET << "\n";
	if (flag % 2 == 0)
	{
		std::cout << MEGA << " " << GREEN << _target << BLUE
				  << " has been robotomized successfully!"
			 	  << RESET << "\n";
	}
	else
	{
		std::cout << MEGA << " " << BLUE << "Robotomy failed for "
				  << GREEN << _target << RESET << "\n";
	}		  
	flag++;
	return;
}

std::ostream&	operator<<(std::ostream& o, RobotomyRequestForm const& b)
{
	std::string tmp;
	
	if (b.getSigned() == true)
		tmp = "signed";
	else
		tmp = "not signed";
	o << BLUE << b.getName() << " RobotomyRequestForm is " << GREEN << tmp << BLUE
	  << ", it can be signed by a Bureaucrat with grade " << GREEN
	  << b.getGradeSign() << BLUE <<  " and be executed with grade "
	  << GREEN << b.getGradeExecute() << RESET << std::endl;
	return (o);
}
