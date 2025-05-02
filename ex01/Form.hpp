/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:57:26 by esellier          #+#    #+#             */
/*   Updated: 2025/05/02 16:57:55 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Common.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string value, int gs, int ge);
		Form(Form const& other);
		~Form();
	
		std::string			getName() const;
		bool				getSigned() const;
		unsigned int		getGradeSign() const;
		unsigned int		getGradeExecute() const;

		void				beSigned(Bureaucrat& b);
		Form& 				operator=(Form const& other);
		
	private:
		std::string			_name;
		bool				_signed;
		const unsigned int	_gradeSign;
		const unsigned int	_gradeExecute;
};

std::ostream&	operator<<(std::ostream& o, Form const& f);

#endif
