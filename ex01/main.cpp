/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:12 by esellier          #+#    #+#             */
/*   Updated: 2025/05/02 16:58:59 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat	a("Jedi", 11);
		Bureaucrat	Indie("Indie", 5);
		//Bureaucrat	Rosie("Rosie", 0);
		
		Form		f;
		Form		f2("42b_2", 10, 10);
		//Form		f3("42a_1", 150, 151);
		  
		Indie.signForm(f);
		a.signForm(f2);
		std::cout << GREEN << "\n" << a << Indie << f << f2 <<"\n";
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
