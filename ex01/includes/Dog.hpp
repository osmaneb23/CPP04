/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:16:54 by obouayed          #+#    #+#             */
/*   Updated: 2025/04/03 16:19:52 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
    private:
        Brain *_brain;

    public:
        Dog();
        Dog(Dog const &src);
        Dog &operator=(const Dog &rhs);
        // Virtual here is not necessary
        virtual ~Dog();
        
        void makeSound() const;
        Brain *getBrain() const;
};

#endif