/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/04/29 16:12:27 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Exception.hpp"

Exception::Exception(const std::string& value) : _message(value)
{
	std::cout << BLUE << ">> Exception default constructor called" << RESET << std::endl;
}

Exception::~Exception()
{
	std::cout << BLUE << ">> Exception default destructor called" << RESET << std::endl;
}

const char* Exception::what() const throw()
{
	return _message.c_str();
}
