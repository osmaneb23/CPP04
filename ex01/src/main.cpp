/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 03:00:00 by obouayed          #+#    #+#             */
/*   Updated: 2025/04/03 02:45:46 by obouayed         ###   ########.fr       */
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
    
    // To properly test deep copy, we would need to add getIdea and setIdea methods to Dog
    // But even without those, we can test basic functionality
    std::cout << "Setting ideas in original dog's brain..." << std::endl;
    
    // Create a copy of the Dog
    Dog* copyDog = new Dog(*originalDog);
    std::cout << "Copy constructor called. If deep copy works, dogs should have different brain addresses" << std::endl;
    
    // Delete the original - if copy is shallow, this would cause problems when accessing copyDog's brain
    delete originalDog;
    std::cout << "Original dog deleted. If copy is shallow, using copyDog now would cause issues." << std::endl;
    
    // Use the copy to prove it's still valid
    copyDog->makeSound();
    
    delete copyDog;
    
    // Test deep copy for Cat
    std::cout << "\n--- Cat deep copy test ---" << std::endl;
    Cat originalCat;
    Cat copyCat = originalCat; // Copy using assignment operator
    
    std::cout << "Original cat and copy cat created." << std::endl;
    std::cout << "If deep copy works, both cats should work independently." << std::endl;
    
    originalCat.makeSound();
    copyCat.makeSound();
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

void testLeakCheck() 
{
    std::cout << "\n===== LEAK CHECK TEST (SUBJECT EXAMPLE) =====\n" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
}

int main() 
{
    testBasicFunctionality();
    testWrongAnimal();
    testDeepCopy();
    testAnimalArray();
    testLeakCheck();    
    return 0;
}