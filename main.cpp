#include <string> 
#include <iostream> 
#include <cassert>

// TODO: Your implementation goes here

int main() {
    // Feel free change below code if needed.

    std::string message = "Hello, Coders School!";
    auto key = generateKey();
    auto cypher = encrypt(message, key);
    auto result = decrypt(cypher, key);

    std::cout << "Message: " << message << '\n';
    std::cout << "Cypher: " << cypher << '\n';
    std::cout << "Result: " << result << '\n';

    assert(message == result);
    return 0;
}