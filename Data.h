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

    Data(const std::vector<uint8_t> &data);

    const std::vector<uint8_t> &getSt() const;
    void setSt(const std::vector<uint8_t> &st);
    uint8_t &operator[](unsigned int i);
    const Data &operator=(std::vector<uint8_t> &that);
    uint8_t getNibble(uint8_t i);
    void setNibble(uint8_t i, uint8_t input);
protected:
    constexpr static uint8_t sbox[16]={0x07,0x04,0x0A,0x09,0x01,0x0F,0x0B,0x00,0x0C,0x03,0x02,0x06,0x08,0x0E,0x0D,0x05};
    std::vector<uint8_t> data;

};


#endif //CPPKLEIN_DATA_H
