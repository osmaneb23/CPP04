/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:14:19 by obouayed          #+#    #+#             */
/*   Updated: 2025/04/03 01:42:36 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(Animal const &src);
        Animal &operator=(const Animal &rhs);
        // Adding virtual make all the derived classes destructors virtual by default
        virtual ~Animal();
        
        std::string getType() const;
        virtual void makeSound() const;
};

#endif