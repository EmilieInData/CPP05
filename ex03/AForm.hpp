/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:57:26 by esellier          #+#    #+#             */
/*   Updated: 2025/05/05 13:57:50 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Common.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string value, int gs, int ge);
		AForm(AForm const& other);
		virtual ~AForm();
	
		std::string			getName() const;
		bool				getSigned() const;
		unsigned int		getGradeSign() const;
		unsigned int		getGradeExecute() const;

		void				beSigned(Bureaucrat& b);
		AForm& 				operator=(AForm const& other);
		void				execute(Bureaucrat const & executor) const;

		class	FormNotSigned : public std::exception
		{
			public:
        		virtual const char* what() const throw();
		};
		class	FileError : public std::exception
		{
			public:
        		virtual const char* what() const throw();
		};

	protected:
		virtual void		formExecute() const = 0;

	private:
		std::string			_name;
		bool				_signed;
		const unsigned int	_gradeSign;
		const unsigned int	_gradeExecute;
};

std::ostream&	operator<<(std::ostream& o, AForm const& f);

#endif
