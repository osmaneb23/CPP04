/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 03:00:00 by obouayed          #+#    #+#             */
/*   Updated: 2025/04/07 17:59:21 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"


void testBasicFunctionality() 
{
    std::cout << "\n===== BASIC FUNCTIONALITY TEST =====\n" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();
    
    delete meta;
    delete dog;
    delete cat;
}

void testWrongAnimal() 
{
    std::cout << "\n===== WRONG ANIMAL TEST =====\n" << std::endl;
    
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    
    wrongCat->makeSound();
    wrongAnimal->makeSound();
    
    delete wrongAnimal;
    delete wrongCat;
}

void testDeepCopy() 
{
    std::cout << "\n===== DEEP COPY TEST =====\n" << std::endl;
    
    // Test deep copy for Dog
    std::cout << "--- Dog deep copy test ---" << std::endl;
    Dog* originalDog = new Dog();
    
    // Set some ideas in the original dog
    originalDog->getBrain()->setIdea(0, "I want to chase cats");
    originalDog->getBrain()->setIdea(1, "I need to bark at mailman");
    originalDog->getBrain()->setIdea(2, "Squirrels are suspicious");
    
    std::cout << "Original dog ideas:" << std::endl;
    std::cout << "Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;
    std::cout << "Brain address: " << originalDog->getBrain() << std::endl;
    
    // Create a copy using copy constructor
    Dog* copyDog = new Dog(*originalDog);
    
    std::cout << "\nCopy dog after creation:" << std::endl;
    std::cout << "Idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << copyDog->getBrain()->getIdea(1) << std::endl;
    std::cout << "Brain address: " << copyDog->getBrain() << std::endl;
    
    // Modify original dog's idea
    originalDog->getBrain()->setIdea(1, "I should dig a hole in the garden");
    
    std::cout << "\nAfter modifying original dog's idea:" << std::endl;
    std::cout << "Original dog idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;
    std::cout << "Copy dog idea 1: " << copyDog->getBrain()->getIdea(1) << std::endl;
    
    // Clean up
    delete originalDog;
    std::cout << "\nOriginal dog deleted. Copy should still work if deep copy was successful." << std::endl;
    
    // Verify copy dog still works
    std::cout << "Copy dog ideas after original deletion:" << std::endl;
    std::cout << "Idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << copyDog->getBrain()->getIdea(1) << std::endl;
    
    delete copyDog;
    
    // Test deep copy for Cat with assignment operator
    std::cout << "\n--- Cat deep copy test ---" << std::endl;
    Cat originalCat;
    
    // Set some ideas in the original cat
    originalCat.getBrain()->setIdea(0, "I should knock things off the table");
    originalCat.getBrain()->setIdea(1, "Humans exist to serve me");
    
    std::cout << "Original cat brain address: " << originalCat.getBrain() << std::endl;
    
    // Create a copy using assignment operator
    Cat copyCat = originalCat;
    
    std::cout << "Copy cat brain address: " << copyCat.getBrain() << std::endl;
    std::cout << "If deep copy worked, addresses should be different" << std::endl;
    
    // Modify copy cat's idea
    copyCat.getBrain()->setIdea(1, "I should demand more food");
    
    std::cout << "\nAfter modifying copy cat's idea:" << std::endl;
    std::cout << "Original cat idea 1: " << originalCat.getBrain()->getIdea(1) << std::endl;
    std::cout << "Copy cat idea 1: " << copyCat.getBrain()->getIdea(1) << std::endl;
}

void testAnimalArray() 
{
    std::cout << "\n===== ANIMAL ARRAY TEST =====\n" << std::endl;
    
    const int arraySize = 10;
    Animal* animals[arraySize];
    
    std::cout << "Creating an array with " << arraySize << " animals (half Dogs, half Cats)..." << std::endl;
    for (int i = 0; i < arraySize; i++) 
    {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\nMaking all animals sound..." << std::endl;
    for (int i = 0; i < arraySize; i++) 
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\nDeleting all animals..." << std::endl;
    for (int i = 0; i < arraySize; i++)
        delete animals[i];
}

int main() 
{
    testBasicFunctionality();
    testWrongAnimal();
    testDeepCopy();
    testAnimalArray();
    return 0;
}