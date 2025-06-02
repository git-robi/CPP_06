/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:46:09 by rgiambon          #+#    #+#             */
/*   Updated: 2025/06/02 12:46:11 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data* data = new Data;
    data->number = 42;
    data->text = "Hello, World!";

    size_t serialized = Serializer::serialize(data);
    Data* deserialized = Serializer::deserialize(serialized);

  
    std::cout << "Original pointer: " << data << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    std::cout << "Are equal: " << (data == deserialized) << std::endl;


    std::cout << "Number: " << deserialized->number << std::endl;
    std::cout << "Text: " << deserialized->text << std::endl;

    delete data;
    return 0;
}
