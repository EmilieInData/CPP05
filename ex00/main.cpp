/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:12 by esellier          #+#    #+#             */
/*   Updated: 2025/05/05 14:42:33 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b = NULL;
	
	try
	{
		Bureaucrat a("Jedi", 11);
		Bureaucrat Indie("Indie", 2);
		//Bureaucrat Indie("Indie", 5);
		Bureaucrat Tina = Indie;
		Bureaucrat Doudou;
		//Bureaucrat c("Rosie", 154);
		b = new Bureaucrat("Nala", 149);
		
		std::cout << "\n" << a << Indie << Tina << Doudou << *b 
				  << "\n" << RESET;
				  
		b->gradeDecrement();
		Indie.gradeIncrement();
		std::cout << *b << Indie
				  << "\n" << RESET;
				  
		Indie.gradeIncrement();
		std::cout << Indie
				  << "\n" << RESET;
				  
		Bureaucrat c("Rosie", 154);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\n" << e.what() << "\n" << "\n";
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\n" << e.what() << "\n" << "\n";
	}
	delete b;
	return 0;
}
