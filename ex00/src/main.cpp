/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:18:33 by obouayed          #+#    #+#             */
/*   Updated: 2025/04/03 01:57:24 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    std::cout << "\n===== TESTING ANIMAL CLASS =====\n" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "\n--- Type Tests ---" << std::endl;
    std::cout << "Animal type: " << meta->getType() << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    std::cout << "\n--- Sound Tests ---" << std::endl;
    std::cout << "Animal sound: ";
    meta->makeSound();
    std::cout << "Dog sound: ";
    dog->makeSound();
    std::cout << "Cat sound: ";
    cat->makeSound();
    
    std::cout << "\n===== TESTING WRONG ANIMAL CLASS =====\n" << std::endl;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "\n--- Wrong Type Tests ---" << std::endl;
    std::cout << "WrongAnimal type: " << wrongMeta->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    
    std::cout << "\n--- Wrong Sound Tests ---" << std::endl;
    std::cout << "WrongAnimal sound: ";
    wrongMeta->makeSound();
    
    std::cout << "WrongCat sound: ";
    wrongCat->makeSound();
    
    std::cout << "\n===== TESTING COPY AND ASSIGNMENT =====\n" << std::endl;
    
    std::cout << "--- Testing Cat Copy ---" << std::endl;
    Cat originalCat;
    Cat copiedCat(originalCat);
    std::cout << "Original Cat type: " << originalCat.getType() << std::endl;
    std::cout << "Copied Cat type: " << copiedCat.getType() << std::endl;
    std::cout << "Original Cat sound: ";
    originalCat.makeSound();
    std::cout << "Copied Cat sound: ";
    copiedCat.makeSound();
    
    std::cout << "\n--- Testing Dog Assignment ---" << std::endl;
    Dog originalDog;
    Dog assignedDog;
    assignedDog = originalDog;
    std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
    std::cout << "Assigned Dog type: " << assignedDog.getType() << std::endl;
    std::cout << "Original Dog sound: ";
    originalDog.makeSound();
    std::cout << "Assigned Dog sound: ";
    assignedDog.makeSound();
    
    std::cout << "\n===== CLEANUP =====\n" << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete wrongMeta;
    delete wrongCat;
    
    return 0;
}