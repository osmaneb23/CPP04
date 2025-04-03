/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:16:13 by obouayed          #+#    #+#             */
/*   Updated: 2025/04/03 16:19:42 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal
{
    private:
        Brain *_brain;
        
    public:
        Cat();
        Cat(Cat const &src);
        Cat &operator=(const Cat &rhs);
        // Virtual here is not necessary
        virtual ~Cat();
        
        void makeSound() const;
        Brain *getBrain() const;
};

#endif