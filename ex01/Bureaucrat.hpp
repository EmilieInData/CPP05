/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:57:26 by esellier          #+#    #+#             */
/*   Updated: 2025/04/30 19:42:02 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Common.hpp"
#include "Form.hpp"

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string value, int i);
		Bureaucrat(Bureaucrat const& other);
		~Bureaucrat();
	
		std::string			getName() const;
		unsigned int		getGrade() const;
		void				gradeIncrement();
		void				gradeDecrement();
		void				signForm(Form& f);
		Bureaucrat& 		operator=(Bureaucrat const& other);
		
		class	GradeTooHighException : public std::exception
		{
			public:
        		virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
        		virtual const char* what() const throw();
		};
	
	private:
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& b);

#endif
