/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:12 by esellier          #+#    #+#             */
/*   Updated: 2025/05/02 19:03:26 by esellier         ###   ########.fr       */
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
	std::cout << BLUE << *form[0] << ", and his target is " << GREEN << *form[0]._target << *form[1] << *form[2] << std::endl; 
	for (int i = 0; i < 4; i++)
		delete form[i];
	return 0;
}
//faire un getTarget pour voir si ca fonctionne !