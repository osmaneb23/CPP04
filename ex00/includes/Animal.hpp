/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:14:19 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/31 17:14:33 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    public:
        Animal();
        Animal(std::string type);
        Animal(Animal const &src);
        Animal &operator=(const Animal &rhs);
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const = 0;

    protected:
        std::string _type;
};

#endif