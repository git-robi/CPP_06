/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:44:46 by rgiambon          #+#    #+#             */
/*   Updated: 2025/06/02 12:44:48 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isInt(std::string const value)
{
    char* endptr;
    const char* str = value.c_str();
    long val = strtol(str, &endptr, 10);
    
    if (*endptr != '\0' || endptr == str)
        return false;
    
    return (val >= INT_MIN && val <= INT_MAX);
}

bool ScalarConverter::isChar(std::string const value)
{
    if (value.length() == 1 && !std::isdigit(value[0]))
        return true;
    if (value.length() == 3 && value[0] == '\'' && value[2] == '\'' )
        return true;
    return false;
}

bool ScalarConverter::isPseudoLiteral(std::string const value)
{
    if (value == "-inff" || value == "+inff" || value == "-inff" || value == "nanf" || value == "-inf" || value == "+inf" || value == "nan")
        return true;
    return false;
}

bool ScalarConverter::isFloat(std::string const value)
{
    if (value[value.length() - 1] != 'f')
        return false;
        
    char* endptr;
    const char* str = value.c_str();
    strtof(str, &endptr);
    
    return (*endptr == 'f' && endptr == str + value.length() - 1);
}

bool ScalarConverter::isDouble(std::string const value)
{
    char* endptr;
    const char* str = value.c_str();
    strtod(str, &endptr);
    
    return (*endptr == '\0');
}

int ScalarConverter::GetType(std::string const value)
{
    if (isPseudoLiteral(value))
        return PSEUDOLITERAL;
    else if (isFloat(value))
        return FLOAT;
    else if (isDouble(value))
        return DOUBLE;
    else if (isInt(value))
        return INT;
    else if (isChar(value))
        return CHAR;
    return 0; 
}

void ScalarConverter::printChar(double d)
{
    if (d < 0 || d > 127 || std::isnan(d))
        std::cout << "char: impossible" << std::endl;
    else if (d < 32 || d == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

void ScalarConverter::printInt(double d)
{
    if (d > INT_MAX || d < INT_MIN || std::isnan(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void ScalarConverter::printFloat(double d)
{
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::handlePseudoLiteral(std::string const value)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (value == "nan" || value == "-inf" || value == "+inf")
    {
        std::cout << "float: " << value << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
    }
    else // nanf, -inff, +inff
    {
        std::cout << "float: " << value << std::endl;
        std::cout << "double: " << value.substr(0, value.length()-1) << std::endl;
    }
}

double ScalarConverter::convertToDouble(std::string const value, int type)
{
    const char* str = value.c_str();
    char* endptr;
    
    switch(type)
    {
        case CHAR:
            return static_cast<double>(value[0]);
        case INT:
            return static_cast<double>(strtol(str, &endptr, 10));
        case FLOAT:
            return static_cast<double>(strtof(str, &endptr));
        case DOUBLE:
            return strtod(str, &endptr);
        default:
            throw std::invalid_argument("Invalid type");
    }
}

void ScalarConverter::convert(std::string const value)
{
    try {
        int type = GetType(value);
        
        if (type == PSEUDOLITERAL)
        {
            handlePseudoLiteral(value);
            return;
        }

        double d = convertToDouble(value, type);
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
    }
    catch (const std::exception& e)
    {
        std::cout << "Conversion error: " << e.what() << std::endl;
    }
}
