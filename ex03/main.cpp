/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:12 by esellier          #+#    #+#             */
/*   Updated: 2025/05/05 14:07:28 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
	AForm* form[4] = {NULL, NULL, NULL, NULL};
	Bureaucrat Indie("Indie", 1);

	try
	{
		Intern I007;
		
		form[0] = I007.makeForm("Shrubbery Creation", "Indie");
		form[1] = I007.makeForm("robotomy request", "Jedi");
		form[2] = I007.makeForm("PRESIDENTIAL PARDON", "Rosie");
		form[3] = I007.makeForm("trying something WRONG", "Bender");
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\n" << e.what() << "\n" << "\n";
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\n" << e.what() << "\n" << "\n";
	}
	std::cout << "\n" << BLUE << *form[0] << *form[1] << *form[2];
	Indie.signForm(*form[0]);
	Indie.signForm(*form[1]);
	Indie.signForm(*form[2]);
	std::cout << "\n";
	Indie.executeForm(*form[0]);
	std::cout << "\n";
	Indie.executeForm(*form[1]);
	std::cout << "\n";
	Indie.executeForm(*form[2]);
	std::cout << "\n";
	for (int i = 0; i < 4; i++)
		delete form[i];
	return 0;
}
