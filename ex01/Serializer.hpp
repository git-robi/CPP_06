#pragma once

#include "Data.hpp"

class Serializer
{ 
    private:
        Serializer();
        Serializer(Serializer const &other);
        Serializer &operator=(Serializer const &other);
        ~Serializer();
    
    public:
        static size_t serialize(Data* ptr);
        static Data* deserialize(size_t raw);

};
