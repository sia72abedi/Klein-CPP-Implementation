#include <iostream>
#include <vector>
#include "Klein.h"
#include <sstream>
#include <iomanip>

int main() {
    std::vector<uint8_t> key({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00});
    std::vector<uint8_t> plainText({ 0x12, 0x34, 0x56, 0x78, 0x90, 0xab, 0xcd, 0xef});
    Klein klein(KleinType::Klein_64,key);
    std::vector<uint8_t> cipherText = klein.encrypt(plainText);
    for (auto ci:cipherText){
        std::cout<<std::hex<< static_cast<int>(ci)<<"\t";
    }
    return 0;
}
