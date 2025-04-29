/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:57:26 by esellier          #+#    #+#             */
/*   Updated: 2025/04/29 18:48:51 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Common.hpp"

class Form
{
	public:
		Form();
		Form(std::string value, int gs, int ge);
		Form(Form const& other);
		~Form();
	
		std::string		getName() const;
		bool			getSigned() const;
		const int		getGradeSign() const;
		const int		getGradeExecute() const;

		void			gradeIncrement();
		void			gradeDecrement();
		Form& 			operator=(Form const& other);
		
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
		std::string		_name;
		bool			_signed;
		const int		_gradeSign;
		const int		_gradeExecute;
};

std::ostream&	operator<<(std::ostream& o, Form const& f);

#endif
