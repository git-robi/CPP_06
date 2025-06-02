/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:47:50 by rgiambon          #+#    #+#             */
/*   Updated: 2025/06/02 12:47:52 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib> 
#include <ctime>
#include <iostream>

Base* generate()
{
    int random = rand() % 3;

    switch(random)
    {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return 0;
}

void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);  // Try to cast to A
        std::cout << "A" << std::endl;
        return;
    } 
    catch(const std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } 
    catch(const std::bad_cast&) {}  

    try 
    {
        (void)dynamic_cast<C&>(p);  
        std::cout << "C" << std::endl;
    } 
    catch(const std::bad_cast&) {}
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

int main()
{
    srand(time(NULL));

    std::cout << "=== Testing generate() and identify() functions ===\n" << std::endl;
    
    // Test multiple random generations
    int i;
    for (i = 0; i < 5; ++i) {
        std::cout << "Test " << i + 1 << ": " << std::endl;
        Base* ptr = generate();
        
        std::cout << "Pointer identification: ";
        identify(ptr);
        
        std::cout << "Reference identification: ";
        identify(*ptr);
        
        std::cout << std::endl;
        delete ptr;
    }

    // Test with explicit instances
    std::cout << "\n=== Testing with explicit instances ===\n" << std::endl;
    
    A a;
    B b;
    C c;

    std::cout << "Testing A:" << std::endl;
    identify(&a);
    identify(a);

    std::cout << "\nTesting B:" << std::endl;
    identify(&b);
    identify(b);

    std::cout << "\nTesting C:" << std::endl;
    identify(&c);
    identify(c);

    // Test with NULL pointer
    std::cout << "\n=== Testing with NULL pointer ===\n" << std::endl;
    identify(static_cast<Base*>(0));

    return 0;
}
