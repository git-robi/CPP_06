#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <climits>

#define INVALID 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define PSEUDOLITERAL 5

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter &operator=(ScalarConverter const &other);
        ~ScalarConverter();

        // Helper methods for conversion
        static void printChar(double d);
        static void printInt(double d);
        static void printFloat(double d);
        static void printDouble(double d);
        static void handlePseudoLiteral(std::string const value);
        static double convertToDouble(std::string const value, int type);

    public:
        static void convert(std::string const value);
        static int GetType(std::string const value);
        static bool isChar(std::string const value);
        static bool isInt(std::string const value);
        static bool isFloat(std::string const value);
        static bool isDouble(std::string const value);
        static bool isPseudoLiteral(std::string const value);
};