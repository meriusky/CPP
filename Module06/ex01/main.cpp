#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.number = 42;
    data.text = "Hello Serializer";

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Data.number: " << data.number << ", Data.text: " << data.text << std::endl;

    // Serialize
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    // Deserialize
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << ptr << std::endl;
    std::cout << "Data.number: " << ptr->number << ", Data.text: " << ptr->text << std::endl;

    // Check equality
    if (ptr == &data)
        std::cout << "✅ Success: Deserialized pointer matches original!" << std::endl;
    else
        std::cout << "❌ Error: Pointers don’t match!" << std::endl;

    return 0;
}

