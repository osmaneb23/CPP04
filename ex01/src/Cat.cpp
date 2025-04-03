/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 01:23:18 by obouayed          #+#    #+#             */
/*   Updated: 2025/04/03 02:50:21 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	this->_brain = new Brain();	
}

Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		*this->_brain = *rhs._brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << "Miaouuuuu" << std::endl;
}
