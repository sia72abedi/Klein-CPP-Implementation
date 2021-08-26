//
// Created by siavash on ۲۰۲۱/۸/۱۴.
//

#ifndef CPPKLEIN_DATA_H
#define CPPKLEIN_DATA_H

#include <vector>
#include <cstdint>

class Data {
public:
    Data(int size);

    Data(const std::vector<int8_t> &data);

    const std::vector<int8_t> &getSt() const;
    void setSt(const std::vector<int8_t> &st);
    int8_t &operator[](unsigned int i);
    const Data &operator=(std::vector<int8_t> &that);
    int8_t getNibble(uint8_t i);
    void setNibble(uint8_t i, int8_t input);
protected:
    const uint8_t sbox[16]={0x7,0x4,0xA,0x9,0x1,0xF,0xB,0x0,0xC,0x3,0x2,0x6,0x8,0xE,0xD,0x5};
    std::vector<int8_t> data;

};


#endif //CPPKLEIN_DATA_H
