/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:12 by esellier          #+#    #+#             */
/*   Updated: 2025/05/02 17:45:38 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	try
	{
		Bureaucrat	a("Jedi", 24);
		Bureaucrat	Indie("Indie", 5);
		//Bureaucrat	Rosie("Rosie", 0);
		
		ShrubberyCreationForm	s("Test1");
		RobotomyRequestForm		r("Test2");
		PresidentialPardonForm	p;
		
		std::cout << "\n" << a << Indie << s << r << p;
		Indie.signForm(s);
		Indie.executeForm(s);
		std::cout << "\n";
		Indie.executeForm(p);
		a.signForm(p);
		a.executeForm(p);
		std::cout << "\n";
		Indie.executeForm(p);
		Indie.signForm(r);
		for(int i = 0; i < 6; i++)
		{
			Indie.executeForm(r);
			std::cout << "\n";
		}
	}	
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\n" << e.what() << "\n" << "\n";
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\n" << e.what() << "\n" << "\n";
	}
	return 0;
}
