#include <string> 
#include <iostream> 
#include <cassert>
#include <vector>
#include <algorithm>
#include <random>
#include <utility>
#include <chrono>
#include <map>

// TODO: Your implementation goes here
std::string encrypt(std::string message, std::map<int,int> key);
std::string decrypt(std::string cypher, std::map<int,int> key);
std::map<int,int> generateKey(std::string message);

int main(int argc, char** argv) {
    // Feel free change below code if needed.
    std::string message;
    if(argc > 1) message = argv[1];
    else{
        std::cout<<"Empty input\n";
        return 0;
    }
    auto key = generateKey(message);
    auto cypher = encrypt(message, key);
    auto result = decrypt(cypher, key);

    std::cout << "Message: " << message << '\n';
    std::cout << "Cypher: " << cypher << '\n';
    std::cout << "Result: " << result << '\n';

    assert(message == result);
    return 0;
}

std::string encrypt(std::string message, std::map<int,int> key){
    std::string cypher;
    for(auto m : message){
        cypher.push_back((char)key[m]);
    }
    return cypher;
}

std::string decrypt(std::string cypher, std::map<int,int> key){
    std::string message;
    std::map<int,int> invertKey;
    for(auto k : key){
        invertKey.insert(std::make_pair(k.second, k.first));    
    }
    key.swap(key);
    for(auto c : cypher){
        message.push_back((char)invertKey[c]);
    }
    return message;
}

std::map<int,int> generateKey(std::string message){
    int index = 0;
    std::pair<int, int> x;
    std::map<int,int> key;
    std::vector<int> usedAsciiCodes(message.begin(), message.end());
    std::sort(usedAsciiCodes.begin(), usedAsciiCodes.end());
    usedAsciiCodes.erase(std::unique(usedAsciiCodes.begin(), usedAsciiCodes.end()), usedAsciiCodes.end());
    std::vector<int> shuffledAsciiCodes = {
        33,34,35,36,37,38,39,40,41,42,43,
        44,45,46,47,48,49,50,51,52,53,54,
        55,56,57,58,59,60,61,62,63,64,65,
        66,67,68,69,70,71,72,73,74,75,76,
        77,78,79,80,81,82,83,84,85,86,87,
        88,89,90,91,92,93,94,95,96,97,98,
        99,100,101,102,103,104,105,106,107,
        108,109,110,111,112,113,114,115,
        116,117,118,119,120,121,122,123,124,125};
    auto base = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(shuffledAsciiCodes.begin(), shuffledAsciiCodes.end(), std::default_random_engine(base));
    for(auto code : usedAsciiCodes){
        key.insert(std::make_pair(code, shuffledAsciiCodes[index++]));
    }
    return key;
}