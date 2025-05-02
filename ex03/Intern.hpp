/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:57:26 by esellier          #+#    #+#             */
/*   Updated: 2025/05/02 18:04:43 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Common.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(Intern const& other);
		~Intern();
	
		Intern& operator=(Intern const& other);
		AForm*	makeForm(std::string formName, std::string FormTarget);
};

#endif
