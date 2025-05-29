#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(Serializer const &other)
{
    *this = other;
}

Serializer& Serializer::operator=(Serializer const &other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer(){}

size_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<size_t>(ptr);
}

Data* Serializer::deserialize(size_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
