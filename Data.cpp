//
// Created by siavash on ۲۰۲۱/۸/۱۴.
//

#include "Data.h"

constexpr uint8_t Data::sbox[16];

Data::Data(int size): data(size, 0) {
}

const std::vector<uint8_t> &Data::getSt() const {
    return data;
}

void Data::setSt(const std::vector<uint8_t> &st) {
    Data::data = st;
}

uint8_t &Data::operator[](unsigned int i) {
    return data[i];
}

const Data &Data::operator=(std::vector<uint8_t> &that) {
    this->data = that;
    return *this;
}

uint8_t Data::getNibble(uint8_t i) {
    uint8_t byteNo = i / 2;
    uint8_t nibbleNo = i % 2;
    auto byteData = data[byteNo];
    if(nibbleNo){//MSB
        return (byteData & 0xf0) >> 4;
    } else{//LSB
        return byteData & 0x0f;
    }
}

void Data::setNibble(uint8_t i, uint8_t input) {
    uint8_t byteNo = i / 2;
    uint8_t nibbleNo = i % 2;
    auto &byteData = data[byteNo];
    if(nibbleNo){//MSB
        input = (input & 0x0f)<<4;
        byteData &= 0x0f;
        byteData |= input;
    } else{//LSB
        input &= 0x0f;
        byteData &= 0xf0;
        byteData |= input;
    }
}

Data::Data(const std::vector<uint8_t> &data) : data(data) {
}
