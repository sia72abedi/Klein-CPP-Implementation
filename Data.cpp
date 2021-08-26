//
// Created by siavash on ۲۰۲۱/۸/۱۴.
//

#include "Data.h"


Data::Data(int size): data(size, 0) {
}

const std::vector<int8_t> &Data::getSt() const {
    return data;
}

void Data::setSt(const std::vector<int8_t> &st) {
    Data::data = st;
}

int8_t &Data::operator[](unsigned int i) {
    return data[i];
}

const Data &Data::operator=(std::vector<int8_t> &that) {
    this->data = that;
    return *this;
}

int8_t Data::getNibble(uint8_t i) {
    uint8_t byteNo = i / 2;
    uint8_t nibbleNo = i % 2;
    auto byteData = data[byteNo];
    if(nibbleNo){//MSB
        return byteData & 0xf0;
    } else{//LSB
        return byteData & 0x0f;
    }
}

void Data::setNibble(uint8_t i, int8_t input) {
    uint8_t byteNo = i / 2;
    uint8_t nibbleNo = i % 2;
    auto &byteData = data[byteNo];
    if(nibbleNo){//MSB
        input &= 0xf0;
        byteData &= 0x0f;
        byteData |= input;
    } else{//LSB
        input &= 0x0f;
        byteData & 0xf0;
        byteData |= input;
    }
}

Data::Data(const std::vector<int8_t> &data) : data(data) {
}
